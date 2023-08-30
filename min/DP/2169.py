import sys
input=sys.stdin.readline
N, M = map(int, input().split())
dp=[]
for _ in range(N):
    dp.append(list(map(int, input().split())))
tmp=[ [0 for _ in range(M+2)] for _ in range(2)]
print(dp)
print(tmp)
def robot() :
    #dp 첫번째 행 업데이트
    for j in range(1, M):
        dp[0][j] += dp[0][j-1]

    for i in range(1, N):
        tmp[0][0] = dp[i-1][0]
        tmp[1][M+1] = dp[i-1][M-1]
        for j in range(1, M): #위와 왼->오, 오->왼 비교
            tmp[0][j] = max(dp[i-1][j], tmp[0][j-1]) + dp[i-1][j-1]
        for k in range(M-1,-1):
            tmp[1][k] = max(dp[i-1][k], tmp[1][k+1]) + dp[i-1][k-1]
        for x in range(1, M+1):
            dp[i][x] = max(tmp[0][x], tmp[1][x])

    print(dp[N-1][M-1]) 
        
robot()
