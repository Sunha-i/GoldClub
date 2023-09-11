//
//  main.cpp
//  2667
//
//  Created by Sun on 2023/09/11.
//

#include <iostream>
#include <vector>
#include <algorithm>    //sort

using namespace std;

int N, ans = 0;
string map[25];
bool vstd[25][25] = {0,};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    
    vstd[x][y] = true;
    ans++;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (map[nx][ny] == '1' && !vstd[nx][ny])
                dfs(nx, ny);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    vector<int> block;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !vstd[i][j]) {
                dfs(i, j);
                block.push_back(ans);
                ans = 0;
            }
        }
    }
    
    cout << block.size() << endl;
    sort(block.begin(), block.end());
    for (int i = 0; i < block.size(); i++) {
        cout << block[i] << endl;
    }
    
    return 0;
}

// 이것도 아이스크림 문제
// 반례 해결하기
// -> 가 아니라 아래처럼 구현했기 때문에 25자리 숫자가 들어왔을 때 감당이 안됨
// -> 그냥 string으로 해야함
// for (int j = N-1; j >= 0; j--) {
//     int r = line % 10;
//     map[i][j] = r;
//     line /= 10;
// }
