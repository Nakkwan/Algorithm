G = int(input())
P = int(input())

avail = []
docking = [0] * (G + 1)
for i in range(P):
    avail.append(int(input()))

for i in range(P):
    docking[avail[i]] += 1
    if sum(docking[:avail[i] + 1]) > avail[i]:
        break
results = sum(docking) - 1
print(results)
    
# ##############
# def getParents(parent, x):
#     if parent[x] != x:
#         parent[x] = getParents(parent[x])
#     return parent[x]
# 
# def setParents(parent, x, y):
#     x = getParents(parent, x)
#     y = getParents(parent, y)
#     if x < y:
#         parent[y] = x
#     else:
#         parent[x] = y
#         
# G = int(input())
# P = int(input())
# 
# docking = [i for i in range(G + 1)]
# results = 0
# avail = []
# for i in range(P):
#     avail.append(int(input()))
# 
# for a in avail:
#     data = getParents(docking, a)
#     if data == 0:
#         break
#     setParents(docking, data, data - 1)
#     results += 1
#     
# print(results)# 