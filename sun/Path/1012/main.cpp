//
//  main.cpp
//  1012
//
//  Created by Sun on 2023/07/27.
//

#include <iostream>
#include <cstring>

using namespace std;

int M, N, K;
bool vstd[50][50];
int farm[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    vstd[x][y] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            if (farm[nx][ny] == 1 && !vstd[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        memset(vstd, 0, sizeof(vstd));
        memset(farm, 0, sizeof(farm));

        for (int j = 0; j < K; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            farm[y][x] = 1;
        }
        
        int cnt = 0;
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (farm[n][m] == 1 && !vstd[n][m]) {
                    dfs(n, m);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}

// 아이스크림 문제 -> dfs
// 배열 초기화는 memset으로 해결하자 ~^^
