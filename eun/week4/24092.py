import sys
input = sys.stdin.readline

def check_count():
    global count,N
    if count==N:
        print(1)
        exit()

def count_before(i):
    global A,B,count
    
    if A[i]==B[i]:
        count-=1

def count_after(i):
    global A,B,count
    
    if A[i]==B[i]:
        count+=1

def swap_array(i1,i2):
    global A
    
    count_before(i1)
    count_before(i2)
    
    A[i1],A[i2] =  A[i2],A[i1]
    
    count_after(i1)
    count_after(i2)
    
    check_count()
    
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
count = 0

for i in range(N):
    if A[i]==B[i]:
        count+=1

check_count()

left_stack=[[0,N-1]]
right_stack=[]
while left_stack or right_stack:
    if left_stack:
        p,r=left_stack.pop()
    else:
        p,r=right_stack.pop()
    
    if p>=r:
        continue
    
    x = A[r]
    i = p-1
    
    for j in range(p,r):
        if A[j] <= x:
            i+=1
            swap_array(i,j)
                    
    if i+1 != r:
        swap_array(i+1,r)

    q = i+1
    
    left_stack.append([p,q-1])
    right_stack.append([q+1,r])   

print(0)