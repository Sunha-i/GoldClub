//
//  main.cpp
//  13450
//
//  Created by Sun on 2023/07/27.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T, u, v;
    int edge[2];
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edge[j];
            for (int i = 0; i < edge[j]; i++)
            {
                cin >> u >> v;  // 그냥 날리기
            }
        }
        if (edge[0] == edge[1])     cout << "yes\n";
        else    cout << "no\n";
    }
    
    return 0;
}

// vertex의 개수가 최대 3개라 받은 edge 값들을 모두 사용하지 않아도 됨
// 허접한 문제..
