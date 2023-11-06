//
//  main.cpp
//  20920 영단어 암기는 괴로워
//
//  Created by Sun on 2023/11/07.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool compare(const pair<int, string> &a, const pair<int, string> &b)
{
    if (a.first == b.first)     // first 값이 같으면서
    {
        if (a.second.length() == b.second.length())     // 단어의 길이도 같으면
        {
            return a.second < b.second;     // second 값이 더 작은게 앞으로 ~ (<: 오름차순)
        }
        return a.second.length() > b.second.length();   // 다를 땐 길이순 (>: 내림차순)
    }
    return a.first > b.first;   // first 값이 다르면 더 큰 값이 앞으로 가도록 (>: 내림차순)
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    map<string, int> m;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.length() < M)  continue;
        m[word]++;      // map에 저장
    }
    
    vector<pair<int, string>> dict;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        dict.push_back({iter->second, iter->first});
    }
    
    sort(dict.begin(), dict.end(), compare);
    
    for (int i = 0; i < dict.size(); i++) {
        cout << dict[i].second << "\n";
    }

    return 0;
}

// key와 value를 쌍으로 갖는 Map은 처음 사용해본듯...(STL 라이브러리)
// map 각 원소에 접근하려면 for (auto iter : m)으로 iter.first ~ 이런식으로 하던가
// for (auto iter = m.begin(); iter != m.end(); iter++) ~ 이때는 iter->first 이렇게!

// compare 함수에서 (<: 오름차순, >: 내림차순)인 것은 두 개의 데이터를 비교할 때,
// 왼쪽 or 오른쪽에 있는 것이 더 크도록 정렬하겠다 ~는 뜻임.

// map 자료구조랑 vector sort시 사용하는 compare 인자 알아두기.
// ++ sort -> <algorithm> 헤더 불러오기!!!

// cin.tie(NULL): 묶여있는 cin-cout을 끊어주는 역할. 출력 버퍼를 비우는 작업을 매번 수행하지 않도록.
// ios_base::sync_with_stdio(false): c의 stdio와 c++의 iostream의 동기화를 비활성화 (c와 c++가 동일한 버퍼를 공유해 딜레이 발생)
// endl: 개행 + flush의 역할로 출력 버퍼를 비우는 데에 시간을 많이 잡아먹음 -> '\n' 사용
