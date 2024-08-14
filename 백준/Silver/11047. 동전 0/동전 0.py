n, k = map(int, input().split())
lst = list()
cnt = 0
for i in range(n):
    lst.append(int(input()))

for i in reversed(lst):
    cnt += k//i
    k %= i
print(cnt)