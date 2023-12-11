//
//  main.cpp
//  [BOJ] 트리의 지름
//
//  Created by Sun on 2023/12/12.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, y;
int result = 0;
vector<pair<int,int>> node[10001];
bool vstd[10001] = {0,};

void dfs(int n, int d) {
    vstd[n] = true;
    
    if (d > result) {
        result = d;
        y = n;
    }
    
    for (int i = 0; i < node[n].size(); i++) {
        int cnnt = node[n][i].first;
        if (!vstd[cnnt]) {
            dfs(cnnt, d + node[n][i].second);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    
    for (int i = 0; i < n-1; i++) {
        int p, c, v;
        cin >> p >> c >> v;
        
        node[p].push_back({c,v});
        node[c].push_back({p,v});
    }
    
    dfs(1, 0);
    memset(vstd, false, sizeof(vstd));
    dfs(y, 0);
    cout << result;
    
    return 0;
}

// 처음에 binary tree인 줄 알고 나름의 독특한 방법으로 풀었는데 아니었음.
// 트리의 지름을 구하는 방법을 직접 알아내진 못했고 찾아본담에 이해했다.n
// -----------------------------------
// 1) 임의의 정점 x에서 가장 먼 정점 y 찾기
// 2) 정점 y에서 가장 먼 정점 z 찾기
// 3) 트리의 지름은 정점 y와 z를 연결하는 경로
// -----------------------------------
// 위 결론이 성립한다는 것은 정점 y가 반드시 트리의 지름에 포함된다는 것이기에
// "정점 y가 트리의 지름에 포함되지 않는다."라는 이 명제가 모순임을 증명하는 방법도 있지만..
// 간단하게 원을 생각해보자.
// (정확히는 문제에서 제시한 것처럼 원 안에 트리를 펼쳐놓은 그림처럼 모든 답을 아는 모든 것의 신이 그려놓은 정답이 이미 정해져있다고 생각하면 됨)
// 정점 x가 우연히 원주 위의 점(지름의 양 끝점 중 하나)이었다면 당연히 그로부터 가장 먼 점 y는
// 지름의 양 끝을 이루는 저 반대편 점이 될 것이다. (이건 이미 3번의 결론을 낼 때 자명하다고 판단한 부분)
// 그리고 만약 원의 중심 어딘가의 한 점이었다면 그 또한 가장 먼 점을 찾아볼 때 결국 지름의 양 끝에 있는 두 점 중 하나로 향하게 될 것!!
// 이라는 게 중요한데.. 왜냐면 그렇지 않은 경우가 없음.
// 원의 중심 어딘가의 한 점에서 가장 먼 점이 지름이 아닌 원의 중심 어딘가에 있는 또 다른 점일 수도 있지 않는가?
// 라는 질문이 틀릴 수밖에 없는 이유는 이미 답은 정해져있기 때문이다.
// 신이 만들어놓은 답이 팩트이기에 만약 그런 점이 있다면 진즉에 그게 그 답이 되었을 것이라는 것.. (파란색 점)
//
// 나름의 방법으로 증명해 봤지만 결국은 위 명제가 모순임을 증명하는 방법이 되었다..~
// +) 암튼 가장 먼 정점을 찾는 방법으로는 dfs를 사용했음
// ++) memset은 <cstring>을 include 해줘야 한다
