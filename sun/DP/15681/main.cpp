//
//  main.cpp
//  15681
//
//  Created by Sun on 2023/08/30.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int d[100001];
bool vstd[100001];
vector<vector<int>> edge;

void dfs(int node) {
    vstd[node] = true;
    d[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int child = edge[node][i];
        if (vstd[child])    continue;
        dfs(child);
        d[node] += d[child];
    }
}

int main(int argc, const char * argv[]) {
    
    /* 이 부분을 추가해주지 않으면 시간초과가 남 */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int R, Q, U, V;
    cin >> N >> R >> Q;
    edge.resize(N+1);
    
    for (int i = 0; i < N-1; i++) {
        cin >> U >> V;
        edge[U].push_back(V);
        edge[V].push_back(U);
    }
    dfs(R);
    for (int i = 0; i < Q; i++) {
        cin >> U;
        cout << d[U] << "\n";
    }
    
    return 0;
}
