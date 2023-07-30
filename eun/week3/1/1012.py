# 유기농 배추 (silver 2)

# dfs 사용
def dfs(x, y, N, M):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    if (x >= 0 and x < N and y >= 0 and y < M): 
        if (visited[x][y] == 0 and farm[x][y] == 1): # 방문 안 하고 배추가 있는 곳
            visited[x][y] = 1
            for i in range(4):
                x_ = x + dx[i]
                y_ = y + dy[i]
                dfs(x_, y_, N, M)
        else: # 방문 했거나 배추가 없는 곳
            return
    else:
        return

T = int(input())
ans = []

for test in range(T):
    M, N, K = map(int, input().split())
    farm = [[0]* M for i in range(N)]

    for cabbage in range(K):
        X, Y = map(int, input().split())
        farm[Y][X] = 1
    
    # print(farm) - 중간에 농장 제대로 입력 되었는지 확인하려고 ..
    visited = [[0]* M for i in range(N)]
    worm_num = 0
    #dfs - 처음 위치에서 이어서 dfs로 방문할 수 있는 곳 이어서 다 방문하고 방문 처리 하면서 각 구역 체크
    for n in range(N):
        for m in range(M):
            if (farm[n][m] == 1 and visited[n][m] == 0):
                dfs(n, m, N, M)
                worm_num += 1
    
    ans.append(worm_num)

for i in range(len(ans)):
    print(ans[i])