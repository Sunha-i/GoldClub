'''
from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
n = int(input())
visited = [0]*(n+1)  # 1부터 시작하므로 n+1로 만들었음, 중복여부 체크
dp = [[-1]*2 for _ in range(n+1)]  # 위와 마찬가지로 n+1
graph = defaultdict(list)
for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(x):
    visited[x] = 1
    dp[x][0] = 0  # 재귀로 들어온 후 얼리어답터가 아닐 때는 0으로
    dp[x][1] = 1  # 얼리어답터인 경우는 1로
    for i in graph[x]:  # x와 연결되어 있는 노드들 탐색
        if not visited[i]:
            dfs(i)
            dp[x][0] += dp[i][1]
            dp[x][1] += min(dp[i][0], dp[i][1])

 
dfs(1)
print(min(dp[1][0], dp[1][1]))
'''
import sys
sys.setrecursionlimit(10 ** 9)
input = sys.stdin.readline
N=int(input())
tree=[[] for _ in range(N + 1)]
dp=[[0, 0] for _ in range(N + 1)]
visited=[0 for _ in range(N + 1)]
#dp[n][0]일 때는 n이 얼리어답터일 때의 최소 정점 수를, dp[n][1]일 때는 n이 얼리어답터가 아닐 때의 최소 정점 수를 기록함
for _ in range(N - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

def dfs(node):
    visited[node] = 1
    dp[node][0] = 1
    for child_node in tree[node]:
        if not visited[child_node]:
            dfs(child_node)
            dp[node][0] += min(dp[child_node][0], dp[child_node][1])
            dp[node][1] += dp[child_node][0]
dfs(1)
answer = min(dp[1][0], dp[1][1])
print(answer)