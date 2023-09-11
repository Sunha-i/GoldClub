n = int(input())
arr = list(map(int, input().split()))
dp = [1 for _ in range(n)]  # 수열의 크기의 최솟값으로 초기화

for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:  # 크기만 하면 ㅇㅋ
            dp[i] = max(dp[i], dp[j]+1)  # 이전에 값중 가장 큰값으로 업데이트 해야하므로

print(max(dp))
# 와 코드 진짜 깔끔하게 짜셨다...!!
