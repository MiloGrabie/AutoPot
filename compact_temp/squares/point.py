# -*- coding: utf-8 -*-

import math

class Point:
    def __init__(self, x, y):
        self.x = int(x)
        self.y = int(y)

    def as_tuple(self):
        return (self.x, self.y)

    def calculateDistance(self, other_point):
        return math.sqrt(
            (self.x - other_point.x) ** 2 + (self.y - other_point.y) ** 2)

    def __str__(self):
        return "Point(%s,%s)" % (self.x, self.y)
