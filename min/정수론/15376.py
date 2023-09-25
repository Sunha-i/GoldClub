# 수학적으로 생각해보기
# 제곱수 구하면됨
n = int(input())
cnt = 0

for i in range(1, n+1):
    if pow(i, 2) <= n:
        cnt += 1
print(cnt)

'''
또는 이렇게 풀기도 가능
'''
answer = int(n**0.5)  # 루트로 나눠서 정수로 바꾼것이 정답이 된다!
print(answer)
