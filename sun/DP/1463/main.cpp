//
//  main.cpp
//  1463
//
//  Created by Sun on 2023/07/16.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int N;
    std::cin >> N;
    
    int dp[1000001] = {0,};
    
    dp[1] = 0;
    
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 3 == 0)
            dp[i] = std::min(dp[i], dp[i/3] + 1);
        if (i % 2 == 0)
            dp[i] = std::min(dp[i], dp[i/2] + 1);
    }
    
    std::cout << dp[N];
    
    return 0;
}
