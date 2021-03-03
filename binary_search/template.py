
# if [lo, hi) does not satisfy the left-false, right-true property, it would only return local minimal

# return minimal index in arr which satisfy function, assume for function, arr left part false, right part true 
# initially, hi should be n, largest + 1, if return n, the whole arr is false for function
def binary_search(arr, lo, hi, function):
    while lo < hi:
        mid = lo+(hi-lo>>1)
        if function(mid):
            hi=mid
        else:
            lo=mid+1
    return lo