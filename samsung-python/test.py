def merge2(nums, low, mid, high):
    r = []
    i, j = low, mid + 1
    
    # Comparing item and put it in list r
    while i <= mid and j <= high:
        if nums[i] < nums[j]:
            r.append(nums[i])
            i += 1
        else:
            r.append(nums[j])
            j += 1
            
    if i > mid:
        for k in range(j, mid + 1):
            r.append(nums[j])
    else:
        for k in range(i, mid + 1):
            r.append(nums[i])
            
    for k in range(len(r)):
        nums[low + k] = r[k]

def mergeSort2(nums, low, high):
    if low < high:
        # print(nums)
        mid = (low + high) // 2
        mergeSort2(nums, low, mid)
        mergeSort2(nums, mid + 1, high)
        
        # print(low, mid, high)
        merge2(nums, low, mid, high)
        
l1 = [1, 4, 6, 3, 2, 7, 8, 0, 9, 5]

mergeSort2(l1, 0, len(l1) - 1)
print(l1)