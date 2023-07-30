//
//  main.cpp
//  1504
//
//  Created by Sun on 2023/07/29.
//

#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int, int> > graph[801];
int d[801];

int dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first;     // 현재 노드까지의 비용
        int now = pq.top().second;      // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist)
        {
            if (now == end)
                return d[now];
            else
                continue;
        }
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
    if (d[end] == INF)
        return -1;
    else
        return d[end];
}


int main(int argc, const char * argv[]) {

    int N, E;
    cin >> N >> E;
    
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    
    int path[2][4] =
    {
        {1, v1, v2, N},
        {1, v2, v1, N}
    };
    int ans[2] = {0,};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fill(d, d + 801, INF);
            int tmp = dijkstra(path[i][j], path[i][j+1]);
            if (tmp == -1) {
                ans[i] = tmp;
                break;
            }
            ans[i] += tmp;
        }
    }
    if (min(ans[0], ans[1]) != -1)
        cout << min(ans[0], ans[1]);
    else if (ans[0] == -1 && ans[1] == -1)
        cout << max(ans[0], ans[1]);
    
    return 0;
}
