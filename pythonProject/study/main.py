def check(n):
    if n >= 35:
        print("더워")
    elif n < 35 and n > -10:
        print("살만하네")
    else:
        print("추웡ㅜ")


num1 = input("온도입력")
num2 = int(num1)


check(num2)
