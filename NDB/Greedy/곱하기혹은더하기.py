def calc(before, value):
    if before * value > before + value:
        return before * value
    else:
        return before + value
        

S = list(map(int, input()))
results = S[0]
for i in range(1, len(S)):
    results = calc(results, S[i])
    
print(results)

