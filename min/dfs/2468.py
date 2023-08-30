import sys
sys.setrecursionlimit(10**6) # 재귀 깊이 제한 설정
n = int(input())
graph = []
dx = [1,-1,0,0]
dy = [0,0,-1,1]
for i in range(n):
    graph.append(list(map(int,input().split())))

# 그래프 내 최댓값,최솟값 구하기
maximum = []
minimum = []
for i in graph:
    maximum.append(max(i))
    minimum.append(min(i))
maximum = max(maximum)
minimum = min(minimum)

# dfs로 탐색
def dfs(x,y):    
    # 범위 벗어나는 경우
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    # 좌표값이 0인 경우
    if temp_graph[x][y] == 0:
        return False
    #인근 지점 체크
    if temp_graph[x][y] == 1:
        temp_graph[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)
        # 검사 후 True를 return
        return True
    return False

results = [] # 최종 결과가 담길 리스트
# 수위를 기준으로 매번 탐색
for level in range(minimum-1,maximum+1):
    # 수위마다 새로운 그래프 생성(원 그래프 카피)
    temp_graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            temp_graph[i].append(graph[i][j])
    
    # 수위보다 높으면 1, 이하면 0으로 변경        
    for i in range(n):
        for j in range(n):
            if temp_graph[i][j] > level: temp_graph[i][j] = 1
            else: temp_graph[i][j] = 0
    cnt = 0 # 카운트 초기화
    for i in range(n):
        for j in range(n):
            # DFS 실행시 카운트
            if temp_graph[i][j] == 1:
                dfs(i,j)
                cnt += 1
    # 결과 리스트에 담아 놓기
    results.append(cnt)
# 결과 리스트 중 최댓값 출력
print(max(results))