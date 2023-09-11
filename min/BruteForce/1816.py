#소인수가 1000000 보다 크면 적절한 비밀번호
#100만보다 작고 2이상의 약수를 가지고 있다면 틀린 비밀번호!
TC=int(input())

for _ in range(TC):
    number = int(input())
    for i in range(2,1000001):
        if number%i == 0:
            print("NO")
            break
        if i==1000000:
            print("YES")