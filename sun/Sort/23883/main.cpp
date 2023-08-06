//
//  main.cpp
//  23883
//
//  Created by Sun on 2023/08/06.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    // selection sort
    for (int i = N-1; i > 0; i--) {
        int swap_idx = N;
        int max_idx = i;
        for (int j = 0; j < max_idx; j++) {
            if (A[max_idx] < A[j]) {
                std::swap(A[max_idx], A[j]);
                swap_idx = j;
            }
        }
        if (swap_idx != N) {
            K--;
            if (K == 0) {
                printf("%d %d", A[swap_idx], A[max_idx]);
                return 0;
            }
        }
    }
    printf("%d", -1);
    
    return 0;
}
