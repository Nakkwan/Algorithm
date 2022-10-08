N_str = input()
Digits = len(N_str)

left = 0
right = 0

for i in range(Digits // 2):
    left += int(N_str[i])

for i in range(Digits // 2, Digits):
    right += int(N_str[i])

    
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