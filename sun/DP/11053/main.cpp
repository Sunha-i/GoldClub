//
//  main.cpp
//  11053
//
//  Created by Sun on 2023/09/04.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    int A[1000];
    int dp[1000] = { 0, };

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
