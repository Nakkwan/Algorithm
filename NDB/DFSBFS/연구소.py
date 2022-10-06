import sys
from copy import deepcopy
from collections import deque

input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())

lab = []
for i in range(N):
    lab.append(list(map(int, input().split())))


def emptySpace(lab_copy):
    count = 0
    for i in range(N):
        for j in range(M):
            if lab_copy[i][j] == 0:
                count += 1
                
    return count

def findSection(lab_copy):
    q = deque()
    for i in range(N):
        for j in range(M):
            if lab_copy[i][j] == 2:
                q.append((i, j))
                
                while q:
                    current = q.pop()
                    for k in range(4):
                        x = current[0] + dx[k]
                        y = current[1] + dy[k]
                        if x < 0 or y < 0 or x > M-1 or y > N-1:
                            continue
                        if lab_copy[x][y] == 0:
                            q.append((x, y))
                            lab_copy[x][y] = 2
                            
    result = emptySpace(lab_copy)
    return result

def takeWall(num):
    global results
    if num == 3:
        lab_copy = deepcopy(lab)
        result = findSection(lab_copy)
        results = max(result, results)
        return 
    
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 0:
                lab[i][j] = 1
                takeWall(num+1)
                lab[i][j] = 0

results = 0
takeWall(0)
print(results)