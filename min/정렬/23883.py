n, k = map(int, input().split())
a=list(map(int, input().split())) #리스트 입력받기
cnt=0

for i in range(n-1,-1,-1):
    max_index=i #가장 큰 원소의 인덱스
    for j in range(i-1,-1,-1):
        if a[max_index] < a[j]:
            max_index = j
    if i==max_index:
        continue
    a[i], a[max_index] = a[max_index], a[i]
    cnt+=1
    if cnt==k:
        print(a[max_index],a[i])

if cnt<k:
    print("-1")


