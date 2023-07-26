#욕심쟁이 판다

n = int(input())
forest = [[0] * (n+2)] * (n+2) #(n*2) x (n+2) 행렬 만들기
d = [[0] * (n+2)] * (n+2)

for row in range(n+2):
    for col in range(n+2):
        if(row == 0 or row == (n+1) or col == 0 or col == (n+1)):
            forest[row][col] = 0
        else:
            forest[row][col] = int(input())

for row in range(n+1,-1,-1):
    for col in range(n+1,-1,-1):
        if(row == 0 or row == (n+1) or col == 0 or col == (n+1)):
            d[row][col] = 0
        elif (row == 1 or row == n or col == 1 or col == n):
            if (forest[row][col] < forest[row-1][col]):
                d[row][col] += 1
            if (forest[row][col] < forest[row][col+1]):
                d[row][col] += 1
            if (forest[row][col] < forest[row+1][col]):
                d[row][col] += 1
            if (forest[row][col] < forest[row][col-1]):
                d[row][col] += 1
        else :
            if (forest[row][col] < forest[row-1][col]):
                d[row][col] += d[row-1][col]
            if (forest[row][col] < forest[row][col+1]):
                d[row][col] += d[row][col+1]
            if (forest[row][col] < forest[row+1][col]):
                d[row][col] += d[row+1][col]
            if (forest[row][col] < forest[row][col-1]):
                d[row][col] += d[row][col-1]

alld = []
for row in range(n+2):
    for col in range(n+2):
        alld.append(d[row][col])


print(max(alld))
