num = int(input())
print(" "*(num-1)+"*")
n = 1
for i in range(num-2, -1, -1):
    print(" "+i+'*'+' '*n+'*')
    j += 2
