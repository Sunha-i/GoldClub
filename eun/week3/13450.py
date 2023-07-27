#László Babai (bronze 1)

T = int(input())
results = ['no'] * T

for i in range(T):
    gA = []
    gB = []

    m = int(input())
    for j in range(m):
        uv_set = set(list(map(int, input().split())))
        gA.append(uv_set)

    m_ = int(input())
    for j in range(m_):
        uv_set = set(list(map(int, input().split())))
        gB.append(uv_set)

    # vertex는 총 1,2,3 3개뿐이고 
    # 두 버텍스 사이의 에지는 최대 하나만 입력하도록 가정하니,
    # 에지의 수만 같으면 동형의 그래프가 된다.
    if (m == m_): 
        results[i] = 'yes'

for i in range(len(results)):
    print(results[i])