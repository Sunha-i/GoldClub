# DP(메모리제이션) => BUT 누적합으로도 풀 수 있다

N = int(input())
arr = list(map(int, input().split()))
prefix = [0 for _ in range(N+1)]

for i in range(N):
    prefix[i+1] = max(arr[i], prefix[i]+arr[i])

max = -1000
for i in range(1, N+1):
    if max < prefix[i]:
        max = prefix[i]
# 이렇게 하거나 애초에 prefix 배열을 -1001로 초기화시킬것
print(max)
