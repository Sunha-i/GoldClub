import sys
input= sys.stdin.readline
sys.setrecursionlimit(10**6) #재귀의 최대깊이 설정

#해당 위치에 배추가 있으면 dfs 수행 후 cnt + 1
#dfs
def dfs(x,y):
    dx=[0,0,-1,1] #상,하,좌,우
    dy=[1,-1,0,0]

    #탐색
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]

        if((0<=nx and nx<m) and (0<=ny and ny<n)) and graph[ny][nx]==1:
                graph[ny][nx]=-1 #지나간 곳은 -1로 표시
                dfs(nx,ny)



t=int(input())

for i in range(t):
    m,n,k=map(int, input().split())
    graph=[[0 for i in range(m)] for j in range(n)] #반대로 저장

    for j in range(k):
        x, y=map(int, input().split())
        graph[y][x]=1

    cnt=0
    for x in range(m):
        for y in range(n):
            if graph[y][x]==1:
                dfs(x,y)
                cnt+=1

    print(cnt)
        

    
