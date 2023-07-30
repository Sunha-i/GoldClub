# 윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유 (silver 1)

# 청국장 : 3, 스시 : 4, 맥앤치즈 : 5
def dfs_3(x, y , n, m, d_3):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    if (x>=0 and x<n and y>=0 and y<m):
        for i in range(4):
            x_ = x + dx[i]
            y_ = y + dy[i]
            if (island[x_][y_] == 1 and visited_3 == 0):
                if (d_3[x_][y_] != 0):
                    d_3[x_][y_] = min(d_3[x_][y_], d_3[x][y] + 1)
                    dfs_3(x_, y_, n, m, d_3)
                else:
                    d_3[x_][y_] = d_3[x][y] + 1
                    dfs_3(x_, y_, n, m, d_3)
            elif (island[x_][y_] == 3):
                d_3[x_][y_] = min(d_3[x_][y_], d_3[x][y] + 1)
            else:
                return
    else:
        return

def dfs_4(x, y, n, m):

def dfs_5(x, y ,n, m):


n, m = map(int, input().split())
island = [[0]* m for i in range(n)]

visited_3= [[0]* m for i in range(n)]
visited_4= [[0]* m for i in range(n)]
visited_5= [[0]* m for i in range(n)]

d_3 = [[0]* m for i in range(n)]
d_4 = [[0]* m for i in range(n)]
d_5 = [[0]* m for i in range(n)]

start = []

for i in range(n):
    row = input()
    for j in range(m):
        island[i][j] = row[j]
        if (island[i][j] == 2):
            start.append(i)
            start.append(j)

dfs_3(start[0], start[1], n, m, d_3)
dfs_4(start[0], start[1], n, m, d_4)
dfs_5(start[0], start[1], n, m, d_5)

