n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))


def quick_sort(a):   
    p=a[0]
    r=a[n-1] 
    if p<r:
        q=partition(a,p,r)
        quick_sort(a,p,q-1)
        quick_sort(a,q+1,r)
'''
def partition(a,p,r):
    
'''
