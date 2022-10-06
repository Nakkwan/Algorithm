import sys

input = sys.stdin.readline

def left(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if (mid == 0 or target > array[mid - 1]) and array[mid] ==target:
        return mid
    elif array[mid] >= target:
        return left(array, target, start, mid - 1)
    else:
        return left(array, target, mid + 1, end)


def right(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    n = len(array)
    if (mid == n - 1 or target < array[mid + 1]) and array[mid] == target:
        return mid
    elif array[mid] > target:
        return right(array, target, start, mid - 1)
    else:
        return right(array, target, mid + 1, end)

N, x = map(int, input().split())
list_ = list(map(int, input().split()))

n = len(list_)
first = left(list_, x, 0, n - 1)
if first == None:
    print(-1)
else:
    last = right(list_, x, 0, n - 1)
    print(last - first + 1)