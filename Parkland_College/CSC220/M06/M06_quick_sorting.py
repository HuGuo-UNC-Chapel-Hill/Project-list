import random


def inplace_quick_sort(arr, a, b):
    global count

    if a >= b:
        return

    count += 1  # access for arr[b]
    pivot = arr[b]

    left = a
    right = b - 1

    while left <= right:
        while left <= right:
            count += 1  # access for arr[left]
            if arr[left] <= pivot:
                left += 1
            else:
                break

        while left <= right:
            count += 1  # access for arr[right]
            if pivot < arr[right]:
                right -= 1
            else:
                break

        if left <= right:
            count += 4  # access for swap left and right
            arr[left], arr[right] = arr[right], arr[left]
            left, right = left + 1, right - 1

    count += 4  # access for swap left and last
    arr[left], arr[b] = arr[b], arr[left]

    inplace_quick_sort(arr, a, left - 1)
    inplace_quick_sort(arr, left + 1, b)


f = open("data.csv", "w")  # open csv file and overwrite it

for i in range(200):  # loop to repeat the insertion sort
    test = []  # create a new list
    size = random.randrange(10000, 99999)  # create the size of the list
    number = 0
    while number < size:  # loop to add numbers to the list
        test.append(random.randint(0, 10000))
        number += 1
    count = 0
    inplace_quick_sort(test, 0, len(test) - 1)
    f.write("{}, {}".format(len(test), count))  # output size and counter to csv file
    f.write("\n")  # add newline
    del size  # delete the size
    del test  # delete the list
    del count  # delete the counter
