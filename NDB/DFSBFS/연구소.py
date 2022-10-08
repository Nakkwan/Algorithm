dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
temp = [[0]*M for _ in range(N)]
lab = []
visited = [[0]*M for _ in range(N)]

for i in range(N):
    lab.append(list(map(int, input().split())))

results = 0

def emptySpace():
    count = 0
    for i in range(N):
        for j in range(M):
            visited[i][j] = 0
            if temp[i][j] == 0:
                count += 1
                
    return count

def findSection(x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx >= 0 and ny >= 0 and nx < N and ny < M:
            if temp[nx][ny] == 0 and visited[nx][ny] == 0:
                temp[nx][ny] = 2
                visited[nx][ny] = 1
                findSection(nx, ny)

def takeWall(num):
    global results
    if num == 3:
        for i in range(N):
            for j in range(M):
                temp[i][j] = lab[i][j]
                
        for i in range(N):
            for j in range(M):
                if temp[i][j] == 2 and visited[i][j] == 0:
                    visited[i][j] = 1
                    findSection(i, j)
        results = max(results, emptySpace())
        return 
    
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 0:
                lab[i][j] = 1
                takeWall(num+1)
                lab[i][j] = 0
                
takeWall(0)
print(results)