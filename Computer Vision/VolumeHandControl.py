import cv2
import time
import numpy as np
import HandTracker as htm
import math
from ctypes import cast,POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume


########################################
weightCam, heightCam = 1280, 720
# ######################################

cap = cv2.VideoCapture(0)
cap.set(3, weightCam)
cap.set(4, heightCam)

prevTime = 0

detector = htm.handDetector(detectionConfidence=0.9)

devices=AudioUtilities.GetSpeakers()
interface=devices.Activate(IAudioEndpointVolume._iid_,CLSCTX_ALL,None)
volume=cast(interface,POINTER(IAudioEndpointVolume))
volRange=volume.GetVolumeRange()

minVol=volRange[0]
maxVol=volRange[1]

while True:
    success, img = cap.read()
    img = detector.detectHands(img)
    lmList = detector.findPosition(img, draw=False)

    if (len(lmList) != 0):

        x1, y1 = lmList[4][1], lmList[4][2]
        x2, y2 = lmList[8][1], lmList[8][2]
        cx, cy = (x1+x2)//2, (y1+y2)//2

        cv2.circle(img, (x1, y1), 15, (255, 0, 255), cv2.FILLED)
        cv2.circle(img, (x2, y2), 15, (255, 0, 255), cv2.FILLED)
        cv2.circle(img, (cx, cy), 15, (255, 0, 255), cv2.FILLED)
        cv2.line(img, (x1, y1), (x2, y2), (255, 0, 255), 3)

        length=math.hypot(x2-x1,y2-y1)

        vol=np.interp(length,[30,350],[minVol,maxVol])
        volume.SetMasterVolumeLevel(vol,None)

        if length<30:
            cv2.circle(img,(cx,cy),15,(0,0,255),cv2.FILLED)

    curTime = time.time()
    fps = 1/(curTime-prevTime)
    prevTime = curTime

    cv2.putText(img, f'FPS:{int(fps)}', (40, 70),
                cv2.FONT_HERSHEY_TRIPLEX, 1, (0, 0, 0), 1)
    cv2.imshow('Image', img)
    cv2.waitKey(1)
