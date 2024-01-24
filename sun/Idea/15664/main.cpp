//
//  main.cpp
//  15664 N과 M(10)
//
//  Created by Sun on 2024/01/23.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int comb[8];

void nCm(int dpth, int idx) {
    if (dpth == M) {
        for (int i = 0; i < M; i++) {
            cout << comb[i] << " ";
        }
        cout << '\n';
    }
    
    int prev = 0;
    for (int i = idx; i < N; i++) {
        if (prev != arr[i]) {
            comb[dpth] = arr[i];
            prev = comb[dpth];
            nCm(dpth+1, i+1);
        }
    }
    // 조합일 때는 for문의 시작 조건이 현재 index or +1이니까 vstd가 의미가 없음.
    // (중복조합에 vstd를 사용하면 i=idx를 걸러버려서 그냥 조합으로 만들어버림)
    // 순열은 재귀마다 0부터 반복하면서 visted만 걸러 모든 순서 조합을 만들어줌.
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
    nCm(0, 0);
    
    return 0;
}

// 그냥 조합(nCm) 구현시
// 1 7
// 1 9
// 1 9
// 7 9
// 7 9
// 9 9
// 이렇게 중복 case가 나올 것.
// 같은 자리(dpth)에 대해 같은 값으로 새롭게 DFS를 들어가는 건 재귀적으로 어차피 같은 결과(수열)를 가져옴.
// 따라서 해당 깊이에서의 previous 값을 저장해두고 비교해서 들어가지 않도록 해야 함..!
