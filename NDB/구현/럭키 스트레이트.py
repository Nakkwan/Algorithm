N_str = input()
Digits = len(N_str)
N = int(N_str)

Digits_half = Digits // 2

left = 0
right = 0
clac_N = N

for i in reversed(range(Digits)):
    if i < Digits_half:
        left += (clac_N // 10^i)
    else:
        right += (clac_N // 10^i)
    clac_N = clac_N % 10^i
    
if left == right:
    print("LUCKY")
else:
    print("READY")
    
# ### 해설 ###
# n = input()
# length = len(n)
# summary = 0
# for i in range(length // 2):
#     summary += int(n[i])
#     
# for i in range(length //2, length):
#     summary -= int(n[i])
#     
# if summary == 0:
#     print("LUCKY")
# else:
#     print("READY")