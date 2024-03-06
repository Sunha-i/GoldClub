//
//  main.cpp
//  2606 바이러스
//
//  Created by Sun on 2024/03/05.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> cnnt(101);
bool infected[101];
int cnt = 0;

void dfs(int node) {
    infected[node] = true;
    for (int i = 0; i < cnnt[node].size(); i++) {
        int nn = cnnt[node][i];
        if (!infected[nn]) {
            dfs(nn);
            cnt++;
        }
    }
}

void bfs(int node) {
    
    queue<int> q;
    q.push(node);
    infected[node] = true;
    
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i = 0; i < cnnt[n].size(); i++) {
            int nn = cnnt[n][i];
            if (!infected[nn]) {
                q.push(nn);
                infected[nn] = true;
                cnt++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        cnnt[n1].push_back(n2);
        cnnt[n2].push_back(n1);
    }
    
    dfs(1);     // or bfs(1)
    cout << cnt;
    
    return 0;
}

// 그냥 간단한 bfsdfs 문제!
