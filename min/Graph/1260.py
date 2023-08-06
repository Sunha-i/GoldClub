import sys
from collections import deque
input = sys.stdin.readline
#dfs
def dfs(x):
    print(x, end=' ')
    visited[x] = 1
    for w in adj[x]:
        if not visited[w]:
            visited[w] = 1
            dfs(w)
#bfs
def bfs(x):
    q = deque()
    q.append(x)
    visited[x] = 1
    print(x, end=' ')
    while q:
        x = q.popleft()
        for i in adj[x]:
            if not visited[i]:
                visited[i] = 1
                q.append(i)
                print(i, end=' ')

n, m, v = map(int, input().split())
adj = [[] for _ in range(n+1)]
visited = [0 for _ in range(n+1)]
for _ in range(m):
    n1, n2 = map(int, input().split())
    adj[n1].append(n2)
    adj[n2].append(n1)
    adj[n1].sort()
    adj[n2].sort()

dfs(v)
print("")
visited = [0 for _ in range(n+1)] #방문 테이블 초기화 
bfs(v)