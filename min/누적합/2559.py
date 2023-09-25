A, B = map(int, input().split())
arr = list(map(int, input().split()))
prefix = [0 for _ in range(A+1)]  # 1칸 더 크게 만들기

for i in range(A):
    prefix[i+1] = prefix[i]+arr[i]

answer = []
for k in range(B, A+1):
    answer.append(prefix[k]-prefix[k-B])

print(max(answer))
