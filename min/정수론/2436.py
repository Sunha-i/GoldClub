# 1. 갭을줄여도 된다!

# 8 12
# 4 8

# 2.최대 공약수라는 말은 두 수 중 하나로 나누어서 나머지가 생기지 않는 다는 말이다
# 8 4

# 3. 한 수를 가능한만큼 갭을 줄인다.
# 하나의 수를 작은 수로 되는 만큼 뺀다는 말은
# 나누고 나서 나머지를 뜻한다

# 121 7
# 121-7-7-7-7-7-7
# 121%7

def _gcd(a, b):
    while a % b != 0:  # 나머지가 0이 되는 순간 멈춘다
        tmp = a % b
        a = b
        b = tmp
    return b


def _lcm(a, b):
    return a*b//_gcd(a, b)


a, b = map(int, input().split())
print(_gcd(a, b), _lcm(a, b))
