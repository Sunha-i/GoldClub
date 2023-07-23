//
//  main.cpp
//  9251
//
//  Created by Sun on 2023/07/23.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    int dp[1000];
    
    std::string str1, str2;
    std::cin >> str1 >> str2;

    std::vector<std::vector<int>> LCS(6);
    
    // str1을 기준으로 str2에 대응하는 인덱스를 2차원 벡터에 넣어서..~
    
    for (int i = 0; i < LCS.size(); i++) {
        if (!LCS[i].empty())
        {
            // 여기서 이제 dp...
        }
    }
    
    return 0;
}
