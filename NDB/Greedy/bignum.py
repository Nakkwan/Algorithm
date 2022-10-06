n, m, k = map(int, input().split())
data = map(int, input().split())

data = sorted(data, reverse=True)

value = 0

first = data[0]
second = data[1]

for i in range(m):
    if i % k == 0:
        value += second
    else:
        value += first
        
print(value)

##### 위의 답은 time 문제가 있을 수 있음

value == 0
bundle = m // (k+1)
remain = m % (k+1)

value += (first * k + second) * bundle
value += remain * first

print(value)