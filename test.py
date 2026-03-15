from random import shuffle
from random import randint
arr = ["Belal", "Anas", "Hossam", "Abdo"]

for i in range(randint(1, 10)):
    shuffle(arr)

print("1:" ,arr[0], arr[1])

print("2:" ,arr[2], arr[3])