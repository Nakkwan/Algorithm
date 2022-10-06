import sys

input = sys.stdin.readline
N = int(input())


adventures = map(int, input().split())

adventures = sorted(adventures)

groups = 0
count = 0

for i in adventures:
    count += 1
    if count >= i:
        groups += 1
        count = 0
    
print(groups)