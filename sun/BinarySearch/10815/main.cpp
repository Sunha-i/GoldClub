//
//  main.cpp
//  10815
//
//  Created by Sun on 2023/08/08.
//

#include <iostream>
#include <algorithm>

using namespace std;

int mycard[500001];
int answer[500001] = {0,};

int binarySearch(int* arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target) return mid;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target) end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else start = mid + 1;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> mycard[i];
    }
    sort(mycard, mycard+N);
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        
        int num;
        cin >> num;
        
        int result = binarySearch(mycard, num, 0, N-1);
        
        if (result == -1)
            answer[i] = 0;
        else
            answer[i] = 1;
    }
    
    for (int i = 0; i < M; i++)
        cout << answer[i] << " ";
    cout << "\n";
    
    return 0;
}
