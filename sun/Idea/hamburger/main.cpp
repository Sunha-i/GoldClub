//
//  main.cpp
//  [PGS] 햄버거 만들기
//
//  Created by Sun on 2023/12/10.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    string sequence = "";
    for (int i = 0; i < ingredient.size(); i++) {
        sequence += to_string(ingredient[i]);
        int len = sequence.length();
        if (len >= 4) {
            if (sequence.substr(len - 4) == "1231") {
                sequence.erase(len - 4);
                answer++;
            }
        }
    }

    return answer;
}

// 구현 방법에는 여러가지가 있겠지만 핵심은 맨 끝의 4자리만 계속해서 검사하도록 하는 것.
// 이를 위해 stack의 구조만 만들어주면 되고, 나는 "1231"을 찾는 부분에서
// 나름 코드를 간단하게 하기 위해 string으로의 변환을 사용해씀 !!
