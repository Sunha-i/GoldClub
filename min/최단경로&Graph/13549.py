import heapq
import sys
input=sys.stdin.readline
INF=int(1e9)
#다익스트라 알고리즘으로 구현!

n, k = map(int, input().split()) #정점, 간선 정보 입력받기

time=[INF]*(100001) #최단거리 테이블
dx=[(1,1),(1,-1),(0,2)]

'''
def dijkstra(n,k):
    que=[]
    heapq.heappush(que,(0,n)) #시작지점은 최단경로가 0이므로
    time[n]=0

    while que:
        #가장 타임이 짧은 노드 꺼내기 
        cost, now=heapq.heappop(que)
        
        #현재 노드가 이미 처리된 적이 있으면 무시
        if time[now]<cost:
            continue
        
        #현재노드와 연결된 인접노드 확인
        for i in nx:
            if i==0 or i==1:
                if time[now+i[1]]>cost+i[0]:
                    time[now+i[1]]=cost+i[0]
                    heapq.heappush(que,(cost+i[0],now+i[1]))
        
            else:
                if time[now*i[1]]>cost:
                    time[now*i[1]]=cost
                    heapq.heappush(que,(cost,now*i[1]))
    print(time[k])
'''
def dijkstra(n,k):
    dist = [INF]*(100001)
    dist[n] =0 
    hq = []
    heapq.heappush(hq,(0,n))
    while hq:
        w,v = heapq.heappop(hq)
        for nx in [(v+1,1),(v-1,1),(v*2,0)]:
            if 0<=nx[0]<100001 and dist[nx[0]] > w + nx[1]:
                dist[nx[0]] = w + nx[1]
                heapq.heappush(hq,(dist[nx[0]],nx[0]))
    print(dist[k])
    
dijkstra(n,k)

