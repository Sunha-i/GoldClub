//
//  main.cpp
//  2533
//
//  Created by Sun on 2023/08/19.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
bool vstd[1000001];
int dp[1000001][2];
vector<vector<int>> edge;

void dfs(int node) {
    vstd[node] = true;
    dp[node][0] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int child = edge[node][i];
        if (vstd[child])    continue;
        dfs(child);
        // 내가 얼리어답터라면 child가 얼리어답터든 아니든 노상관
        dp[node][0] += min(dp[child][1], dp[child][0]);
        // 내가 얼리어답터가 아니라면 child가 얼리어답터여야함
        dp[node][1] += dp[child][0];
    }
}

int main(int argc, const char * argv[]) {

    cin >> N;
    edge.resize(N+1);   // 벡터 선언 시점에서만 N+1로 하면 런타임 에러 (OutOfBounds)
    
    for (int i = 0; i < N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}
