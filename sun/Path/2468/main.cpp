//
//  main.cpp
//  2468
//
//  Created by Sun on 2023/08/24.
//

#include <iostream>
#include <cstring>

using namespace std;

int N, ice = 0;

int map[100][100];
bool vstd[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int h) {
    vstd[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (map[nx][ny] - h > 0 && !vstd[nx][ny] &&
            0 <= nx && nx < N && 0 <= ny && ny < N) {
            dfs(nx,ny,h);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int min = 101;
    int max = 1;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int h;
            cin >> h;
            if (h < min)    min = h;
            if (h > max)    max = h;
            map[i][j] = h;
        }
    }

    int ans = 0;
    for (int h = min-1; h < max; h++) {
        memset(vstd, 0, sizeof(vstd));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] - h > 0 && !vstd[i][j]) {
                    dfs(i, j, h);
                    ice += 1;
                }
            }
        }
        ans = std::max(ans, ice);
        ice = 0;
    }
    
    cout << ans;
    
    return 0;
}

// 반례 유의할 것 -> 비가 아예 안올수도 있음
//2
//1 1
//1 1
//1
