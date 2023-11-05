//
//  main.cpp
//  1522 문자열 교환
//
//  Created by Sun on 2023/11/05.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    cin >> s;
    
    const int LEN = s.length();
    
    int nA = 0;
    for (int i = 0; i < LEN; i++) {
        if (s[i] == 'a')    nA++;
    }
    
    int ans = LEN;
    for (int i = 0; i < LEN; i++) {
        int ex = 0;
        for (int j = 0; j < nA; j++) {
            if (s[(i+j) % LEN] == 'b')  ex++;
        }
        ans = min(ans, ex);
    }
    cout << ans;
    
    return 0;
}

// 처음엔 circular queue라도 구현해서 해야하나... 싶었는데
// 다음의 방법을 떠올리고 나선 문제가 꽤나 간단해졌다.
// abababababababa -> ax8, bx7
// (abababab)abababa
// a(babababa)bababa
// ...
// abababa(babababa)
//
// 어차피 () 안은 a의 개수를 기준으로 했다면 a로 채워져야 한다.
// 즉 괄호 내 b의 개수가 교환 횟수가 되는 것.
// 괄호가 )( 이렇게 되는 부분은 )( 나머지 연산을 이용해 이러한 괄호까지 고려해주거나 -> 이게 더 간단할 듯
// 애초에 괄호 안에 들어가는 개수를 두 가지 경우로 나눠서 생각해볼 수 있음 -> nA, nB을 둘 다 고려하는 것
// ++
// a or b 둘 중 하나를 기준으로 해도 됨.
// 알아보니 슬라이딩 윈도우? 라는 알고리즘이라고 함
