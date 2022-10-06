import sys
input = sys.stdin.readline

N = int(input())

def takeBig(tri, i, j):
    global load
    if load[i][j] != 0:
        return load[i][j]
    if i == N - 1:
        load[i][j] = tri[i][j]
        return tri[i][j]
    
    if load[i+1][j] != 0:
        left = load[i+1][j]
    else:
        left = takeBig(tri, i+1, j)
    
    if load[i+1][j+1] != 0:
        right = load[i+1][j+1]
    else:
        right = takeBig(tri, i+1, j+1)
        
        load[i][j] = tri[i][j] + max(left, right)
    return load[i][j]


tri = []
load = []
for i in range(N):
    tri.append(list(map(int, input().split())))
    load.append([0] * (i + 1))
    
results = takeBig(tri, 0, 0)
print(results)