#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.

# Hu Guo

print("Content-type: text/html\n")


# function to output the rectangle
def rect():
    str1 = '<rect x={} y={} width={} height={} style="fill:rgb({},{},{})" />' \
        .format("750", "20", "220", "120", "0", "0", "153")
    return str1


# function to output the circle
def circle():
    str2 = '<circle cx={} cy={} r={} style="fill:rgb({},{},{});stroke-width:{};' \
           'stroke:rgb({},{},{})"/>' \
          .format("90", "90", "70", "255", "255", "255", 10, "0", "0", "153")
    return str2


# function to output the name
def text():
    str3 = '<text x={} y={} style="fill:rgb({},{},{})" font-size={}>{}</text>' \
          .format("788", "90", "0", "0", "0", "xx-large", "Hu Guo")
    return str3


print('<html><head></head><body>')
print('<svg height="1000" width="1000">')
print(rect())
print(circle())
print(text())
print('</svg>')
print('</body></html>')
