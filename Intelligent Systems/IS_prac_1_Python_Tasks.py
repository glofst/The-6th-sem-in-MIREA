def task4():
    n = int(input())
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            print(j, end='')
        print()


def task5():
    s = input()
    s = s.replace('@', '')
    print(s)


def task6():
    x = int(input())
    counter = 0
    while x != 0:
        if x % 2 == 0:
            counter += 1
        x = int(input())
    print(counter)


def task7():
    a = input().split()
    for i in range(len(a)):
        a[i] = int(a[i])
    min_a = a.index(min(a))
    max_a = a.index(max(a))
    a[min_a], a[max_a] = a[max_a], a[min_a]
    for elem in a:
        print(elem, end=' ')


def power(a, n):
    if n == 0:
        return 1
    return a * power(a, n-1)


def task8():
    a = float(input())
    n = float(input())
    print(power(a, n))


def task9():
    n = int(input())
    a = [[abs(i - j) for j in range(n)] for i in range(n)]
    for row in a:
        for elem in row:
            print(elem, end=' ')
        print()


def task10():
    m = set()
    n, k = (int(i) for i in input().split())
    for i in range(k):
        a_i, b_i = (int(j) for j in input().split())
        while a_i <= n:
            if a_i % 6 != 0 and a_i % 7 != 0:
                m.add(a_i)
            a_i += b_i
    print(len(m))


def task11():
    customers = dict()
    name, prod, amount = (i for i in input().split())
    amount = int(amount)
    if name not in customers:
        customers[name] = dict()
    if prod not in customers[name]:
        customers[name][prod] = 0
    customers[name][prod] += amount
    for cus in customers:
        print(cus, ':', sep='')
        for prods in customers[cus]:
            print(prods, customers[cus][prods])



task11()
