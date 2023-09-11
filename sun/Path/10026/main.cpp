//
//  main.cpp
//  10026
//
//  Created by Sun on 2023/09/11.
//

#include <iostream>
#include <queue>
#include <cstring>  //memset

using namespace std;

int N;
char photo[100][100];
bool vstd[100][100] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, char color) {
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (photo[nx][ny] == color && !vstd[nx][ny]) {
                    q.push({nx,ny});
                    vstd[nx][ny] = true;
                }
            }
        }
        // 재활용을 위해 ...
        if (photo[x][y] == 'G')
            photo[x][y] = 'R';
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> photo[i][j];
        }
    }
    
    int normal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vstd[i][j]) {
                bfs(i,j,photo[i][j]);
                normal++;
            }
        }
    }
    cout << normal << " ";
    
    memset(vstd, 0, sizeof(vstd));
    
    int colorblind = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vstd[i][j]) {
                bfs(i,j,photo[i][j]);
                colorblind++;
            }
        }
    }
    cout << colorblind;
    
    return 0;
}
