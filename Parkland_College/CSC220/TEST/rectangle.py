from point import Point
from color import Color
import random


class Rectangle:
    def __init__(self):
        self._upperleft = Point()
        self._width = 0
        self._height = 0
        self._fill = Color()

    def setdata(self):
        self._upperleft.setdata(random.randrange(880), random.randrange(940))
        self._width = random.randrange(60)
        self._height = random.randrange(120)
        self._fill.setdata(random.randrange(255), random.randrange(255), random.randrange(255))

    def getdata(self):
        return self._upperleft.getdata() + [self._width, self._height] + self._fill.getdata()

    def SVG(self):
        return str("<rect x={} y={} width={} height={} " \
                   .format(*self._upperleft.getdata() + [self._width, self._height])
                   + self._fill.SVG())


# unit testing
if __name__ == "__main__":
    test = Rectangle()
    test.setdata()
    print(test.getdata())
    print(test.SVG())
