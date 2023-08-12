//
//  main.cpp
//  1756
//
//  Created by Sun on 2023/08/08.
//

#include <iostream>

using namespace std;

int binarySearch(int* arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 오른쪽 확인
        if (arr[mid] >= target) start = mid + 1;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 오른쪽 확인
        else end = mid - 1;
    }
    return end;
}

int main(int argc, const char * argv[]) {

    int D, N;
    cin >> D >> N;
    
    int* oven = new int[D+1];
    
    for (int i = 1; i < D+1; i++)
    {
        int tmp;
        cin >> tmp;
        if (i == 1) {
            oven[i] = tmp;
            continue;
        }
        if (tmp > oven[i-1])
            oven[i] = oven[i-1];
        else
            oven[i] = tmp;
    }
    
    int result = D;
    int myend = D;
    for (int i = 0; i < N; i++)
    {
        int pzza;
        cin >> pzza;
        
        result = binarySearch(oven, pzza, 1, myend);
        myend = result - 1;
    }
    if (result < 0)
        cout << 0;
    else
        cout << result;
    
    delete[] oven;
    
    return 0;
}

// 시간초과
//    for (int i = 0; i < N; i++)
//    {
//        int pzza;
//        cin >> pzza;
//
//        // 현재 들어온 피자 크기가 오븐에서 걸리는 부분 찾기
//        for (int j = 1; j < D+1; j++) {
//            if (oven[j] < pzza) {
//                D = j-1;
//                break;
//            }
//        }
//        if (i == N-1)
//            printf("%d", D);
//        D--;
//    }
