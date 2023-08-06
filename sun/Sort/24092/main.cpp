//
//  main.cpp
//  24092
//
//  Created by Sun on 2023/08/06.
//

#include <iostream>

using namespace std;

int N;
int ans = 0;

int tmp(int* A, int* B, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            swap(A[++i], A[j]);
            if (std::equal(A, A+N, B)) {
                ans = 1;
                return -1;
            }
        }
    }
    if (i+1 != r) {
        swap(A[i+1], A[r]);
        if (std::equal(A, A+N, B)) {
            ans = 1;
            return -1;
        }
    }
    return i+1;
}

void quickSort(int* A, int* B, int p, int r)
{
    if (p < r) {
        int q = tmp(A, B, p, r);
        if (q < 0)
            return;
        quickSort(A, B, p, q-1);
        quickSort(A, B, q+1, r);
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    int* A = new int[N];
    int* B = new int[N];
    
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    
    quickSort(A, B, 0, N-1);
    cout << ans;
    
    delete[] A;
    delete[] B;
    
    return 0;
}
