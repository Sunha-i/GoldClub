//
//  main.cpp
//  11049 행렬 곱셈 순서
//
//  Created by Sun on 2023/11/16.
//

#include <iostream>

#define INF 1e9

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    pair<int,int> nxm[501][501];
    int d[501][501];
    
    for (int i = 0; i < N; i++) {
        cin >> nxm[i][i].first >> nxm[i][i].second;
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N-i; j++) {
            nxm[j][i+j].first = nxm[j][i+j-1].first;
            nxm[j][i+j].second = nxm[j+i][i+j].second;

            d[j][i+j] = INF;
            for (int k = 1; k < i+1; k++) {
                d[j][i+j] = min(d[j][i+j], d[j][i+j-k] + d[j+i+1-k][i+j]
                                + nxm[j][i+j-k].first * nxm[j][i+j-k].second * nxm[j+i+1-k][i+j].second);
            }
        }
    }
    cout << d[0][N-1];
    
    return 0;
}

// 5
// 5 3
// 3 2
// 2 6
// 6 2
// 2 4

// 위 경우 nxm 배열은 이렇게 채워지고,
// (5,3)(5,2)(5,6)(5,2)(5,4)
// (0,0)(3,2)(3,6)(3,2)(3,4)
// (0,0)(0,0)(2,6)(2,2)(2,4)
// (0,0)(0,0)(0,0)(6,2)(6,4)
// (0,0)(0,0)(0,0)(0,0)(2,4)

// A AB ABC ABCD ABCDE
//    B  BC  BCD  BCDE
//        C   CD   CDE
//             D    DE
//                   E
// dp table은 위와 같이 구성. A->B->C->...->AB->BC->...->ABC->... 순서로 값을 계산할 것
// ABCD의 경우 min(A(BCD), (AB)(CD), (ABC)D)인데, dp 배열에서 A(d[0][0]), BCD(d[1][3])의 값을 더해주면서
// A(5x3)랑 BCD(3x2)를 연산하는 횟수도 추가로 더해줘야 함. (5*3*2)
// ++) 여기서 하나 A,B,C와 같은 연산 전 행렬의 d 값은 0이 되어야 하는데 dp = min(dp, ~) 이런식으로 식을 쓰려면..
// 따로 반복문 내 min 값을 구해서 넣어주거나, 반복문에 들어가기 직전에 해당값을 INF로 바꿔주면 됨.

// result d
// 0  30 90 66 106
// 0  0  36 36 60
// 0  0  0  24 40
// 0  0  0  0  48
// 0  0  0  0  0

// 힌트 없이 풀었지만, 생각을 좀 더 빠르게 정리하는 연습을 할 것
// 집중해서 풀기
