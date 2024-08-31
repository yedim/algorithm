A, B, V = map(int, input().split())

tmp = (V - B) // (A - B)
if (V - B) % (A - B) != 0:
    tmp += 1

print(tmp)