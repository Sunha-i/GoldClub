a=input()
b=input()

len1 = len(a)
len2 = len(b)
dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

for i in range(1,len1+1):
    for j in range(1,len2+1):
        if a[i-1] == b[j-1]: #추가된 글자가 같을떄
        	dp[i][j] = dp[i - 1][j - 1] + 1 #두 문자열을 추가하기 전 최대 lcs 길이
        else:#추가된 글자가 다를때
        	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) #기존 문자열로 만들 수 있는 최대 길이 비교
        	
print(dp([-1][-1])
