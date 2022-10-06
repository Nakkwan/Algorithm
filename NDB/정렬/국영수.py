import sys

def rightBig(x, y):
    if x[1] > y[1]:
        return True
    elif x[1] < y[1]:
        return False
    else:
        if x[2] > y[2]:
            return False
        elif x[2] < y[2]:
            return True
        else:
            if x[3] > y[3]:
                return True
            elif x[3] < y[3]:
                return False
            else:
                if x[0] > y[0]:
                    return False
                else:
                    return True
            
def sortClass(student):
    if len(student) < 1:
        return student
    pivot = student[0]
    rest = student[1:]
    
    left = []
    right = []
    for i in rest:
        if rightBig(pivot, i):
            right.append(i)
        else:
            left.append(i)
            
    return sortClass(left) + [pivot] + sortClass(right)

input = sys.stdin.readline
N = int(input())
student = []
for i in range(N):
    name, ko, eng, math = input().split()
    student.append([name, int(ko), int(eng), int(math)])
            
result = sortClass(student)
for stu in result:
    print(stu[0])
            
    
# ###### 해설 ######
# input = sys.stdin.readline
# N = int(input())
# student = []
# for i in range(N):
#     name, ko, eng, math = input().split()
#     student.append([name, int(ko), int(eng), int(math)])
#     
# student.sort(key=lambda x:(-x[1], x[2], -x[3], x[0]))
# for stu in student:
#     print(stu[0])