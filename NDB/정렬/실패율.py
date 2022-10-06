def solution(N, stages):
    answer_ = [(0, i) for i in range(N + 2)]
    stages.sort()

    num = len(stages)
    start = 0

    for i in range(num-1):
        if stages[i] != stages[i+1]:
            answer_[stages[i]] = ((i + 1 - start) / (num - start), stages[i])
            start = i + 1
            
        if i == num - 2:
            if stages[i] != stages[i+1]:
                answer_[stages[i+1]] = (1, stages[i+1])
            else:
                answer_[stages[i]] = ((i + 2 - start) / (num - start), stages[i])

    answer_ = answer_[1:-1]
    answer_ = sorted(answer_, key=lambda x:-x[0])
    answer = [i for _, i in answer_]
    
    return answer