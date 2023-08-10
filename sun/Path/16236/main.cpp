//
//  main.cpp
//  16236
//
//  Created by Sun on 2023/07/29.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int sea[20][20];
int fish = 0;
int timer = 0;
int bs_size = 2;    // size of baby shark
int bs_x = 0, bs_y = 0;   // position of babyshark
int dist[20][20];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(int x, int y) {

    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> que;
    que.push({x, y});
    dist[x][y] = 0;
    
    int min_dist = (N-1)*(N-1)+1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (sea[nx][ny] > bs_size || dist[nx][ny] > 0)
                    continue;
    
                dist[nx][ny] = dist[x][y] + 1;
                
                if (1 <= sea[nx][ny] && sea[nx][ny] <= 6 && sea[nx][ny] < bs_size) {
                    if (dist[nx][ny] <= min_dist) {
                        min_dist = dist[nx][ny];
                        pq.push({nx,ny});
                        continue;
                    }   // 먹을만한 물고기를 처음 찾았을 때 같은 거리만큼에 대해서는 더 탐색하고 비교를 위해 저장
                    break;
                }
                else {
                    que.push({nx,ny});
                }
            }
        }
    }
    // 우선순위에 따라 상어가 이동할 곳
    if (!pq.empty()) {
        
        int x = pq.top().first;
        int y = pq.top().second;
        
        sea[bs_x][bs_y] = 0;    // ~ 하기전에 빈칸으로 만들기
        sea[x][y] = 9;  // 아기상어 사냥 위치로 이동 ~
        bs_x = x;
        bs_y = y;
        timer += dist[x][y];    // 이동으로 인한 시간 증가 ☆
        fish++;     // 물고기 먹은 개수 늘려주기
        if (bs_size == fish) {  // 아기 상어의 크기와 같은 수의 물고기를 먹었다면
            bs_size++;      // 무게 늘려주고
            fish = 0;       // 먹은 개수 초기화
        }
        return 0;
    }
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int state;
        for (int j = 0; j < N; j++) {
            cin >> state;
            sea[i][j] = state;
            if (state == 9) {   // starting point
                bs_x = i;
                bs_y = j;
            }
        }
    }

    while (true) {
        int val = bfs(bs_x, bs_y);
        if (val < 0)
            break;
        
        // for debugging
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++)
//            {
//                int grid = sea[i][j];
//                if (grid == 9)
//                    printf("(%d)", grid);
//                else
//                    printf(" %d ", sea[i][j]);
//            }
//            cout << endl;
//        }
//        printf("timer: %d\n", timer);
//        printf("bs_size: %d\n\n", bs_size);
    }
    cout << timer;
    
    return 0;
}
