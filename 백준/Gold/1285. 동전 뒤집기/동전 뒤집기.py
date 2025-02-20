n = int(input())
c = [list(input()) for _ in range(n)]
ans = 10000000

for bit in range(1 << n):
    tmp = [c[i][:] for i in range(n)]
    for i in range(n):
        if bit & (1 << i):
            for j in range(n):
                if tmp[i][j] == 'H':
                    tmp[i][j] = 'T'
                else:
                    tmp[i][j] = 'H'

    total = 0
    for i in range(n):
        count = 0
        for j in range(n):
            if tmp[j][i] == 'T':
                count += 1
        total += min(count, n - count)
    ans = min(ans, total)

print(ans)
