//
//  main.cpp
//  1992 쿼드트리
//
//  Created by Sun on 2024/02/02.
//

#include <iostream>

using namespace std;

char video[64][64];

void compress(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (video[i][j] != video[x][y]) {
                cout << "(";
                compress(x, y, size/2);
                compress(x, y+size/2, size/2);
                compress(x+size/2, y, size/2);
                compress(x+size/2, y+size/2, size/2);
                cout << ")";
                return;
            }
        }
    }
    cout << video[x][y];
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> video[i][j];
        }
    }
    compress(0, 0, N);
    
    return 0;
}
