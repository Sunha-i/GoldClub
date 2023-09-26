//
//  main.cpp
//  30052 거리 두기 게임
//
//  Created by Sun on 2023/09/27.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, M, D;
    scanf("%d %d", &N, &M);
    scanf("%d", &D);

    vector<vector<bool>> grid(N, vector<bool>(M, 0));
    
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            if (i + j < D)  break;
            grid[i][j] = true;
        }
    }
    
    int ans = 0;
    for (int i = N/2; i < N; i++) {
        for (int j = M/2; j < M; j++) {
            if (!grid[i][j])    continue;
            if ((N % 2 != 0 && i == N/2) || (M % 2 != 0 && j == M/2)) {
                ans += 2;
                continue;
            }
            ans += 4;
        }
    }
    if (N % 2 != 0 && M % 2 != 0 && grid[N/2][M/2])
        ans--;
    printf("%d", N * M - ans);
    
    return 0;
}

// 문제 이해하기
// 준성쓰가 어떤 칸을 밟더라도 효석이가 승리하는 루트가 있어야 함
// -> 각 모서리를 기준으로 조건을 만족하는 칸 찾기
// -> 답은 그 반대일 것

// 테스트 케이스 (D = 4)
// 0 0 0
// 0 x 0
// 0 x 0
// 0 0 0

// 테스트 케이스 (D = 7)
// 0 x x x 0
// x x x x x
// x x x x x
// 0 x x x 0

// 구현 과정에서는 (0,0) 모서리를 기준으로 구해주고 4등분해서 count
// (홀수 영역)이면 x2, [짝수 영역]이면 x4
// 0  0  0  0  0  0  0
// 0  0  0  0  0  0  x
// 0  0  0  0  0 (x)(x)
// 0  0  0  0 [x][x][x]
// 0  0  0 (x)[x][x][x]
