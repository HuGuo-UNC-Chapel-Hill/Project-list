# generator (it's iteratable)
def transport():
    yield "car"
    yield "bus"
    yield "train"
    yield "airplane"


def first_last_faculty():
    yield "Ken", "Urban"
    yield "Derek", "Dallas"
    yield "Dave", "Bock"


for item in transport():
    print(item)

for first, last in first_last_faculty():
    print("{}, {}".format(last, first))

for value in fib(40):
    print(value)