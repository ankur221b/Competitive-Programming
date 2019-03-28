n = int(input())
s = input()

maxi,start = 1,0

dp = [ [ False for j in range(n)] for i in range(n) ]

for i in range(n):
    dp[i][i]=True

for i in range(n-1):
    if s[i]==s[i+1]:
        dp[i][i+1]=True
        start=i
        maxi=2

for l in range(3,n+1):
    for st in range(n-l+1):
        end = st+l-1

        if dp[st+1][end-1]==True and s[st]==s[end] :
            dp[st][end]=True

            if l > maxi:
                start=st
                maxi=l

        
print(maxi)
print( s[start:start+maxi])
