## binary_search

### [binary_search.**binary_search**(*lo*, *hi*, *function*)](/binary_search.py)


[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)
```python
def search(self, nums: List[int], target: int) -> int:
        
    def binary_search(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start

    n = len(nums)
    i = binary_search(1, n, lambda x: nums[x]<nums[0])
    res = None
    find_target = lambda x:nums[x]>=target
    if i==n:
        res = binary_search(0, n, find_target)
    else:
        if target<nums[0]:
            res = binary_search(i, n, find_target)
        else:
            res = binary_search(0, i, find_target)
    return res if res<n else -1
```

[Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array)
```python
def searchRange(self, nums, target):

    def binary_search(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    if nums:
        n = len(nums)
        i = binary_search(0, n, lambda x: nums[x] >= target)
        if i==n or nums[i]!=target:
            return [-1, -1]
        j = binary_search(i+1, n, lambda y: nums[y] > target)
        return [i, j-1]
    return [-1, -1]
```


[Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
```python
def search(self, nums: List[int], target: int) -> bool:
        
        def binary_search(start, end, function):
            while start < end:
                mid = start+(end-start>>1)
                if function(mid):
                    end=mid
                else:
                    start=mid+1
            return start
        
        n = len(nums)
        j=n-1
        while j and nums[j]==nums[0]:
            j-=1
        if j==0:
            return nums[j]==target
        else:
            j+=1
            p = binary_search(0, j, lambda x:nums[x]<nums[0])
            res = 0
            if target>=nums[0]:
                res = binary_search(0, p, lambda x:nums[x]>=target)
                return res < p and nums[res]==target
            else:
                res = binary_search(p, j, lambda x:nums[x]>=target)
                return res < j and nums[res]==target
```

[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
```python
def findMin(self, nums: List[int]) -> int:
    # without duplicates
        
    def binary_search(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    n = len(nums)
    if n==1:
        return nums[0]
    if nums[-1]>nums[0]:
        return nums[0]
    index = binary_search(0, n, lambda x: nums[x]<nums[0])
    return nums[index if index<n else 0]    
```

[Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
```python
def findMin(self, nums: List[int]) -> int:
    # with duplicates
        
    def binary_search(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    n = len(nums)
    if n==1:
        return nums[0]
    if nums[-1]>nums[0]:
        return nums[0]
    j = n-1
    while j and nums[j]==nums[0]:
        j-=1
    if j==0:
        return nums[0]
    j+=1
    index = binary_search(0, j, lambda x: nums[x]<nums[0])
    return nums[index if index<j else 0]    
```

[Find Peak Element](https://leetcode.com/problems/find-peak-element)
```python
 def findPeakElement(self, nums: List[int]) -> int:
        
    def binary_search(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    return binary_search(0, len(nums)-1, lambda x:nums[x]>nums[x+1])

```

[H-Index II](https://leetcode.com/problems/h-index-ii)
```python
def hIndex(self, citations: List[int]) -> int:
        
    def binary_search(lo, hi, function):
        while lo < hi:
            mid = lo+(hi-lo>>1)
            if function(mid):
                hi=mid
            else:
                lo=mid+1
        return lo
    
    if citations:
        n = len(citations)
        return n - binary_search(0, n, lambda x: n-x<=citations[x])
    return 0
```

[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)
```python

#https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
#https://leetcode.com/problems/longest-increasing-subsequence/
def lengthOfLIS(self, nums: List[int]) -> int:
        
        n = len(nums)
        arr = [0]*n
        size = 1
        arr[0] = nums[0]
        
        def binary_search(lo, hi, a):
            while lo<hi:
                mid = lo+(hi-lo>>1)
                if arr[mid]>=a:
                    hi = mid
                else:
                    lo = mid+1
            return lo
        
        for a in nums[1:]:
            # every iteration, 
            # the current element would be correct position of the LIS ending at it
            i = binary_search(0, size, a)
            arr[i] = a
            if i == size:
                size+=1
        return size
```

[Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square)
```python
def isPerfectSquare(self, num: int) -> bool:
    if num==1: 
        return num
    
    def binary_search(lo, hi, function):
        while lo < hi:
            mid = lo+(hi-lo>>1)
            if function(mid):
                hi=mid
            else:
                lo=mid+1
        return lo
    return binary_search(2, num>>1, lambda x: x**2 >= num)**2 == num
```

[Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum)
```python
# binary search is used to solve opimization problem
def splitArray(self, nums: List[int], m: int) -> int:
        n, total = len(nums), sum(nums)
        if m==1:
            return total
        else:
            lower = max(total//m, max(nums))
        
        
        def binary_search(lo, hi, function):
            while lo < hi:
                mid = lo+(hi-lo>>1)
                if function(mid):
                    hi=mid
                else:
                    lo=mid+1
            return lo
        
        def possible(target):
            # split nums into m part with largest sum of target
            # is it possible
            count, subsum =1, 0
            for i, c in enumerate(nums):
                subsum+=c
                if subsum>target:
                    count+=1
                    subsum=c
                    if count>m:
                        return False
            return True
                
        
        return binary_search(lower, total, possible)
```

[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas)
```python
def minEatingSpeed(self, piles: List[int], H: int) -> int:
        
    def cando(speed)->bool:
        # whether koko with this speed can eat all
        return sum(math.ceil(p/speed) for p in piles)<=H
    
    def binary_search2(lo, hi, function):
        # first lo<=index<hi satisfy function => true
        # if return hi, no element satisfy within [lo, hi)
        while lo<hi:
            mid=lo+(hi-lo>>1)
            if function(mid):
                hi=mid
            else:
                lo=mid+1
        return lo
        
    return binary_search2(1, max(piles)+1, cando)
```

[Find Positive Integer Solution for a Given Equation](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation)
```python
def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        hi = 1000
        ans = []
        
        def binary_search2(lo, hi, function):
            while lo < hi:
                mid = lo+(hi-lo>>1)
                if function(mid):
                    hi=mid
                else:
                    lo=mid+1
            return lo
        
        for x in range(1, 1001):
            if not customfunction.f(x, hi)<z:
                y = binary_search2(1, hi+1, lambda t: customfunction.f(x, t)>=z)
                value = customfunction.f(x, y)
                if value>=z:
                    hi=y-1
                    if value==z:
                        ans.append([x,y])
        return ans
```

[Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold)
```python
def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def good(d):
            # if current d satisfy threshold
            return sum(math.ceil(p/d) for p in nums)<=threshold
        
        def binary_search2(lo, hi, function):
            while lo < hi:
                mid = lo+(hi-lo>>1)
                if function(mid):
                    hi=mid
                else:
                    lo=mid+1
            return lo
        
        return binary_search2(1, max(nums)+1, good)
```

[https://binarysearch.io/room/Weekly-Contest-24-t9gad8UJRv?questionsetIndex=2]
since making K pairs implies we can make K-1 pairs, we can binary search for the answer
class Solution:
    def solve(self, A, target):
        # Write your code here
        A.sort()
        n = len(A)
        
        def possible(k):
            return all(
                A[-k+i]-A[i]>=target for i in range(k)
                )
        
        def binary_search(lo, hi, function):
            while lo<hi:
                mid = hi-(hi-lo>>1)
                if function(mid):
                    lo=mid
                else:
                    hi=mid-1
            return hi
        
        
        return binary_search(-1, n>>1, lambda x: possible(x))

