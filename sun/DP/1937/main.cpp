//
//  main.cpp
//  1937
//
//  Created by Sun on 2023/07/23.
//

#include <iostream>

int x,y,n;
int cnt = 0;

//bool vstd[500][500] = {0,};
int dp[500][500] = {0,};
int forest[500][500] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
//    vstd[x][y] = true;
    if (dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n
            && forest[x][y] < forest[nx][ny]) {
            dp[x][y] = std::max(dp[x][y], dfs(nx, ny)+1);
        }
    }
    return dp[x][y];
}

int main(int argc, const char * argv[]) {
    
    std::cin >> n;
    
    int b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> b;
            forest[i][j] = b;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = std::max(ans, dfs(i,j));
        }
    }
    std::cout << ans;

    return 0;
}
