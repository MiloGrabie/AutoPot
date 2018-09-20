import math

class SquareImg():

    def __init__(self, p1, p2, p3, p4):
        self.p1 = p1
        self.p2 = p2
        self.p3 = p3
        self.p4 = p4
        self.attr()

    def attr(self):
        self.diagLength = self.getDiagLength()
        self.width = self.getWidth()
        self.height = self.getHeight()
        self.area = self.getArea()
        self.angle = self.getAngle()

    def getAngle(self): # angle between p1 and p2
        if self.p1.x == self.p2.x:
            angle = float(90.0)
        else:
            tan = (float(-self.p1.y + self.p2.y)) / (self.p1.x - self.p2.x)
            angleEnRadian = math.atan(tan)
            angle = math.degrees(angleEnRadian)
        return angle

    def getDiagLength(self):
        return math.sqrt(
            (self.p1.x - self.p3.x) ** 2 + (self.p1.y - self.p3.y) ** 2)

    def getDeltaX(self):
        return (self.p2.x - self.p1.x)

    def getDeltaY(self):
        return (self.p2.y - self.p1.y)

    def centerPoint(self, _square):
        self.centerPoint = [(self.p1.x + self.p2.x)/2,(self.p1.y + self.p2.y)/2]
        return self.centerPoint

    def getLength(self, p1, p2):
        return math.sqrt(
            (p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

    def getWidth(self): # largeur
        return self.getLength(self.p1, self.p2)

    def getHeight(self): # hauteur
        return self.getLength(self.p2, self.p3)

    def getArea(self):
        return self.height*self.width
