import sys
sys.setrecursionlimit(10**6)  # 파이썬의 재귀 깊이 지정 (Python3)
input = sys.stdin.readline
n = int(input())
# 적록색맹이 아닐때 영역 개수 -> g를 r로 바꾸고 => 적록색맹일 때 영역 개수 구하자
graph = [list(input().rstrip()) for _ in range(n)]
dx = [-1, 0, 1, 0]  # 좌, 상, 우, 하
dy = [0, 1, 0, -1]


def visited_table():
    return [[False] * (n) for _ in range(n)]


def dfs(x, y):
    # 방문한 경우는 x
    if visited[x][y] == True:
        return 0
    visited[x][y] = True
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if nx < 0 or nx > (n-1) or ny < 0 or ny > (n-1):
            continue
        if visited[nx][ny] == True:
            continue
        if graph[x][y] == graph[nx][ny]:  # 같은 구역일 경우
            dfs(nx, ny)

    #구역 +1
    return 1


# 적록색맹 x case
result1 = 0
visited = visited_table()
for x in range(n):
    for y in range(n):
        result1 += dfs(x, y)

# 적록색맹 case
for x in range(n):
    for y in range(n):
        if graph[x][y] == 'R':
            graph[x][y] = 'G'

# 방문테이블 초기화
visited = visited_table()
result2 = 0
for x in range(n):
    for y in range(n):
        result2 += dfs(x, y)
print(result1, result2)
