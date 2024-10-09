A, B = map(list, input().split())

for i in A, B:
    tmp = i[2]
    i[2] = i[0]
    i[0] = tmp

A = ''.join(map(str, A))
B = ''.join(map(str, B))

if A > B:
    print(A)
else:
    print(B)