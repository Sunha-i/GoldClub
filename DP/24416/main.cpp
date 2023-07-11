//
//  main.cpp
//  24416
//
//  Created by Sun on 2023/07/12.
//

#include <iostream>

int f[40] = {0,};
int count = 0;

int fib(int n);
int fibonacci(int n);

int main(int argc, const char * argv[]) {
    
    int n;
    std::cin >> n;
    
    fib(n);
    std::cout << count << " " << fibonacci(n);
    
    return 0;
}

// recursive (no memoization)
int fib(int n) {
    if (n == 1 or n == 2) {
        count++;
        return 1;
    }
    else
        return fib(n-1) + fib(n-2);
}

// DP
int fibonacci(int n) {
    f[1] = 1;
    f[2] = 1;
    int cnt = 0;
    for (int i = 3; i < n+1; i++) {
        f[i] = f[i-1] + f[i-2];
        cnt++;
    }
    return cnt;
}
