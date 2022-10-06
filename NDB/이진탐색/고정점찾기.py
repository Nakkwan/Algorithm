def fixpoints(list_, left, right):
    mid = (left + right) // 2
    if left > right:
        return -1
    if list_[mid] == mid:
        return mid
    elif list_[mid] > mid:
        return fixpoints(list_, left, mid - 1)
    else:
        return fixpoints(list_, mid + 1, right)

import sys
input = sys.stdin.readline

N = int(input())
elem = list(map(int, input().split()))
value = fixpoints(elem, 0, len(elem) - 1)
print(value)