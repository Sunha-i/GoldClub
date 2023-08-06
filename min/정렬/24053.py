n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
result=0

for i in range(1,n):
    loc=i-1
    newItem=a[i]

    while loc>=0 and newItem < a[loc]:
        a[loc+1]=a[loc]
        loc-=1
    if (loc+1) is not i:
        a[loc+1]=newItem
    if a==b:
        result=1
        
print(result)



