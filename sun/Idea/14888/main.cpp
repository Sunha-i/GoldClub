//
//  main.cpp
//  14888 연산자 끼워넣기
//
//  Created by Sun on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int rmax = -1e9;
int rmin = 1e9;

int num[11];
int oper[4];    // + - × ÷
vector<int> opera;

void backtracking(int val, int dpth) {
    if (dpth == N-1) {
        rmax = max(rmax, val);
        rmin = min(rmin, val);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (oper[i] == 0)   continue;
        oper[i]--;
        if (i == 0) {
            backtracking(val + num[dpth+1], dpth + 1);
        } else if (i == 1) {
            backtracking(val - num[dpth+1], dpth + 1);
        } else if (i == 2) {
            backtracking(val * num[dpth+1], dpth + 1);
        } else if (i == 3) {
            backtracking(val / num[dpth+1], dpth + 1);
        }
        oper[i]++;
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> num[i];
        
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
        for (int j = 0; j < oper[i]; j++) {
            opera.push_back(i);
        }
    }
    
    /* sol 1 */
    do {
        int tmp = num[0];
        for(int i = 0; i < opera.size(); i++)
        {
            switch (opera[i]) {
                case 0: tmp += num[i+1];  break;
                case 1: tmp -= num[i+1];  break;
                case 2: tmp *= num[i+1];  break;
                case 3: tmp /= num[i+1];  break;
                default:    break;
            }
        }
        rmax = max(rmax, tmp);
        rmin = min(rmin, tmp);

    } while(next_permutation(opera.begin(), opera.end()));
    
    /* sol 2 */
    // backtracking(num[0], 0);
    
    cout << rmax << "\n" << rmin;
    
    return 0;
}

// 모든 연산 순열을 하나씩 확인하는 완탐의 경우에도 11!로 문제 해결이 가능하지만
// 백트래킹으로 더 단축시킬 수 있을 것
