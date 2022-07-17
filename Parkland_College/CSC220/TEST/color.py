class Color:
    def __init__(self):
        self._red = 0
        self._green = 0
        self._blue = 0

    def setdata(self, red, green, blue):
        self._red = red
        self._green = green
        self._blue = blue

    def getdata(self):
        return [self._red, self._green, self._blue]

    def SVG(self):
        return str("style=\"fill:rgb({},{},{})\" />".format(self._red, self._green, self._blue))


# unit testing
if __name__ == "__main__":
    test = Color()
    test.setdata(130, 201, 250)
    print(test.getdata())
    print(test.SVG())