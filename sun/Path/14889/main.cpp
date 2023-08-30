//
//  main.cpp
//  14889
//
//  Created by Sun on 2023/08/17.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 9999999;

bool vstd[21];
int S[21][21];

vector<int> start(N/2);
vector<int> link(N/2);

void dfs(int x, int cnt) {
    
    if (cnt == N/2)
    {
        start.clear();
        link.clear();
        
        // 팀 나누기
        for (int i = 1; i < N+1; i++) {
            if (vstd[i])    start.push_back(i);
            else        link.push_back(i);
        }
        
        int strt = 0;
        int lnk = 0;
        
        // 점수 계산
        for (int i = 0; i < N/2; i++) {
            for (int j = i+1; j < N/2; j++) {
                strt += S[start[i]][start[j]] + S[start[j]][start[i]];
                lnk += S[link[i]][link[j]] + S[link[j]][link[i]];
            }
        }
        
        int gap = abs(strt - lnk);
        if (gap < ans)  ans = gap;
        
        return;
    }
    else {
        for (int i = x; i < N+1; i++) {
            if (!vstd[i]) {
                // ☆★ 재귀 구현 방식 ☆★
                vstd[i] = true;
                dfs(i+1, cnt+1);
                vstd[i] = false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < N+1; j++) {
            cin >> S[i][j];
        }
    }
    
    dfs(1, 0);
    cout << ans;
    
    return 0;
}
