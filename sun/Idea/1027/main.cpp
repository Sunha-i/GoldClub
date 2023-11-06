//
//  main.cpp
//  1027 고층 건물
//
//  Created by Sun on 2023/11/06.
//

#include <iostream>

using namespace std;

int bldg[50];
bool view[50][50];

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> bldg[i];
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int num = 0;
        for (int j = 0; j < N; j++) {
            if (i == j)    continue;
            if (j < i)  {
                if (view[j][i])    num++;
                continue;
            }
            bool check = true;
            double slope = static_cast<double>(bldg[j] - bldg[i]) / static_cast<double>(j-i);
            
            for (int k = i+1; k < j; k++) {
                double y = slope * (k - i) + bldg[i];
                if (y <= bldg[k]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                view[i][j] = true;
                view[j][i] = true;
                num++;
            }
        }
        ans = max(ans, num);
    }
    
    cout << ans;

    return 0;
}

// 그냥 문제만 읽었을 때, 브루트포스 알고리즘으로 구현하는 방향으로는 막힐게 없어보였다
// 다른 방법이 떠오르지 않아 그냥 해보고 수정해보기로 했다.
// 근데 2->4번째를 구하는거나 4->2번째를 구하는건 같으니까... 결과를 2차원 배열에 기록하기로 함

// 지나거나 겹치는거 구현하는 방식은 두 점을 지나는 직선의 방정식을 구하고
// x 좌표를 대입해서 y 값이 더 큰지(보임) 작은지(시야 가림) 같은지(접합)로 구분했다 ~
// 구현은 어렵지 않았는데 은근히 생각할게 많았음 ;_;

// ++ 39%에서 틀려서 질문 게시판을 참고했는데 float -> double로 바꿨더니 성공함 ...
// "보통 float형은 소수점 아래 7자리까지 오차범위가 없는 편이고, double형은 소수점 아래 16자리까지 오차범위 없이 표현할 수 있다"고 함.
// 따라서 float보다는 double을 사용해야 부동소수점 오차범위를 줄일 수 있다..~

// ++ 그리고 이 문제는 CCW 알고리즘 유형이라고 했다.
// 외적을 이용해서 구할 수도 있을 것,,
