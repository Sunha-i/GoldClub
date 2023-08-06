n, k = map(int, input().split())
li = list(map(int, input().split()))
sorted_li = sorted(li)
d = {}

for i, l in enumerate(li):
    d[l] = i

i = n - 1
for i in range(n - 1, -1, -1):
    if sorted_li[i] != li[i]:
        temp = [li[i], sorted_li[i]]
        li[i], li[d[sorted_li[i]]] = li[d[sorted_li[i]]], li[i]
        d[temp[0]], d[temp[1]] = d[temp[1]], d[temp[0]]
        k -= 1
        if k == 0:
            print(*temp)
            exit()

print(-1)