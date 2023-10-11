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

# Loop that runs the camera (for every millisec)
while True:
    # Taking the camera input
    success,img=cap.read()

    # Converting into RGB image object
    imgRGB=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

    # The output processed by the model
    results=hands.process(imgRGB)

    # Prints detect hand landmarks, (i.e. positions on the screen)
    '''
    print(results.multi_hand_landmarks)
    '''

    # Assigning dots and edges for the patterns
    if results.multi_hand_landmarks:
        for handLMS in results.multi_hand_landmarks:
            mpDraw.draw_landmarks(img,handLMS,mpHands.HAND_CONNECTIONS)

    # Displaying the input
    cv2.imshow("Test Display",img)
    cv2.waitKey(1)