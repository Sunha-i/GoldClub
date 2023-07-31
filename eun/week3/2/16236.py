# 아기 상어
# 다익스트라
# 자신보다 크기가 큰 물고기까지의 거리는 무한, 작거나 같은 물고기까지의 거리는 1로 설정.

N = int(input()) # 공간의 크기
aquamap = [] # N*N map
minlen = [[1]*N for _ in range(N)]
shark_size = 2

for i in range(N):
    a = list(map(int, input().split()))
    aquamap.append(a)
    for j in range(N):
        if aquamap[i][j] > shark_size:
            minlen[i][j] = int(1e9)

# 그래서 이 2차원 배열을 그래프 형식으로 보고 상어 크기가 달라짐에 따라 간선의 가중치를 조정해가면서
# 다익스트라를 써서 최단 경로를 구하고자 했음.
