a, b, c, d, e, f = map(int, input().split())
# 직접 대입해보면서 푸는 방식?
for x in range(-999, 1000):
    for y in range(-999, 1000):
        if a*x + b*y == c:
            if d*x+e*y == f:
                print(x, y)
                break
