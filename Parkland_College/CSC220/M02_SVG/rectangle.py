from point import Point
from color import Color
import random


class Rectangle:
    def __init__(self, point, width, height, color):
        self._upperleft = point
        self._width = width
        self._height = height
        self._fill = color

    def set_point(self, x, y):
        self._upperleft.set_data(x, y)

    def set_width_height(self, width, height):
        self._width = width
        self._height = height

    def set_color(self, red, green, blue):
        self._fill.set_data(red, green, blue)

    def get_point(self):
        return self._upperleft.get_data()

    def get_width_height(self):
        return [self._width, self._height]

    def get_color(self):
        return self._fill.get_data()

    def make_random(self):
        self.set_point(random.randrange(880), random.randrange(940))
        self.set_width_height(random.randrange(60), random.randrange(120))
        self.set_color(random.randrange(255), random.randrange(255), random.randrange(255))

    def svg(self):
        return str("<rect x=\"{}\" y=\"{}\" width=\"{}\" height=\"{}\" " \
                   .format(*self.get_point() + self.get_width_height())
                   + self._fill.svg())


if __name__ == "__main__":  # unit testing
    point = Point()
    width = 0
    height = 0
    color = Color()
    test = Rectangle(point, width, height, color)
    print(test.svg())
    test.set_point(111, 122)
    test.set_width_height(133, 144)
    test.set_color(155, 166, 177)
    print(test.get_point())
    print(test.get_width_height())
    print(test.get_color())
    test.make_random()
    print(test.svg())
