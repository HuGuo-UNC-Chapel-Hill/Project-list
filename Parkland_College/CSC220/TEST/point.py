class Point:
    def __init__(self):
        self._across = 0
        self._down = 0

    def setdata(self, across, down):
        self._across = across
        self._down = down

    def getdata(self):
        return [self._across, self._down]


# unit testing
if __name__ == "__main__":
    test = Point()
    test.setdata(30, 40)
    print(test.getdata())

