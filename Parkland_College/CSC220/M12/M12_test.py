from sorted_priority_queue import SortedPriorityQueue



str1 = "sdada dade# ."
str2 = "XYVWTWVXTWYVXTTTTTTTWVWXVUUUUUUZVYZ"
arr=list(str1)
arr=sorted(arr)
print(arr)

string = "ABBCCDDDDEEEEEFFFFFFGGGGGGGHHHHHHHHH"
freq = {}


for ch in str2:
    #freq[ch] += 1  # KeyError: '5'
    freq[ch] = freq.get(ch, 0) + 1


# sorted_dict = dict(sorted(unsorted_dict.items()))
# sd = sorted(d.items())

key = sorted(freq.keys())


for char in freq:
    print("{}: {}".format(char, freq[char]))

print("Modified for use in huffman code:")
for char in freq:
    print("add to priority queue Key={}, Value={}".format(freq[char], char))
    

s= {}
d={}
d = dict(sorted(freq.items(), key = lambda x:x[1]))
for item in d.items():
    print(item)

s = dict(sorted(freq.items(), key = lambda kv:(kv[1], kv[0])))

x = {}
for key in d.keys():
    x[key] = ""
print(x)

x["Z"] = "0" + x.get("Z", "")
x["Z"] = "1" + x.get("Z", "")
print(x)


dict1 = {1: 1, 2: 9, 3: 4}
sorted_dict = {}
sorted_keys = sorted(freq, key=freq.get)  # [1, 3, 2]
print(sorted_keys)
for w in sorted_keys:
    sorted_dict[w] = freq[w]

print(sorted_dict)
codemap = {}
for key in sorted_dict.keys():
    codemap[key]=""
print(codemap)

headqueue= SortedPriorityQueue()

for i in sorted_keys:
    headqueue.add(int(sorted_dict[i]), str(i))
    
#headqueue.output()


while len(headqueue)>1:
    freq1, freq2 = 0, 0
    str1, str2 = "",""
    freq1, str1 = headqueue.remove_min()
    for char in str1:
        codemap[char] = "0" + codemap.get(char, "")
   # headqueue.output()
    freq2, str2 = headqueue.remove_min()
    for char in str2:
        codemap[char] = "1" + codemap.get(char, "")

    print(codemap)

    headqueue.add(freq1+freq2, str1+str2)
   # headqueue.output()