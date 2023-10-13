import cv2
import mediapipe as mp
import time


class handDetector():
    def __init__(self, mode=False, maxHands=2, detectionConfidence=0.5, trackConfidence=0.5) -> None:
        self.mode = mode
        self.maxHands = maxHands
        self.detectionConfidence = detectionConfidence
        self.trackConfidence = trackConfidence

        # Creating a hand tracking and detecting model
        self.mpHands = mp.solutions.hands
        self.hands = self.mpHands.Hands(
            self.mode, self.maxHands,1, self.detectionConfidence, self.trackConfidence)

        # Module that contains methods place edges on the patterns
        self.mpDraw = mp.solutions.drawing_utils

    def detectHands(self, img, draw=True):
        # Converting into RGB image object
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

        # The output processed by the model
        self.results = self.hands.process(imgRGB)

        # Assigning dots and edges for the patterns
        dots = self.mpDraw.DrawingSpec()
        dots.color = (0, 0, 0)

        edge = self.mpDraw.DrawingSpec()
        edge.color = (0, 0, 255)  # Red color (BGR-format)

        if self.results.multi_hand_landmarks:
            for handLMS in self.results.multi_hand_landmarks:
                if draw:
                    # Printing landmarks
                    self.mpDraw.draw_landmarks(
                        img, handLMS, self.mpHands.HAND_CONNECTIONS, dots, edge)
        return img
    
    def findPosition(self,img,handNo=0,draw=True):
        lmList=[]

        if self.results.multi_hand_landmarks:
            myHand=self.results.multi_hand_landmarks[handNo]
            for id,lm in enumerate(myHand.landmark):
                # Image Dimensions
                height, width, channel = img.shape
                cx,cy=int(lm.x*width),int(lm.y*height)
                lmList.append([id,cx,cy])

                if draw:
                    for id, lm in enumerate(myHand.landmark):
                        # Printing id's of the dots/landmarks
                        cv2.putText(img, str(id), (int(
                            lm.x*width)+20, int(lm.y*height)), cv2.FONT_HERSHEY_PLAIN, 1, (0, 0, 0), 1)
        
        return lmList


def main():
    # Creating a screen object
    cap = cv2.VideoCapture(0)

    # Hand Detector
    detector=handDetector()

    # variables to calculate frames per second
    currentTime = 0
    previousTime = 0

    # Loop that runs the camera (for every millisec)
    while True:
        # Taking the camera input
        success, img = cap.read()

        # Detecting Patterns
        img=detector.detectHands(img)

        # Tracking points in the hands
        lmList=detector.findPosition(img)

        # Frames per second
        currentTime = time.time()
        fps = 1/(currentTime-previousTime)
        previousTime = currentTime

        # Displaying Frames-P-S
        cv2.putText(img, str(int(fps)), (10, 70),
                    cv2.FONT_HERSHEY_TRIPLEX, 1, (0, 0, 0), 1)

        # Displaying the image
        cv2.imshow("Test Display", img)
        cv2.waitKey(1)
    pass


if __name__ == "__main__":
    main()
