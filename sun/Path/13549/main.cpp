//
//  main.cpp
//  13549
//
//  Created by Sun on 2023/07/27.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

#define INF 1e9

using namespace std;

int N, K;
bool vstd[100001] = {0,};

int tmp;
int p = 1;

int dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    vstd[start] = true;
    
    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (now == K)   // 동생 찾음
            return time;
        
        if (now * 2 <= 100000 && !vstd[now * 2])
        {
            pq.push({time, now * 2});
            vstd[now * 2] = true;
        }
        if (now + 1 <= 100000 && !vstd[now + 1])
        {
            pq.push({time + 1, now + 1});
            vstd[now + 1] = true;
        }
        if (now - 1 >= 0 && !vstd[now -1])
        {
            pq.push({time + 1, now - 1});
            vstd[now - 1] = true;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    std::cin >> N >> K;
    
    cout << dijkstra(N);
    
    return 0;
}
