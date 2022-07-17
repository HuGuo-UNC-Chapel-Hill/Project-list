string = " var1  :=     7.1"
string1 = string.split(":=")
(var, num)=string.replace(" ", "").split(":=")
print(len(string1))
print(var)
print(num)

Variable_table = {"test": 1}
for (k, v) in Variable_table.items():
    print(k, ":=", v)

    print("<text>Hu Guo</text>")

test ={}
test["t1"] = 33
flo = test["t1"]
test["t2"] = flo
print(test)

string2 = "33.4"
if string2[0].isdigit():
    print("True")


"""
Variable_table = {}
    for i in range(len(wordlist)):
        if wordlist[i][0] == "D":
            for (k, v) in Variable_table.items():
                print(k, " := ", v, "</br>")
        elif wordlist[i][0] == "N":
            print("<text>Hu Guo</text>")
        else:
            (left, right) = wordlist[i].split(":=")
            if right in Variable_table or right.isdigit():
                if left[0] == "v" and right[0].isdigit():
                    Variable_table[left] = float(right)
                if left[0] == "v" and not right[0].isdigit():
                    Variable_table[left] = Variable_table[right]
            else:
                raise NotImplementedError('User defined Runtime Error: {} is not in the dictionary'.format(right))
"""