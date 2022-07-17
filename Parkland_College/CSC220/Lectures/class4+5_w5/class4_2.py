#220 iterables

def retList():
    return ['a', 'train',  5, 'bus', 'car']

alist = ["a", 2, 5, "bus"]

for item in alist:
    print("Item is {}".format(item))

for item in retList():
    print("Item is {}".format(item))

# Generator(it's iterable)

# our own function that's iteratable
def fib(n):
    count = 0
    previous = 1
    yield previous
    count += 1
    current = 1
    yield current
    while (count != n):
        count += 1
        current, previous = current + previous, current
        yield current





