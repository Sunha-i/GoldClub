def insertion_sort(A):
    for i in range(1, len(A)):
        loc = i - 1
        newItem = A[i]

        while loc >= 0 and newItem < A[loc]:
            A[loc + 1] = A[loc]
            loc -= 1

        if loc + 1 != i:
            A[loc + 1] = newItem

def check_if_sorted_arrays_match(A, B):
    insertion_sort(A)
    return 1 if A == B else 0

# 입력 받기
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 결과 출력
print(check_if_sorted_arrays_match(A, B))
