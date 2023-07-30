//
//  main.cpp
//  16236
//
//  Created by Sun on 2023/07/29.
//

#include <iostream>
#include <queue>

using namespace std;

int N;
int sea[20][20];
int move_cnt = 0;
int bs_size = 2;    // size of baby shark
int num_fish = 0;
bool vstd[20][20] = {0,};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void move(int x, int y)
{
    queue<pair<int,int>> que;
    que.push({x,y});
    while (num_fish == 0) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (!vstd[nx][ny] && sea[nx][ny] < bs_size) {   // 0인 경우 어떻게 처리할지
                    sea[x][y] = 0;
                    sea[nx][ny] = 0;
                    bs_size++;
                    move_cnt++;
                    num_fish--;
                    que.push({nx,ny});
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int bs_x, bs_y;   // position of babyshark
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int state;
        for (int j = 0; j < N; j++) {
            cin >> state;
            sea[i][j] = state;
            if (state == 9) {   // 아기상어 시작위치 지정
                bs_x = i;
                bs_y = j;
            }
            else if (state > 0)
                num_fish++;
        }
    }
    
    
    
    
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            cout << sea[i][j] << " ";
//        cout << endl;
//    }
    
    return 0;
}
