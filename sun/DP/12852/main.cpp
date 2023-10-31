//
//  main.cpp
//  12852 1로 만들기 2
//
//  Created by Sun on 2023/11/01.
//

#include <iostream>
#include <vector>

using namespace std;

int d[1000001] = {0,};
int cnnt[1000001];

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i = 2; i <= N; i++) {
        d[i] = d[i-1] + 1;
        cnnt[i] = i-1;
        
        if (i % 2 == 0 && d[i/2] + 1 < d[i]) {
            d[i] = d[i/2] + 1;
            cnnt[i] = i/2;
        }
        if (i % 3 == 0 && d[i/3] + 1 < d[i]) {
            d[i] = d[i/3] + 1;
            cnnt[i] = i/3;
        }
    }

    cout << d[N] << endl;
    
    int idx = N;
    while (true) {
        cout << idx << " ";
        if (idx == 1)   break;
        idx = cnnt[idx];
    }
    
    return 0;
}

// [1로 만들기]라는 유형 자체는 익숙해서 쉽게 점화식 d[i] = min(d[i/3], d[i/2], d[i-1]) + 1을 떠올렸지만,
// 오히려 경로를 추적하는 부분이 은근히 어려웠다. (순서 출력)
// 암튼 그 숫자가 순서상 어느 숫자에 연결되는지를 기록해두는 cnnt 배열을 이용해 해결함!
// 예) 10은 9에 연결, 9는 3에 연결, 3은 1 ...
