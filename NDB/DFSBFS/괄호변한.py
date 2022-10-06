def check(p):
    pair = 0
    for i in range(len(p)):
        if p[i] == "(":
            pair += 1
        else:
            pair -= 1

        if i % 2 == 1:
            if pair % 2 != 0:
                return False
        else:
            if pair < 0:
                return False

    return True

def rev(p):
    q = ""
    for i in range(len(p)):
        if p[i] == "(":
            q += ")"
        else:
            q += "("
    return q

def solution(p):
    if p == "":
        return ""
    pair = 0
    for idx in range(len(p)):
        if p[idx] == "(":
            pair += 1
        else:
            pair -= 1

        if pair == 0:
            u = p[:idx+1]
            v = p[idx+1:]
            break

    if check(u):
        answer = u + solution(v)
    else:
        answer = '(' + solution(v) + ')' + rev(u)[1:-1]

    return answer


############# 다른 사람 풀이 #############

# def solution(p):
#     if p=='': return p
#     r=True; c=0
#     for i in range(len(p)):
#         if p[i]=='(': c-=1
#         else: c+=1
#         if c>0: r=False
#         if c==0:
#             if r:
#                 return p[:i+1]+solution(p[i+1:])
#             else:
#                 return '('+solution(p[i+1:])+')'+''.join(list(map(lambda x:'(' if x==')' else ')',p[1:i]) ))