def calcDistance(distance, N):
    for i in range(1, N+1):
        for a in range(1, N+1):
            for b in range(1, N+1):
                distance[a][b] = min(distance[a][i] + distance[i][b], distance[a][b])
                    
    return distance

N = int(input())
M = int(input())

distance = [[int(1e9)] * (N+1) for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(1, N+1):
        if i == j:
            distance[i][j] = 0
            
for i in range(M):
    a, b, c  = map(int, input().split())
    if c < distance[a][b]:
        distance[a][b] = c
        
distance = calcDistance(distance, N)

for i in range(1, len(distance)):
    for j in range(1, len(distance)):   
        if distance[i][j] == int(1e9):
            print(0, end=' ')
        else:     
            print(distance[i][j], end=' ')
    print()