import random


def insertion_sort(alist):   # function for insertion-sort
    count = 0  # list visit counter
    for i in range(1, len(alist)):
        count += 1  # counter + 1 for alist[i]
        key = alist[i]
        j = i - 1
        count += 1  # counter + 1 for alist[j] in while statement
        while j >= 0 and key < alist[j]:
            count += 2  # counter +2 for alist[j+1] and alist[j]
            alist[j + 1] = alist[j]
            j -= 1
        count += 1  # counter +1 for alist[j+1]
        alist[j + 1] = key
    f.write("{}, {}".format(len(alist), count))  # output size and counter to csv file
    f.write("\n")  # add newline


f = open("data.csv", "w")  # open csv file and overwrite it

for i in range(1000):  # loop to repeat the insertion sort
    arr = []    # create a new list
    size = random.randrange(1000, 9999)     # create the size of the list
    number = 0
    while number < size:    # loop to add numbers to the list
        arr.append(random.randint(0, 10000))
        number += 1
    insertion_sort(arr)    # sorting
    del size    # delete the size
    del arr     # delete the list

