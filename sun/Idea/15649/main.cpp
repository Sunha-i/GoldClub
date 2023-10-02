//
//  main.cpp
//  15649 N과 M (1)
//
//  Created by Sun on 2023/10/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> v;
vector<bool> vstd(N+1, 0);

void permutation(int dpth) {
    if (dpth == M) {
        for (int i = 0; i < M; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (vstd[i])    continue;
        vstd[i] = true;
        v.push_back(arr[i]);
        permutation(dpth + 1);
        v.pop_back();
        vstd[i] = false;
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;

    for (int i = 1; i < N+1; i++) {
        arr.push_back(i);
    }

    /* sol 1 */
    do {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        reverse(arr.begin() + M, arr.end());
    } while(next_permutation(arr.begin(), arr.end()));
    
    /* sol 2 (DFS + 재귀) */
    // permutation(0);
    
    return 0;
}

// 기본적으로 stl 라이브러리의 next_permutation을 사용하면 간단하게 nPn 순열을 구할 수 있음.
// 하지만 nPr 순열을 구하기 위해서는 next_permutation을 변형해서 사용하거나 백트래킹을 이용해 직접 구현해야 함!

// ============ next_permutation의 활용 ============
// 에 앞서 next_permutation의 작동원리부터 알아보자. 정의는 다음과 같다.
// bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);
// 순열을 구할 컨테이너(오름차순으로 정렬)의 시작과 끝 iterator를 인자로 받아, 이 순열로 더 큰 수를 만들 수 있을 때까지 수행됨
// 만약 해당 컨테이너에 다음 순열이 존재하면 true, 없으면 false를 반환함
// (이떄 다음 순열이 존재하면 그 컨테이너의 원소를 해당 순열 순서로 바꿈)
// reverse(arr.begin() + r, arr.end())를 통해 {r+1 ~ n}부분을 reverse 해줌. (12345 -> 12543)
// 그러면 '12'로 시작하는 가장 작은 수열이 '12'로 시작하는 가장 큰 수열이 됨.
// 그렇기에 다음 상태가 바로 '13'으로 시작하는 수열이 되는 것 !!!

// ============ DFS로 구현 ============
// next_permutation은 시간복잡도가 커서 N이 10~이하일 때만 사용하는 게 좋을 것.
// 재귀를 이용한 DFS 탐색 + 백트래킹으로 순열(or 조합)을 구하는 방법을 알아두자..~
// '123' 에서 '12'로 돌아가고, '124'로 가는 방식
