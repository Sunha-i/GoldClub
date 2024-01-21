//
//  main.cpp
//  10819 차이를 최대로
//
//  Created by Sun on 2024/01/22.
//

#include <iostream>

using namespace std;

int N;
int arr[8];
int perm[8];
bool vstd[8];
int result = 0;

void permutation(int dpth) {
    if (dpth == N) {
        // 여기서 계산!
        int tmp = 0;
        for (int i = 0; i < N-1; i++) {
            tmp += abs(perm[i] - perm[i+1]);
        }
        result = max(result, tmp);
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (!vstd[i]) {
            perm[dpth] = arr[i];
            vstd[i] = true;
            permutation(dpth + 1);
            vstd[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    permutation(0);
    cout << result << endl;
    
    return 0;
}

// |A[0]-A[1]| + |A[1]-A[2]| + ... + |A[N-2]-A[N-1]|가 최대가 되려면...
// 특별히 규칙이 적용되는 것 같지는 않음. -> 브루트포스 & 백트래킹 -> 순열 이용!
