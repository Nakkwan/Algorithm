def takeCalc(value, list_, calc_):
    global results_max
    global results_min
    for i in range(4):
        if calc_[i] > 0:
            calc_[i] -= 1
            if i == 0: results = value + list_[0]
            elif i == 1: results = value - list_[0]
            elif i == 2: results = value * list_[0]
            elif i == 3: 
                if value >= 0:
                    results = value // list_[0]
                else:
                    results = -(-value // list_[0])
                
            if sum(calc_) == 0:
                results_max = max(results, results_max)
                results_min = min(results, results_min)
                calc_[i] += 1
                return
            
            takeCalc(results, list_[1:], calc_)
            calc_[i] += 1
                

N = input()
num_list = list(map(int, input().split()))
calc_num = list(map(int, input().split()))

results_max = 0
results_min = 100000000

takeCalc(num_list[0], num_list[1:], calc_num)
print(results_max)
print(results_min)