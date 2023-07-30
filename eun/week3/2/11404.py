n = int(input()) # 도시의 개수
m = int(input()) # 버스의 개수

mincost = [[0] * n for _ in range(n)] # n*n 최소 비용 배열

for bus in range(m):
    a, b, c = map(int, input().split())
    a = a - 1
    b = b - 1

    for dep in range(n):
        for arr in range(n):
            if (dep == arr):
                mincost[dep][arr] = 0
            else:
                # a -> b 인 경우
                if (dep == a and arr == b):
                    if mincost[dep][arr] == 0:
                        mincost[dep][arr] = c
                    else:
                        if mincost[dep][arr] > c:
                            mincost[dep][arr] = c
                # a -> 다른 도착지인 경우
                if (dep == a and arr != b):
                    if mincost[b][arr] != 0:
                        if mincost[dep][arr] == 0:
                            mincost[dep][arr] = c + mincost[b][arr]
                        else:
                            if mincost[dep][arr] > c + mincost[b][arr]:
                                mincost[dep][arr] = c + mincost[b][arr]
                # 다른 출발지 -> b 인 경우
                if (dep != a and arr == b):
                    if (mincost[dep][a] != 0):
                        if mincost[dep][arr] == 0:
                            mincost[dep][arr] = mincost[dep][a] + c
                        else:
                            if mincost[dep][arr] > mincost[dep][a] + c:
                                mincost[dep][arr] = mincost[dep][a] + c
                # 다른 출발지 -> 다른 도착지인 경우
                if (dep != a and arr != b):
                    if (mincost[dep][a] != 0 and mincost[b][arr] != 0):
                        if mincost[dep][arr] == 0:
                            mincost[dep][arr] = mincost[dep][a] + c + mincost[b][arr]
                        else:
                            if mincost[dep][arr] > mincost[dep][a] + c + mincost[b][arr]:
                                mincost[dep][arr] = mincost[dep][a] + c + mincost[b][arr]

for i in range(n):
    for j in range(n):
        print(mincost[i][j], end=' ')
    print('\n')