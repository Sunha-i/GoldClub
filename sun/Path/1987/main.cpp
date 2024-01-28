//
//  main.cpp
//  1987 알파벳
//
//  Created by Sun on 2024/01/28.
//

#include <iostream>

using namespace std;

int R, C;
char board[20][20];
bool alphabet[26];
bool vstd[20][20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int ans = 0;

void dfs(int x, int y, int dpth) {
    
    vstd[x][y] = true;
    alphabet[board[x][y] - 'A'] = true;     // 말이 지난 알파벳 체크!
    ans = max(ans, dpth);
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C) {
            if (!alphabet[board[nx][ny] - 'A'])
            {
                // 지금까지 지나온 모든 칸에 적혀있지 않은 알파벳인지 확인.
                // 백트래킹을 이용해 최적해 찾기. dpth는 말이 지나는 칸의 수를 카운팅.
                
                alphabet[board[nx][ny] - 'A'] = true;
                dfs(nx, ny, dpth+1);
                alphabet[board[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 1);
    cout << ans << endl;
    
    return 0;
}
