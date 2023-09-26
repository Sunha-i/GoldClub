//
//  main.cpp
//  2563 색종이
//
//  Created by Sun on 2023/09/26.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    scanf("%d", &N);
    
    bool paper[100][100] = {0,};
    int ans = 0;
    while (N--) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int i = x; i < x+10; i++) {
            for (int j = y; j < y+10; j++) {
                if (paper[i][j])    continue;
                paper[i][j] = true;
                ans++;
            }
        }
    }
    printf("%d", ans);
    
    return 0;
}

// 도화지 크기가 정해져있다는 걸 생각하지 못했을 때의 코드

//int main(int argc, const char * argv[]) {
//
//    int N;
//    scanf("%d", &N);
//
//    vector<vector<int>> square(N, vector<int>(2));
//
//    int xmax = 0, ymax = 0;
//    for (int xx = 0; xx < N; xx++) {
//        int x, y;
//        scanf("%d %d", &x, &y);
//
//        if (x > xmax)   xmax = x;
//        if (y > ymax)   ymax = y;
//
//        square[xx][0] = x;
//        square[xx][1] = y;
//    }
//
//    vector<vector<int>> paper(ymax+10, vector<int>(xmax+10, 0));
//
//    for (int xx = 0; xx < N; xx++) {
//        int x = square[xx][0];
//        int y = square[xx][1];
//        for (int i = y; i < y+10; i++) {
//            for (int j = x; j < x+10; j++) {
//                paper[i][j]++;
//            }
//        }
//    }
//
//    int ans = 100 * N;
//    for (int i = 0; i < ymax+10; i++) {
//        for (int j = 0; j < xmax+10; j++) {
//            if (paper[i][j] >= 2)
//                ans -= paper[i][j] - 1;
//        }
//    }
//    printf("%d", ans);
//
//    return 0;
//}
