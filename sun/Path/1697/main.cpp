//
//  main.cpp
//  1697 숨바꼭질
//
//  Created by Sun on 2024/03/06.
//

#include <iostream>
#include <queue>

using namespace std;

int N, K;
int vstd[100001];

void bfs(int loc) {
    
    queue<int> q;
    q.push(loc);
    vstd[loc] = 1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == K)     break;
        
        if (x-1 >= 0 && !vstd[x-1]) {
            q.push(x-1);
            vstd[x-1] = vstd[x] + 1;
        }
        if (x+1 < 100001 && !vstd[x+1]) {
            q.push(x+1);
            vstd[x+1] = vstd[x] + 1;
        }
        if (2*x < 100001 && !vstd[2*x]) {
            q.push(2*x);
            vstd[2*x] = vstd[x] + 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> K;
    
    bfs(N);
    
    cout << vstd[K]-1 << endl;
    
    return 0;
}

// dp 문제라고만 생각했는데,.. 감이 안 잡혀서 다시 생각해보니까
// 기준 위치가 주어진다면, 1초 동안 움직일 수 있는 칸이 정해져있음 -> 연결 노드로 생각해서 각각을 큐에 넣어주면 됨!
// 이때 x-1, x+1, 2*x의 범위도 고려해줘야 함 !! 큰 숫자를 넣었을 때 에러가 발생해서 금방 파악할 수 있었음.

// 처음에는 정답(최소시간)을 저장하는 배열을 따로 뒀는데, 그러면 그 배열을 INF로 초기화해야 하기도 하고 매번 기존값과 비교해 min을 구해줘야 해서 visited 배열을 활용함. (이를 위해서는 반환형을 boolean -> integer로 변경)
// 이때 vstd 값이 zero인 경우를 방문하지 않은 지점으로 간주하려면 위치 N에서의 값을 0으로 설정하면 안됨..!
// 따라서 n으로 설정해놓고 결과값에서 그만큼 빼주기! 그냥 1로 했다.

// ++) 첫번째 방법에서는 조건문 안에서 vstd 배열 참조 순서가 문제가 되지는 않았는데, int 배열로 바꿔서 그런지 컴파일러가 알아서 처리해주지 못하는 것 같음. (100000 0) 같은거 넣어보면 확인 가능., 암튼 확실하게 범위 체크를 먼저 수행하도록 순서 바꿔주기.
