X = int(input())
i, a, b = 0, 0, 0

while X > 0:
    i += 1
    X -= i

if i % 2 == 0:
    a = i + X
    b = i + 1 - a
else:
    b = i + X
    a = i + 1 - b

print(str(a) + '/' + str(b))