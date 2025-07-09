import math


def Is_Prime(num):
    lim = int(math.sqrt(num)) + 1
    for i in range(2, lim):
        if num % i == 0:
            return False
    return True


def main():
    a = []
    num = 2
    lim = eval(input())
    while True:
        if Is_Prime(num):
            if sum(a) + num > lim:
                break
            a.append(num)
        num += 1
    for i in a:
        print(i)
    print(len(a))


main()
