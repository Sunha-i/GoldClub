from collections import deque

N, K = map(int, input().split())
q = deque() # 빈 리스트를 초기화하여 빈 deque 객체 생성. 
q.append(N)
visited = [-1 for _ in range(100001)] # visited 리스트를 -1의 100001개 요소로 초기화.
visited[N] = 0

while q:
    x = q.popleft() # pop(0)을 하면 리스트의 크기에 따라 O(n)의 시간이 걸리는 반면, popleft()를 하면 리스트의 맨 마지막 값을 가져오는 pop()과 마찬가지로 O(1)의 시간이 걸린다. 
    if x == K: # 동생이 있는 위치에 다다르면 걸린 시간을 print 함.
        print(visited[x])
        break # break를 통해 while 문 탈출

        """
    # 반복문을 통해 3가지 이동의 경우를 확인
    for next_x in (x+1, x-1, x*2):
        if 0 <= next_x < 100001 and visited[next_x] == -1: # 다음에 방문할 위치가 주어진 범위 안에 있고, 한 번도 방문한 적 없는 위치일 경우
        # 아마 2배 해서 0초만에 순간이동 하는 거를 우선순위를 높게 둬서 하니까,
        # visited에 가장 먼저 적히는 것이 가장 빠르게 접근하는 방법이라고 해서 
        # visited[x-1] == -1 이라는 조건이 붙은 듯.
            if (next_x == 2*x and next_x != 0):
                visited[next_x] = visited[x]
                q.appendleft(next_x) # 2*x가 다른 연산보다 높은 우선순위를 가지기 위해서 큐의 가장 앞에 넣어 줌.
            if (next_x == x+1 or next_x == x-1): # 그냥 else로 하면 next_x = x*2이고 next_x == 0인 경우에 아래의 식이 수행될 수 있음.
                # 이거 elif로 하면 2*x 을 넣었을 경우 x+1 이랑 x-1은 확인 안 하니까 if로 해야 함.
                visited[next_x] = visited[x] + 1
                q.append(next_x)

                
    ->  이렇게 하면 틀린 이유 
        : next_x == 2*x and next_x != 0;
          이라서 visited[next_x]를 visited[x]로 바꿨는데, 
          이 바꾼 visited[next_x]가 이때 -1이 아니게 될 경우
          그냥 아래로 내려가서 next_x == x+1 or next_x == x-1 만 만족하면 
          visted[next_x] = visited[x] + 1로 또 바꾸고 q.append(next_x)를 또 함. 
          예로는 x가 1인 경우가 있음. 
          x가 1이면 next_x == 2인 경우가 next_x == 2*x 이면서 next_x == x+1이기 때문.

        따라서 아래와 같이 해줘야 함.

        """
    if 0 <= x-1 < 100001 and visited[x-1] == -1:
        visited[x-1] = visited[x] + 1
        q.append(x-1)
    if 0 < x*2 < 100001 and visited[x*2] == -1:
        visited[x*2] = visited[x]
        q.appendleft(x*2)  # 2*s 가 다른 연산보다 더 높은 우선순위를 가지기 위함
    if 0 <= x+1 < 100001 and visited[x+1] == -1:
        visited[x+1] = visited[x] + 1
        q.append(x+1)