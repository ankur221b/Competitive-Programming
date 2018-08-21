import random

#function for modular exponentiation
def power(a,b,mod): 
    res=1
    while b>0:
        if b%2==1:
            res=(res*a)%mod
        b//=2
        a=(a*a)%mod
    return res
 
# n - number to test
# k - number of iterations
def isprime(n,k):
    
    if n < 2: return False
    if n < 4: return True
    if n % 2 == 0: return False 
    
    d=n-1
    s=0
 
    while d%2==0:
        d//=2
        s+=1
 
    for i in range(k):
        a=random.randrange(2,n-1) #random number in [2,n-1]
        x=power(a,d,n)
 
        if x==1:continue
 
        for j in range(s):
            if x==n-1:break
            x=power(x,2,n)
        else:
            return False
    return True
    

