//
//  main.cpp
//  2636 치즈
//
//  Created by Sun on 2024/03/04.
//

#include <iostream>
#include <queue>
#include <cstring>      // for memset

using namespace std;

int N, M;
int map[100][100];
bool vstd[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (!vstd[nx][ny]) {
                    if (map[nx][ny] == 0) {
                        q.push({nx,ny});
                    }
                    else {
                        map[nx][ny] = 0;
                    }
                    vstd[nx][ny] = true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    int hour = 0;
    int lastcheese = 0;
    while (true) {
        int cheese = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1)
                    cheese++;
            }
        }
        if (cheese == 0)    break;
        
        bfs(0, 0);
        memset(vstd, 0, sizeof(vstd));
        
        hour++;
        lastcheese = cheese;
    }
    
    cout << hour << "\n" << lastcheese;
    
    return 0;
}

// 공기와 접촉하는 치즈를 바로 녹여주는 방식을 위해서는 방문처리가 필요함.
// bfs 탐색은 공기에 대해서만 해주면 되고, 그렇지 않은 칸이면 공기와 맞닿는 치즈라서 녹여줘야 한다는 점을 이용해 적절한 위치에서 해당 연산을 수행 ~.~
