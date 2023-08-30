import sys
input=sys.stdin.readline
N, M = map(int, input().split())
graph=[]
for _ in range(N):
    graph.append(list(map(int, input().split())))

dp = [ [0 for _ in range(M)] for _ in range(N)]
tmp=[ [0 for _ in range(M+2)] for _ in range(2)]

def robot() :
    #dp 첫번째 행 업데이트
    dp[0][0] = graph[0][0]
    for j in range(1, M):
        dp[0][j] += graph[0][j] + dp[0][j-1] 

    for i in range(1, N):
        tmp[0][0] = dp[i-1][0]
        for j in range(1,M+1): #위와 왼->오, 오->왼 비교, tmp 인덱스 기준으로 생각(1~M)
            tmp[0][j] = max(dp[i-1][j-1], tmp[0][j-1]) + graph[i][j-1]
        tmp[1][M+1] = dp[i-1][M-1]
        for k in range(M, 0, -1): #1~M
            tmp[1][k] = max(dp[i-1][k-1], tmp[1][k+1]) + graph[i][k-1]
        for x in range(M):
            dp[i][x] = max(tmp[0][x+1], tmp[1][x+1])

    print(dp[N-1][M-1]) 
robot()
