//
//  main.cpp
//  2208
//
//  Created by Sun on 2023/08/29.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    int* v = new int[N];
    int* d = new int[N+1]();
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for (int i = N-M; i >= 0; i--) {
        int tmp = 0;
        for (int j = 0; j < M; j++) {
            tmp += v[i+j];
        }
        if (i == N-M)
            d[i] = tmp;
        else
            d[i] = max(d[i+1]+v[i], tmp);
    }
    
    int ans = d[0];
    for (int i = 1; i < N; i++) {
        ans = max(ans, d[i]);
    }
    if (ans < 0)
        printf("%d", 0);
    else    // 보석을 안가지고 나가는게 더 이득이라면 그래야함^
        printf("%d", ans);
    
    delete[] v;
    delete[] d;
    
    return 0;
}

// 95%에서 fail -> 해결
