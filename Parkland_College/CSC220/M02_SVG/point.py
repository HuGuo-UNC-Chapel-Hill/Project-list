class Point:
    def __init__(self):
        self._across = 0
        self._down = 0

    def set_data(self, across, down):
        self._across = across
        self._down = down

    def get_data(self):
        return [self._across, self._down]


if __name__ == "__main__":  # unit testing
    test = Point()
    test.set_data(30, 40)
    print(test.get_data())

