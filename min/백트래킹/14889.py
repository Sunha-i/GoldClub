import sys
n=int(sys.stdin.readline())
stat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)] #선수들의 능력치 테이블
player=[False for _ in range(n)]
minvalue=n/2 * (n/2-1) * 100

#양 팀의 능력치 차이를 구함
def get_ans():
    global minvalue
    s_result = 0
    l_result = 0

    sTeam=[idx for idx, val in enumerate(player) if val==True]
    lTeam=[idx for idx, val in enumerate(player) if val==False]
    for i in range(0, n//2):
        for j in range(i+1,n//2):
            s_first=sTeam[i]
            s_second=sTeam[j]
            s_result+=stat[s_first][s_second]+stat[s_second][s_first]

            l_first=lTeam[i]
            l_second=lTeam[j]
            l_result+=stat[l_first][l_second] + stat[l_second][l_first]
    
            minvalue=min(minvalue, abs(s_result - l_result))

#팀을 나누는 경우의 수를 백트래킹으로 탐색
def dfs(depth, idx):
    if depth ==n/2:
        get_ans()
        return
    
    for i in range(idx, n):
        if player[i]:
            continue
        player[i]=True
        dfs(depth+1, i)
        player[i]=False

dfs(0,1)
print(minvalue) #능력치 차이의 최솟값 출력
    