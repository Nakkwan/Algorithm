N = int(input())
home = list(map(int, input().split()))
sorted(home)
print(home[(N - 1) // 2])