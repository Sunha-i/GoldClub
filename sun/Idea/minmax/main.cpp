//
//  main.cpp
//  [PGS] 최댓값과 최솟값 만들기
//
//  Created by Sun on 2023/12/10.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    string num = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(num));
            num = "";
            continue;
        }
        num += s[i];
    }
    v.push_back(stoi(num));

    sort(v.begin(), v.end());
    answer += to_string(v.front()) + " " + to_string(v.back());

    return answer;
}

// 각 문자들을 기록 -> 공백이 나오면 string to int로 변환 후 저장 -> sort -> ..~
// 구현 자체는 쉬웠지만 string 클래스의 메소드들이 아직도 헷갈리는게 문제다.
// (나올 때마다 까먹지말고 외우기...𖤐𖤐)
