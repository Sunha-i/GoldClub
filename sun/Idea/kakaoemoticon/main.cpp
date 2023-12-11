//
//  main.cpp
//  [PGS] 이모티콘 할인행사
//
//  Created by Sun on 2023/12/11.
//

#include <string>
#include <vector>

using namespace std;

int sale[4] = {10,20,30,40};

vector<int> ans(2,0);
vector<int> P;    // permutation

void dfs(int cnt, vector<vector<int>> users, vector<int> emoticons)
{
    if(cnt == emoticons.size()) {
        int sub = 0;        // 구독자수
        int sum = 0;        // 이모티콘 판매액
        for (int i = 0; i < users.size(); i++) {
            int cost = 0;
            for (int j = 0; j < emoticons.size(); j++) {
                if (P[j] >= users[i][0]) {
                    cost += emoticons[j] * (100.0 - P[j]) / 100.0;
                }
            }
            if (cost >= users[i][1])    sub++;      // 이모티콘 플러스 서비스에 가입하는 경우
            else        sum += cost;                // 그냥 이모티콘 구매
        }

        if (sub > ans[0]) {     // 구독자수가 우선순위 !!!
            ans[0] = sub;
            ans[1] = sum;
        }
        else if (sub == ans[0] && sum > ans[1]) {   // 두번째로 판매액도 최대로..~
            ans[1] = sum;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        P.push_back(sale[i]);
        dfs(cnt+1, users, emoticons);
        P.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    dfs(0, users, emoticons);

    answer.push_back(ans[0]);
    answer.push_back(ans[1]);

    return answer;
}

// 완전 탐색 말고는 방법이 떠오르지 않았다. 경우의 수는 최대 100 * 4^7로 160만 정도이고,
// 4^7이라는 중복순열을 구현해주기 위해 dfs를 사용했삼. 연산횟수에 따라 완탐을 사용해도 된다는 확신과
// 중복순열 구현법만 떠올린다면 쉽게 구현할 수 있는 문제였음.
// (중복)순열, (중복)조합 이 4가지 구현을 안보고 구현할 정도로 외우지 못해서 빠른 시일내로 정리할 예정.
