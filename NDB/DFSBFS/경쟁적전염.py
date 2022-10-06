import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())
experiments = []
info = []
for i in range(N):
    experiments.append(list(map(int, input().split())))
    for j in range(N):
        if experiments[i][j] != 0:
            info.append((experiments[i][j], 0, i, j))

info.sort()
q = deque(info)

S, X, Y = map(int, input().split())
    
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

while q:
    v, s, y, x = q.popleft()
    
    if s == S:
        break
    
    for i in range(4):
        yy = y + dy[i]
        xx = x + dx[i]
        if yy < N and yy >= 0 and xx < N and xx >= 0:
            if experiments[yy][xx] == 0:
                experiments[yy][xx] = v
                q.append((v, s+1, yy, xx))
 
print(experiments[X - 1][Y - 1]) 
           
    
    
    