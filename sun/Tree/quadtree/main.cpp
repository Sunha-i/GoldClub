//
//  main.cpp
//  알고스팟. 쿼드 트리 뒤집기
//
//  Created by Sun on 2024/02/02.
//

#include <iostream>

using namespace std;

int C;
string quadtree;

string reverse(string::iterator &it) {
    
    char head = *(it++);
    if (head == 'b' || head == 'w')
        return string(1, head);
    
    string topleft = reverse(it);
    string topright = reverse(it);
    string bottomleft = reverse(it);
    string bottomright = reverse(it);
    
    return "x" + bottomleft + bottomright + topleft + topright;
}

int main(int argc, const char * argv[]) {
    
    cin >> C;
    for (int x = 0; x < C; x++) {
        cin >> quadtree;
        string::iterator it = quadtree.begin();
        cout << reverse(it) << '\n';
    }
    
    return 0;
}
