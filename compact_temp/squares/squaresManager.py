from squareImg import *
from point import *
import cv2

class Squares():

    def __init__(self):
        self.squares = []   # liste de carre par frame
        #self.box = box
        #self.addSquare(box[0], box[1], box[2], box[3])

    def addSquare(self, p1, p2, p3, p4):
        newSquare = SquareImg(Point(p1[0], p1[1]), Point(p2[0], p2[1]), Point(p3[0], p3[1]), Point(p4[0], p4[1]))
        self.squares.append(newSquare)

    def getArea(self, _square):
        return _square.area

    def sortBySize(self):
        self.squares = sorted(self.squares, key=self.getArea)

    def trace(self, img, _minLength=0):
        for square in self.squares:
            if square.area > _minLength:
                cv2.line(img, (square.p1.x, square.p1.y), (square.p2.x,square.p2.y), (0,0,255))
                cv2.line(img, (square.p3.x, square.p3.y), (square.p2.x,square.p2.y), (0,0,255))
                cv2.line(img, (square.p3.x, square.p3.y), (square.p4.x,square.p4.y), (0,0,255))
                cv2.line(img, (square.p4.x, square.p4.y), (square.p1.x,square.p1.y), (0,0,255))

    def sortByPersistence(self):
        self.box = [self.squares]  # liste de liste de carre par frame
        self.squares.old = True

    def wipe(self, _pers=False):
        self.squares=[]