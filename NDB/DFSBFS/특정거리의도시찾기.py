import sys
from collections import deque

input = sys.stdin.readline

N, M, K, X = input().split()

graphs = [[] for i in range(N+1)]
results = [-1] * N

for i in range(M):
    a, b = input().split()
    graphs[a].append(b)

q = deque()
q.append(X)
results[X] = 0

while q:
    node = q.popleft()
    for i in graphs[node]:
        if results[i] == -1:
            q.append(i)
            results[i] = results[node] + 1

flag = False
for i in len(results):
    if results[i] == K:
        print(i)
        flag = True
        
if flag == False:
    print("-1")