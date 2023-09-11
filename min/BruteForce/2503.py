# A가 정답으로 생각할 수 있는 모든 수 넣어보기
# 그리고 B가 도전한 내용에 맞는지 확인하기!
# 서로 다른 세자리수
N = int(input())
HINT = [list(map(int, input().split()))
        for _ in range(N)]  # [[123, 1, 1], [356, 1, 0] ..]
answer = 0
for a in range(1, 9):  # 100의 자리수
    for b in range(1, 9):  # 10의 자리수
        for c in range(1, 9):  # 1의 자리수
            if(a or b == c or c == a):  # 서로 다른 숫자로 이루어진 세자리수이므로
                continue
            # 숫자가 정해지면
            cnt = 0
            for arr in HINT:
                number = list(arr[0])
                strike = list(arr[1])
                ball = list(arr[2])

                # a,b,c 숫자를 number과 비교해서 자리수를 나눠 strike를 측정하는 부분
                ball_count = 0
                strike_count = 0
                '''
                number_a = number[0]
                number_b = number[1]
                number_c = number[2]
                if a == number_a:
                    bal
                '''

                if ball == ball_count and strike == strike_count:
                    cnt += 1
            if cnt == N:
                answer += 1
