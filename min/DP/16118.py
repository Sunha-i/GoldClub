# 다익스트라 알고리즘
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int(input().split()))
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

# 여우


def fox_dijk():
    distance = [INF]*(n+1)  # 거리테이블 초기화
    distance[1] = 0
    q = []
    heapq.heappush(q, (0, 1))  # 시작노드로 가기 위한 최단경로는 0 으로 설정후 큐에 삽입
    while q:
        dist, now = heapq.heappop(q)  # 가장 거리가 짧은 노드 꺼내기
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist+i[1]
            if cost < distance[i[0]]:  # 현재 노드를 거쳐 다른 노드로 이동하는 거리가 더 짧은 경우
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    return distance[2:]

# 늑대


def wolf_dijk():


fox = fox_dijk()
wolf = wolf_dijk()
result = 0
for i in range(n):
    if fox[i] <:
        result += 1
print(result)
