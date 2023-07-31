import heapq
import sys
input=sys.stdin.readline
INF=(1e9)

n,m=map(int, input().split())
graph=[[] for _ in range(n+1)]
for i in range(1,n+1):
    a, b, c=map(int, input().split()) 
    graph[a].append((b,c))
    graph[b].append((a,c))

v1,v2=map(int, input().split())

def dijkstra(start):
    q=[]
    distance=[INF]*(n+1)
    heapq.heappush(q,(0,start))
    distance[start]=0

    while q:
        dist,now=heapq.heappop(q)
        
        for i in graph[now]:
            cost=dist+i[1]
            if cost< distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))
    return distance

from_1=dijkstra(1)
from_v1=dijkstra(v1)
from_v2=dijkstra(v2)

result=min(from_1[v1]+from_v1[v2]+from_v2[n],from_1[v2]+from_v2[v1]+from_v1[n])
if result>=INF :
    print(-1)
else:
    print(result)
