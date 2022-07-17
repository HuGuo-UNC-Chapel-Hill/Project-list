class Color:
    def __init__(self):
        self._red = 0
        self._green = 0
        self._blue = 0

    def set_data(self, red, green, blue):
        self._red = red
        self._green = green
        self._blue = blue

    def get_data(self):
        return [self._red, self._green, self._blue]

    def svg(self):
        return str("style=\"fill:rgb({},{},{})\" />".format(self._red, self._green, self._blue))


if __name__ == "__main__":  # unit testing
    test = Color()
    test.set_data(130, 201, 250)
    print(test.get_data())
    print(test.svg())