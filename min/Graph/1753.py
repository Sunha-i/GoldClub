import heapq
import sys
input=sys.stdin.readline
INF=int(1e9)
#다익스트라 알고리즘으로 구현!

n, m = map(int, input().split()) #정점, 간선 정보 입력받기
start = int(input()) #시작 정점 입력받기
graph=[[] for i in range(n+1)] #각 노드에 연결되어있는 노드에 대한 정보 리스트(모든 정보 저장)
distance=[INF]*(n+1) #최단거리 테이블


#모든 간선 정보 입력받기
for _ in range(m):
    a,b,c=map(int,input().split())
    #a번노드에서 b번노드로 가는데 가중치가 c
    graph[a].append((b,c))


def dijkstra(start):
    que=[]
    heapq.heappush(que,(0,start)) #시작지점은 최단경로가 0이므로
    distance[start]=0

    while que:
        #가장 최단거리가 짧은 노드 꺼내기 
        dist, now=heapq.heappop(que)
        #현재 노드가 이미 처리된 적이 있으면 무시
        if distance[now]<dist:
            continue
        #현재노드와 연결된 인접노드 확인
        for i in graph[now]:
            cost=dist+i[1]
            #현재 노드를 거쳐 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost<distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(que, (cost,i[0]))

dijkstra(start)
        
#모든 노드로 가기 위한 최단 거리 출력
for i in range(1, n+1):
    #도달할 수 없는 경우
    if distance[i]==INF:
        print("INF")
    #도달할 수 있는 경우 거리
    else:
        print(distance[i]) 


