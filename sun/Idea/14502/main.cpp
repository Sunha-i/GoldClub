//
//  main.cpp
//  14502 연구소
//
//  Created by Sun on 2023/09/29.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int tmp_map[8][8];
bool vstd[8][8] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (tmp_map[nx][ny] != 0)   continue;
                tmp_map[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d %d", &N, &M);

    vector<pair<int,int>> blank;
    vector<pair<int,int>> virus;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)         blank.push_back({i,j});
            else if (map[i][j] == 2)    virus.push_back({i,j});
        }
    }

    int ans = 0;
    for (int i = 0; i < blank.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                map[blank[i].first][blank[i].second] = 1;
                map[blank[j].first][blank[j].second] = 1;
                map[blank[k].first][blank[k].second] = 1;
                
                copy(&map[0][0], &map[0][0] + 64, &tmp_map[0][0]);
                for (int v = 0; v < virus.size(); v++) {
                    bfs(virus[v].first, virus[v].second);
                }
                
                int safearea = 0;
                for (int n = 0; n < N; n++) {
                    for (int m = 0; m < M; m++) {
                        if (tmp_map[n][m] == 0) safearea++;
                    }
                }
                ans = max(ans, safearea);
                
                map[blank[i].first][blank[i].second] = 0;
                map[blank[j].first][blank[j].second] = 0;
                map[blank[k].first][blank[k].second] = 0;
            }
        }
    }
    cout << ans;
    
    return 0;
}

// 시간복잡도를 계산하거나 주어진 조건(가로세로 최대 8, 벽을 3개 세울 것)에서 힌트를 얻어
// 조합으로 모든 경우를 탐색하는 문제임을 파악해야함. 그 이후 구현은 간단함
