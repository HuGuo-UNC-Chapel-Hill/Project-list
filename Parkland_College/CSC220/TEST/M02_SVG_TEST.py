#!/usr/local/bin/python3

# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from point import Point
from color import Color
from rectangle import Rectangle

print("Content-type: text/html\n")

Rectanglelist = []

i = 0
while i < 1000:
    test = Rectangle()
    test.setdata()
    Rectanglelist.append(test)
    del test
    i += 1

print('<html><head></head><body>')
print('<svg height="1000" width="1000">')
for rec in Rectanglelist:
    print(rec.SVG())
print('</svg>')
print('</body></html>')