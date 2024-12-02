a = int(input())

for _ in range(a):
    b = int(input())
    x = len(str(b))
    ans = False
    for i in range(1, 10):
        c = b - int(str(i) * x)
        if c > 0:
            p = str(c)
            if p == (p[0]) * len(p):
                print(str(i) * x, end=' ')
                print(c)
                ans = True
                break
    if ans==False:
        x = len(str(b))-1
        ans = False
        for i in range(1, 10):
            c = b - int(str(i) * x)
            p = str(c)
            if p == (p[0]) * len(p):
                print(str(i) * x, end=' ')
                print(c)
                break
        
