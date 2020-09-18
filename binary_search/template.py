
#https://leetcode.com/problems/find-peak-element/submissions/
#if arr doesn`t satisfy [false, true] property as a whole, 
#binary_search2 would find index with local arr satisfy that, check link above 
def binary_search2(arr, lo, hi, function):
    # return minimal index in arr which satisfy function, assume for function, arr left part false, right part true 
    # initially, hi should be n, largest + 1
    while lo < hi:
        mid = lo+(hi-lo>>1)
        if function(mid):
            hi=mid
        else:
            lo=mid+1
    return lo

def binary_search3(arr, lo, hi, function):
    # return maximal index in arr which satisfy function, assume for function, arr left part true, right part false 
    # initally lo shoulbe be -1, hi=n-1, if return -1, it means no such element satisfy function
    while lo < hi:
        mid = hi-(hi-lo>>1)
        if function(mid):
            lo=mid
        else:
            hi=mid-1
    return hi
        
def binary_search1(arr, lo, hi, target):
    # initally hi shoulbe be n-1, return insertion point for target.
    while lo<=hi:
        mid = lo+(hi-lo>>1)
        cur = nums[mid]
        if cur==target:
            return mid
        elif cur>target:
            hi=mid-1
        else:
            lo=mid+1
    return lo