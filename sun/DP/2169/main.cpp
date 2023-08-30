//
//  main.cpp
//  2169
//
//  Created by Sun on 2023/08/25.
//

#include <iostream>
#include <vector>

using namespace std;

int map[1000][1000];
int d[1000][1000] = {0,};

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    // 첫번째줄은 왼쪽->오른쪽
    d[0][0] = map[0][0];
    for (int i = 1; i < M; i++) {
        d[0][i] = map[0][i] + d[0][i-1];
    }
    
    // 두번째줄부터는 max(->,<-)
    for (int i = 1; i < N; i++) {
        vector<int> LeftToRight(M);
        vector<int> RightToLeft(M);
        
        LeftToRight[0] = d[i-1][0] + map[i][0];
        RightToLeft[M-1] = d[i-1][M-1] + map[i][M-1];
        for (int j = 1; j < M; j++) {
            LeftToRight[j] = max(d[i-1][j], LeftToRight[j-1]) + map[i][j];
            RightToLeft[M-1-j] = max(d[i-1][M-1-j], RightToLeft[M-j]) + map[i][M-1-j];
        }
        for (int k = 0; k < M; k++) {
            d[i][k] = max(LeftToRight[k], RightToLeft[k]);
        }
    }
    
    // (N,M)에 저장된 가치 출력
    cout << d[N-1][M-1];
    
    return 0;
}
