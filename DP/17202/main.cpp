//
//  main.cpp
//  17202
//
//  Created by Sun on 2023/07/12.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int A, B;
    std::cin >> A >> B;
    
    int dp[16][16] = {0,};
    
    for (int i = 7; i >= 0; i--) {
        dp[0][i*2] = A % 10;
        dp[0][i*2+1] = B % 10;
        A /= 10;
        B /= 10;
    }
    
    for (int n = 1; n < 15; n++) {
        for (int m = 0; m < 16-n; m++) {
            dp[n][m] = (dp[n-1][m] + dp[n-1][m+1]) % 10;
        }
    }
    
    std::cout << dp[14][0] << dp[14][1];
    
    return 0;
}
