//
//  main.cpp
//  17213 과일 서리
//
//  Created by Sun on 2024/01/24.
//

#include <iostream>

using namespace std;

int N, M;
int result = 0;

void nHm(int dpth, int idx) {
    if (dpth == M-N) {
        result++;
        return;
    }
    
    for (int i = idx; i < N; i++) {
        nHm(dpth+1, i);
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    nHm(0, 0);
    cout << result << endl;
    
    return 0;
}

// 중복조합, nHm 구현. (nCm과 동일한데 반복문의 시작값을 이전에 선택한 값으로만 선택)
// 모든 종류의 과일을 적어도 1개 훔쳐야 하니까,.. 하나씩 킵했다고 생각하면서 M-N개 골라주면 됨.
// 사실상 nHm-n.
