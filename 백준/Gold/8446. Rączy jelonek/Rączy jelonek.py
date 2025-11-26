n = int(input())
ans = 1
if n%2==0:
    n-=1
    ans+=2

while n>=1:
    n//=2
    ans+=2

print(ans)