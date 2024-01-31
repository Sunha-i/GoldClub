//
//  main.cpp
//  2667 단지번호붙이기
//
//  Created by Sun on 2023/09/11.
//       & updated on 2024/01/31.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>    //sort

using namespace std;

int N;
char map[25][25];
bool vstd[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int house = 0;
vector<int> complex;

void dfs(int x, int y) {
    
    vstd[x][y] = true;
    house++;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (map[nx][ny] == '1' && !vstd[nx][ny])
                dfs(nx, ny);
        }
    }
}

void bfs(int x, int y) {
    
    if (map[x][y] == '0')   return;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    vstd[x][y] = true;
    house++;
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (!vstd[nx][ny] && map[nx][ny] == '1') {
                    q.push({nx,ny});
                    vstd[nx][ny] = true;
                    house++;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !vstd[i][j])
            {
                bfs(i, j);      // or dfs(i,j)
                complex.push_back(house);
                house = 0;
            }
        }
    }
    
    cout << complex.size() << endl;
    sort(complex.begin(), complex.end());
    for (int i = 0; i < complex.size(); i++) {
        cout << complex[i] << endl;
    }
    
    return 0;
}

// 아이스크림 문제
