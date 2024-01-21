//
//  main.cpp
//  10974 모든 순열
//
//  Created by Sun on 2024/01/22.
//

#include <iostream>

using namespace std;

int N;
bool vstd[8] = {0,};
int perm[8];

void permutation(int dpth) {
    if (dpth == N) {
        for (int i = 0; i < N; i++) {
            cout << perm[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (!vstd[i]) {     // 이미 사용한 숫자라면 pass. -> 중복x
            perm[dpth] = i+1;
            vstd[i] = true;
            permutation(dpth+1);
            vstd[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    permutation(0);
    
    return 0;
}

// 가장 기본적인 순열 구현. DFS+백트래킹 이용.
// "cout < endl"로 해결시 시간초과. (flush 때문) '\n'을 사용할 것.
