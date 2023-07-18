num=int(input())

for i in range(num):
    k=int(input())
    n=int(input())
    people=[i for i in range(1,n+1)] #0층
    
    for j in range(k): #각 층에 대한 반복문을 돌면서
        temp = [] 
        for l in range(n): #n호 전까지 반복문을 돌면서 합함
            temp.append(sum(people[:l+1])) 
        people = temp.copy() #각 층에 대한 반복문 끝낸 후 people 리스트에 값 없데이트
    print(people[-1])
