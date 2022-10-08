N = int(input())
home = list(map(int, input().split()))
home = sorted(home)
print(home[(N - 1) // 2])