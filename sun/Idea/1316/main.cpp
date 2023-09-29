//
//  main.cpp
//  1316 그룹 단어 체커
//
//  Created by Sun on 2023/09/28.
//

#include <iostream>
#include <cstring>

#define NUM 26

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    bool alphabet[NUM] = {0,};

    int ans = N;
    for (int x = 0; x < N; x++) {
        string word;
        cin >> word;
        
        for (int i = 0; i < word.length(); i++) {
            if (alphabet[int(word[i]) - 97]) {
                ans--;
                break;
            }
            if (word[i] == word[i+1])   continue;
            alphabet[int(word[i]) - 97] = true;
        }
        memset(alphabet, 0, NUM);
    }
    cout << ans << endl;
    
    return 0;
}
