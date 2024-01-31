//
//  main.cpp
//  14502 연구소
//
//  Created by Sun on 2023/09/29.
//       & updated on 2024/01/31.
//

#include <iostream>
#include <algorithm>    // for copy
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    
    int tmp[8][8];
    copy(&map[0][0], &map[0][0]+64, &tmp[0][0]);
    
    queue<pair<int,int>> q;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                q.push({i,j});
            }
        }
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (tmp[nx][ny] != 0)   continue;
                tmp[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    
    int safearea = 0;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (tmp[n][m] == 0) safearea++;
        }
    }
    ans = max(ans, safearea);
}

void nCm(int cnt) {
    if (cnt == 3) {     // 벽을 3개 세우면
        bfs();          // bfs -> 바이러스 퍼트리기
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                nCm(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    nCm(0);
    cout << ans;
    
    return 0;
}

// 시간복잡도를 계산하거나 주어진 조건(가로세로 최대 8, 벽을 3개 세울 것)에서 힌트를 얻어
// 조합으로 모든 경우를 탐색하는 문제임을 파악해야함. 그 이후 구현은 간단함

// ++ 24/1/31 추가) 벽을 세우는 조합을 구하는 방법 수정
// 빈칸0들 중에 3개를 뽑고 벽을 세운 다음, 그 상태에서 bfs를 호출 -> 매번 새로운 map 필요.
