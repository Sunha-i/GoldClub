//
//  main.cpp
//  1260 : DFS와 BFS
//
//  Created by Sun on 2023/07/26.
//

#include <iostream>
#include <algorithm>    // sort
#include <vector>
#include <queue>

bool vstd_d[1001];
bool vstd_b[1001];
std::vector<int> adjMtrx[1001];

void dfs(int vtx)
{
    vstd_d[vtx] = true;
    std::cout << vtx << " ";
    for (int i = 0; i < adjMtrx[vtx].size(); i++)
    {
        if (!vstd_d[adjMtrx[vtx][i]])
            dfs(adjMtrx[vtx][i]);
    }
}

void bfs(int vtx)
{
    std::queue<int> que;
    que.push(vtx);
    vstd_b[vtx] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        std::cout << v << " ";
        for (int i = 0; i < adjMtrx[v].size(); i++)
        {
            if (!vstd_b[adjMtrx[v][i]])
            {
                que.push(adjMtrx[v][i]);
                vstd_b[adjMtrx[v][i]] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N, M, V;
    std::cin >> N >> M >> V;
    
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        adjMtrx[v1].push_back(v2);
        adjMtrx[v2].push_back(v1);
    }
    
    // Ascending sort
    for (int i = 1; i < N+1; i++) {
        for (int j = 0; j < adjMtrx[i].size(); j++) {
            sort(adjMtrx[i].begin(), adjMtrx[i].end());
        }
    }
    
    dfs(V);
    printf("\n");
    bfs(V);
    
    return 0;
}
