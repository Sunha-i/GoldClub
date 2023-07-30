//
//  main.cpp
//  1753
//
//  Created by Sun on 2023/07/27.
//

#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int table[20001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0,start});
    table[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int vtx = pq.top().second;
        pq.pop();
        if (table[vtx] < dist)
            continue;
        for (int i = 0; i < graph[vtx].size(); i++)
        {
            int step = dist + graph[vtx][i].second;
            if (step < table[graph[vtx][i].first])
            {
                table[graph[vtx][i].first] = step;
                pq.push({-step, graph[vtx][i].first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    
    for (int i = 1; i < V+1; i++)
        table[i] = INF;
    dijkstra(K);
    
    for (int i = 1; i < V+1; i++)
    {
        if (table[i] == INF)
            cout << "INF\n";
        else
            cout << table[i] << endl;
    }
    
    return 0;
}
