"""TODO
mettre init cam dans def
main propre (juste nom de fct)
"""

import cv2
import numpy as np
from squares.squaresListsManager import *

cap = cv2.VideoCapture(0)
SqMan = SquareListsManager()

while 1:
    _, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_orange = np.array([0, 50, 80])
    upper_orange = np.array([20, 255, 255])

    lower_blue = np.array([80, 10, 0])
    upper_blue = np.array([130, 60, 60])

    maskOrange = cv2.inRange(hsv, lower_orange, upper_orange)
    maskBlue = cv2.inRange(hsv, lower_blue, upper_blue)

    filterOrange = cv2.bitwise_and(frame, frame, mask=maskOrange)
    filterBlue = cv2.bitwise_and(frame, frame, mask=maskBlue)

    cnts = cv2.findContours(maskOrange.copy(), cv2.RETR_EXTERNAL,
                            cv2.CHAIN_APPROX_SIMPLE)[-2]

    squares = SqMan.addSquares() # create a new list of square

    for c in cnts:
        #c = max(cnts, key=cv2.contourArea)
        rect = cv2.minAreaRect(c)
        box = cv2.boxPoints(rect)
        box = np.int0(box)
        #cv2.drawContours(frame, [box], 0, (0, 0, 255), 2)
        box = box.tolist()
        #square.wipe()
        squares.addSquare(box[0], box[1], box[2], box[3]) # create a new square in the list of squares
        squares.trace(frame)

    SqMan.wipe()
    sqBox = SqMan.getBox()
    sqBox[0].trace(frame)
    try:sqBox[1].trace(frame)
    except:pass

    cv2.imshow('filterOrange', filterOrange)
    cv2.imshow('filterBlue', filterBlue)
    cv2.imshow('hsv', hsv)
    cv2.imshow('frame', frame)

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
cap.release()