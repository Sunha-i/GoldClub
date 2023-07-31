from collections import deque
n=int(input())
graph=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
shark_x,shark_y=-1,-1
size, num=2, 0 #상어크기와 먹은 물고기수

for i in range(n):
    arr=list(map(int,input().split()))
    graph.append(arr)
    for j in range(n):
        if graph[i][j]==9:
            shark_x,shark_y=i,j
            graph[i][j]=0

#현재 상어 위치보다 크기가 작은 물고기 색출&거리,위치 계산
def bfs(shark_x,shark_y,size):
    visited= [[False]*n for _ in range(n)] 
    queue=deque() #탐색하는 큐(위치,지나간 칸수)
    queue.append((shark_x, shark_y, 0))
    visited[shark_x][shark_y] = True
    fish = [] #먹을 수 있는 물고기 리스트

    while queue:
        x,y,count = queue.popleft()
        for i in range(4):
            #위치
            nx=x+dx[i]
            ny=y+dy[i]
            
            if 0<=nx<n and 0<=ny<n and not visited[nx][ny]: #graph 범위체크&방문여부체크
                visited[nx][ny]=True
                if graph[nx][ny]!=0 and graph[nx][ny]<size:#먹을 수 있는지 체크
                    fish.append((count+1,nx,ny))#먹을 수 있는 물고기리스트
                    queue.append((nx,ny,count+1))
                    visited[nx][ny]=True
                elif graph[nx][ny]==0 or graph[nx][ny] ==size:#먹을 수는 없지만 지나갈 수 있는지 체크
                    visited[nx][ny] =True
                    queue.append((nx,ny,count+1))

    fish.sort() #거리,위쪽,왼쪽 우선순위로 정렬
    if fish:
        return [fish[0][1], fish[0][2], fish[0][0]] #위치,거리
    else:
        return []

result=0

while True:
    fish_eat = bfs(shark_x, shark_y, size)
    if fish_eat:
        x,y,move = fish_eat
        graph[x][y] =0
        num+=1 #먹은 물고기수
        result+=move
        if num==size:
            size += 1
            num=0
        shark_x, shark_y= x, y
    else:
        break

print(result)




    


