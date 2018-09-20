import numpy as np
import cv2

def squareAcq(frame, color):

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    if color == "orange":
        lower_orange = np.array([0, 50, 80])
        upper_orange = np.array([20, 255, 255])
        maskOrange = cv2.inRange(hsv, lower_orange, upper_orange)
        filterOrange = cv2.bitwise_and(frame, frame, mask=maskOrange)

    elif color == "blue":
        lower_blue = np.array([80, 10, 0])
        upper_blue = np.array([130, 60, 60])
        maskBlue = cv2.inRange(hsv, lower_blue, upper_blue)
        filterBlue = cv2.bitwise_and(frame, frame, mask=maskBlue)

    else:
        #raise print(Color not accepted")
        pass


    cnts = cv2.findContours(maskOrange.copy(), cv2.RETR_EXTERNAL,
                            cv2.CHAIN_APPROX_SIMPLE)[-2]

    for c in cnts:
        rect = cv2.minAreaRect(c)
        box = cv2.boxPoints(rect)
        box = np.int0(box)
        # cv2.drawContours(frame, [box], 0, (0, 0, 255), 2)
        box = box.tolist()
        # square.wipe()
