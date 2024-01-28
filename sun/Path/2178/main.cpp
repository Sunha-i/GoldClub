//
//  main.cpp
//  2178 미로 탐색
//
//  Created by Sun on 2024/01/28.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char maze[100][100];
int dist[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y) {
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    dist[x][y] = 1;
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (!dist[nx][ny] && maze[nx][ny] == '1')
                {
                    // 인접한 칸들 중에 이동할 수 있는 칸(1)이면서 아직 방문하지 않은 칸에 대해 수행.
                    // dist 배열에는 (0,0)부터 해당 칸까지 이동하기 위해 지나야 하는 최소 칸 수를 기록.
                    
                    q.push({nx,ny});
                    dist[nx][ny] = dist[xx][yy] + 1;
                }
            }
        }
    }
    return dist[N-1][M-1];
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    
    cout << bfs(0, 0);
    
    return 0;
}
