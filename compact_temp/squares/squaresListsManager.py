from squaresManager import *

class SquareListsManager():

    def __init__(self):
        self.box = []

    def addSquares(self):
        newSquares = Squares()
        self.box.append(newSquares)
        print(len(self.box))
        return newSquares

    def wipe(self):
        if len(self.box) > 2:
            del self.box[0]
        else: pass

    def getBox(self):
        return self.box
