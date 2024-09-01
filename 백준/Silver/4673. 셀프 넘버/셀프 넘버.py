def d(n):
    a = n
    lst = list(map(int, str(n)))
    for i in lst:
        a += i
    
    return a

lst = []

for i in range(10001):
    lst.append(d(i))

for i in range(10001):
    if i not in lst:
        print(i)