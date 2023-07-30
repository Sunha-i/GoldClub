//
//  main.cpp
//  17129
//
//  Created by Sun on 2023/07/26.
//

#include <iostream>
#include <queue>

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[3001][3001];
int dist[3001][3001];

int bfs(int x, int y)
{
    std::queue<std::pair<int,int>> que;
    que.push({x,y});
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if (map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5)
            return dist[x][y];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (map[nx][ny] == 1)
                    continue;
                
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx,ny});
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    std::cin >> n >> m;
    std::string str;
    
    int start[2];
    for (int i = 0; i < n; i++)
    {
        std::cin >> str;
        for (int j = 0; j < m; j++)
        {
            int val = static_cast<int>(str[j]) - '0';
            if (val == 2) {
                start[0] = i;
                start[1] = j;
            }
            map[i][j] = val;
        }
    }
    
    int ans = bfs(start[0], start[1]);
    if (ans == -1)  std::cout << "NIE";
    else    std::cout << "TAK\n" << ans;
    
    return 0;
}
