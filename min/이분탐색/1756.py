d, n = map(int, input().split())
oven = list(map(int, input().split()))
pizza = list(map(int, input().split()))

for i in range(1, len(oven)):
    if oven[i] > oven[i-1]:
        oven[i] = oven[i-1]

start, end = 0, len(oven)-1
result=0
for i in range(len(pizza)):

    while start<=end:
        mid=(start+end)//2
        if oven[mid]>=pizza[i]:
            start=mid+1
        else:
            end=mid-1
    result=end
    start=0
    end=end-1
if result<0:
    print(0)
else:
    print(result+1)
