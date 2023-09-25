n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
prefix = [[0 for _ in range(n+1)] for _ in range(n+1)]
arr = []
for _ in range(m):
    arr.append(list(map(int, input().split())))

for y in range(n):
    for x in range(n):
        prefix[y+1][x+1] = prefix[y][x+1] + \
            prefix[y+1][x]-prefix[y][x]+graph[y][x]
for i in range(m):
    x1, y1, x2, y2 = arr[i][0], arr[i][1], arr[i][2], arr[i][3]
    answer = prefix[y2][x2]-prefix[y2][x1-1] - \
        prefix[y1-1][x2]+prefix[y1-1][x1-1]
    print(answer)
