//
//  main.cpp
//  2156
//
//  Created by Sun on 2023/07/20.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int n, g;
    std::cin >> n;
    
    int* D = new int[n]();
    int* ND = new int[n]();
    int* arr = new int[n]();
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> g;
        arr[i] = g;
        
        if (i == 0) {
            D[i] = arr[i];
            continue;
        }
        if (i == 1) {
            D[i] = arr[0] + arr[1];
            ND[i] = std::max(D[i-1], ND[i-1]);
            continue;
        }
        D[i] = std::max(ND[i-1], ND[i-2] + arr[i-1]) + arr[i];
        ND[i] = std::max(D[i-1], ND[i-1]);
    }
    std::cout << std::max(D[n-1], ND[n-1]);
    
    delete[] D;
    delete[] ND;
    delete[] arr;
    
    return 0;
}
