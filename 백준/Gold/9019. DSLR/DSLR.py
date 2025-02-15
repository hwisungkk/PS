import sys
from collections import deque

def bfs(A, B):
    queue = deque([(A, [])])
    visited = [0]*10000
    visited[A]=1

    while queue:
        num, path = queue.popleft()
        
        if num == B:
            return ''.join(path)
        
        for op, next_num in [
            ("D", (2 * num) % 10000), 
            ("S", 9999 if num == 0 else num - 1), 
            ("L", (num % 1000) * 10 + num // 1000), 
            ("R", (num % 10) * 1000 + num // 10)
        ]:
            if visited[next_num] == 0:
                visited[next_num] = 1
                queue.append((next_num, path + [op]))
    return ""

if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for _ in range(T):
        A, B = map(int, sys.stdin.readline().strip().split())
        print(bfs(A, B))
