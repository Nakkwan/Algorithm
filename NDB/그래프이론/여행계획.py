import sys

def getGroups(group, x):
    if group[x] == x:
        return group[x]
    else:
        return getGroups(group, group[x])
    
def setGroups(groups, a, b):
    a = getGroups(groups, a)
    b = getGroups(groups, b)
    if a < b:
        groups[b] = a
    else:
        groups[a] = b
        
    return groups

input = sys.stdin.readline

N, M = map(int, input().split())

node = []
for i in range(N):
    node.append(list(map(int, input().split())))
    
plan = list(map(int, input().split()))

groups = [i for i in range(N + 1)]

for i in range(N):
    for j in range(N):
        if node[i][j] == 1:
            groups = setGroups(groups, i+1, j+1)

flag = "YES"
for i in range(M-1):
    if getGroups(groups, plan[i]) != getGroups(groups, plan[i+1]):
        flag = "NO"
        
print(flag)