import sys
import numpy as np
input = sys.stdin.readline


dx = [1, 1, 1]
dy = [-1, 0, 1]
def getScores(map, gold_map, n, m):
    N, M = gold_map.shape
    if m == M - 1:
        gold_map[n][m] = map[n][m]
        return gold_map
        
    score = 0
    for i in range(len(dx)):
        x = m + dx[i]
        y = n + dy[i]
        if x > -1 and y > -1 and x < M and y < N:
            if gold_map[y][x] == -1:
                gold_map = getScores(map, gold_map, y, x)
            score = max(gold_map[y][x], score)
    
    gold_map[n][m] = map[n][m] + score
    
    if n < N - 1:
        gold_map = getScores(map, gold_map, n + 1, m)
    
    return gold_map
                
T = int(input())
for i in range(T):
    N, M = map(int, input().split())
    gold = np.array(list(map(int, input().split())))
    gold = gold.reshape(N , M)
    gold_map = np.zeros_like(gold) - 1
    results = getScores(gold, gold_map, 0, 0)
    print(max(results[:, 0]))

    



