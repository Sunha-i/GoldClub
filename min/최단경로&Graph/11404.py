INF = int(1e9) #10억

#노드개수&간선개수 입력받기
n=int(input())
m=int(input())
graph=[[INF]*(n+1) for _ in range(n+1)]

#자기 자신에게 가는 비용 0으로 초기화

for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            graph[a][b]=0

#각 간선에 대한 정보를 입력받아 그 값으로 초기화
for _ in range(m):
    a,b,c=map(int,input().split())
    if graph[a][b] > c:
        graph[a][b]=c

#플루이드 워셜 알고리즘
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1): #a에서 b로 가는 비용과 a에서 k를 거쳐 b로 가는 비용 비교
            graph[a][b]=min(graph[a][b], graph[a][k]+graph[k][b])

#출력
for a in range(1,n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print("0", end = " ")
        else:
            print(graph[a][b], end=" ")
    print()