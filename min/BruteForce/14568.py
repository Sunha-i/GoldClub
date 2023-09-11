# 0개 받는 사람 없어야함,
# 남는 사탕은 없어야 함,
# 남규(c)는 영훈이(b)보다 2개 이상 많은 사탕을 가져야함
# 택희(a)가 받는 사탕의 수는 홀수개가 되어서는 안된다 => 즉, 짝수개로 가져야함
candy = int(input())

answer = 0
for A in range(0, candy+1):  # 0~6
    for B in range(0, candy+1):  # 0~6
        for C in range(0, candy+1):  # 0~6
            if A+B+C == candy:
                if A >= B+2:
                    if A != 0 and B != 0 and C != 0:
                        if C % 2 == 0:
                            answer += 1
print(answer)
