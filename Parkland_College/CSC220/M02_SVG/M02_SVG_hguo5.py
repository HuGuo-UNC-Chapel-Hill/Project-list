#!/usr/local/bin/python3

# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from point import Point
from color import Color
from rectangle import Rectangle

print("Content-type: text/html\n")

Rectanglelist = []

for i in range(1000):
    point = Point()
    width = 0
    height = 0
    color = Color()
    test = Rectangle(point, width, height, color)
    test.make_random()
    Rectanglelist.append(test)

print('<html><head></head><body>')
print('<svg height="1000" width="1000">')
for rec in Rectanglelist:
    print(rec.svg())
print('</svg>')
print('</body></html>')