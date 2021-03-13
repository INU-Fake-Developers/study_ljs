num = int(input("정수 입력:"))
for i in range(1, num+1):
    for j in range(i):
        print("*", end="")
    print()
