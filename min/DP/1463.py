n=int(input())
arr=[0] * (n+1) #계산된 값을 저장함

for i in range(2, n+1):
    #이때 꼭 if else문이 아닌 if문만을 사용해야함
    arr[i] = arr[i-1]+1 
    if i%3==0:
        arr[i] = min(arr[i], arr[i//3]+1)
    if i%2==0:
        arr[i] = min(arr[i], arr[i//2]+1)
print(arr[n])
