//
//  main.cpp
//  2193
//
//  Created by Sun on 2023/07/16.
//

#include <iostream>

long long d[91] = {0,};

long long pinary_num(int N) {
    if (N <= 2)
        return 1;
    if (d[N] != 0)
        return d[N];
    d[N] = pinary_num(N-1) + pinary_num(N-2);
    
    return d[N];
}

int main(int argc, const char * argv[]) {
    
    int N;
    std::cin >> N;
    
    std::cout << pinary_num(N);
    
    return 0;
}
