N = int(input())
result = []

try:
  if N % 5 == 0:
    result.append(N // 5)
  if N % 3 == 0:
    result.append(N // 3)
  if (N % 5) % 3 == 0:
    result.append((N // 5) + ((N % 5) // 3))
  for i in range(1, N//5+1):
    if (N - i * 5) % 3 == 0:
      result.append(i + (N - i * 5) // 3)
  
  result.sort()
  result = result[0]
  
except:
  result = -1

print(result)