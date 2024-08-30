A = input().upper()
lst1 = list(set(A))
lst2 = list()
            
for i in lst1:
    cnt = 0
    
    for j in A:
        if i == j:
            cnt += 1
            
    lst2.append(cnt)

cnt = 0

for i in lst2:
    if i == max(lst2):
        cnt += 1

if cnt > 1:
    print('?')
else:     
    idx = lst2.index(max(lst2))
    print(lst1[idx])