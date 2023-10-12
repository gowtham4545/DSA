import cv2
import mediapipe as mp
import time

# Creating a screen object
cap=cv2.VideoCapture(0)

# Creating a hand tracking and detecting model
mpHands=mp.solutions.hands
hands=mpHands.Hands()

# Module that contains methods place edges on the patterns
mpDraw=mp.solutions.drawing_utils

# variables to calculate frames per second
currentTime=0
previousTime=0

# Loop that runs the camera (for every millisec)
while True:
    # Taking the camera input
    success,img=cap.read()

    # Image Dimensions
    height,width,channel=img.shape

    # Converting into RGB image object
    imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

    # The output processed by the model
    results=hands.process(imgRGB)

    # Prints detect hand landmarks, (i.e. positions on the screen)
    '''
    print(results.multi_hand_landmarks)
    '''

    # Assigning dots and edges for the patterns
    dots=mpDraw.DrawingSpec()
    dots.color=(0,0,0)

    edge=mpDraw.DrawingSpec()
    edge.color=(0,0,255)  # Red color 

    if results.multi_hand_landmarks:
        for handLMS in results.multi_hand_landmarks:
            for id,lm in enumerate(handLMS.landmark):
                # Printing id's of the dots/landmarks
                cv2.putText(img,str(id),(int(lm.x*width)+20,int(lm.y*height)),cv2.FONT_HERSHEY_PLAIN,1,(0,0,0),1)
            mpDraw.draw_landmarks(img,handLMS,mpHands.HAND_CONNECTIONS,dots,edge)

    # Frames per second
    currentTime=time.time()
    fps=1/(currentTime-previousTime)
    previousTime=currentTime

    # Displaying Frames-P-S
    cv2.putText(img,str(int(fps)),(10,70),cv2.FONT_HERSHEY_TRIPLEX,1,(0,0,0),1)

    # Displaying the image
    cv2.imshow("Test Display",img)
    cv2.waitKey(1)