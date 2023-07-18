//
//  main.cpp
//  2775
//
//  Created by Sun on 2023/07/12.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int T, k, n;
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        std::cin >> k >> n;
        
        int dp[15][15] = {0,};
        
        for (int j = 1; j < n+1; j++) {
            dp[0][j] = j;
            
        }
        for (int a = 1; a < k+1; a++) {
            for (int b = 1; b < n+1; b++) {
                for (int c = 1; c < b+1; c++) {
                    dp[a][b] += dp[a-1][c];
                }
            }
        }
        std::cout << dp[k][n] << std::endl;
    }
    
    return 0;
}
