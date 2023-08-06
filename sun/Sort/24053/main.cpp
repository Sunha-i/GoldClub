//
//  main.cpp
//  24053
//
//  Created by Sun on 2023/08/06.
//

#include <iostream>
#include <vector>

int insertionSort(int N, int* A, int* B) {
    for (int i = 1; i < N; i++) {
        int loc = i - 1;
        int newItem = A[i];
        while (0 <= loc && newItem < A[loc]) {
            A[loc + 1] = A[loc];
            loc--;
            if (std::equal(A, A+N, B))
                return 1;
        }
        if (loc + 1 != i) {
            A[loc + 1] = newItem;
            if (std::equal(A, A+N, B))
                return 1;
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int N;
    std::cin >> N;
    
    int* A = new int[N];
    int* B = new int[N];

    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    for (int i = 0; i < N; i++)
        std::cin >> B[i];
    
    // insertion sort
    std::cout << insertionSort(N, A, B);
    
    delete[] A;
    delete[] B;
    
    return 0;
}
