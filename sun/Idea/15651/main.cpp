//
//  main.cpp
//  15651 N과 M(3)
//
//  Created by Sun on 2024/01/22.
//

#include <iostream>

using namespace std;

int N, M;
int perm[7];

void npiem(int dpth) {
    if (dpth == M) {
        for (int i = 0; i < M; i++) {
            cout << perm[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        perm[dpth] = i+1;
        npiem(dpth+1);
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    npiem(0);
    
    return 0;
}

// 중복순열, nㅠm 구현; n개 중에 m개를 골라 수열을 만드는데 중복을 허용함.
// 중복을 허용하니까 vstd 배열이 필요없음! just DFS 구조.
