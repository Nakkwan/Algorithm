N = int(input())

schedule = []
for i in range(N):
    schedule.append(list(map(int, input().split())))
    
payed = [0] * (N + 1)

for i in range(N):
    next_ = schedule[i][0] + i
    if next_ > N:
        continue
    payed[next_:] = map(lambda x: max(schedule[i][1] + payed[i], x), payed[next_:])

print(max(payed))