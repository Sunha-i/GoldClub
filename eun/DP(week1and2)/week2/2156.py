#포도주 시식
#d[n] = n번째 포도주까지 살펴봤을 때 먹을 수 있는 포도주의 가장 많은 양

n = int(input())
wine = []
d = [0] * n #maximum weight of wine hyoju can drink

for i in range(n):
    w = int(input()) #weight of each wine
    wine.append(w)
    if (i<2):
        d[i] = sum(wine)

    #현재 잔을 못 먹을 때, 전전 x & 전 o & 현재 o, 전전 o & 전 x & 현재 o
    elif (i==2):
        d[i] = max(d[1], wine[1]+wine[2], wine[0]+wine[2])
        #d[1] = wine[0] + wine[1]
    else:
        d[i] = max(d[i-1], d[i-3]+wine[i-1]+wine[i], d[i-2]+wine[i])

print(d[n-1])