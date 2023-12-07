def mergeSort(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])
    return merge(left, right)

def merge(arr_l, arr_r):
    i = 0
    j = 0
    result = []
    while i < len(arr_l) and j < len(arr_r):
        if(arr_l[i] < arr_r[j]):
            result.append(arr_l[i])
            i += 1
        else:
            result.append(arr_r[j])
            j += 1

    while i < len(arr_l):
        result.append(arr_l[i])
        i += 1
    
    while j < len(arr_r):
        result.append(arr_r[j])
        j += 1
    
    return result

cases = int(input())

for _ in range(cases):
    arr = [int(i) for i in input().split(' ')]
    arr = mergeSort(arr)
    for i in arr:
        print(i, end=" ")
    print("")

