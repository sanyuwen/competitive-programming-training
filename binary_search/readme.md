## binary_search

### [binary_search.**binary_search**(*lo*, *hi*, *function*)](/binary_search.py)

Find the first index `i` where `lo <= i <= hi` that satisfies `function`.

when returned hi, it means lo <= j < hi not satisfy function

def binary_search(arr, start, end, function):
    while start < end:
        mid = start+(end-start>>1)
        if function(arr, mid):
            end=mid
        else:
            start=mid+1
    return start

[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays)
```python
# this solution is wrong
# def findMedianSortedArrays(nums1, nums2):

#     def median(a, b, extrema):
#         k = -1 * (extrema == max)
#         half = []
#         if a:
#             half += [nums2[j + k]]
#         if b:
#             half += [nums1[i + k]]
#         return extrema(half)

#     nums1, nums2 = sorted([nums1, nums2], key=len)
#     m, n = len(nums1), len(nums2)
#     sum_len = m + n
#     mean_len = (sum_len + 1)//2
#     i = binary_search(0, m,
#         lambda x: x and nums1[x - 1] > nums2[mean_len - x]
#     )
#     j = sum_len - i
#     return median_low if sum_len%2 else (median_low
#         + median(i == m, j == n, min)
#     )/2
```

[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)
```python
def search(self, nums: List[int], target: int) -> int:
        
        def binary_search2(start, end, function):
            while start < end:
                mid = start+(end-start>>1)
                if function(mid):
                    end=mid
                else:
                    start=mid+1
            return start
        
        def binary_search1(lo, hi, target):
            while lo<=hi:
                mid = lo+(hi-lo>>1)
                if nums[mid]==target:
                    return mid
                elif nums[mid]>target:
                    hi=mid-1
                else:
                    lo=mid+1
            return -1

        if nums:
            n = len(nums)
            i = binary_search2(0, n, lambda x: nums[x]<nums[0])
            if i==n:
                return binary_search1(0, n-1, target)
            else:
                if target<nums[0]:
                    return binary_search1(i, n-1, target)
                else:
                    return binary_search1(0, i-1, target)
        return -1
```

[Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array)
```python
def searchRange(self, nums, target):
    
    if nums:
        n = len(nums)
        i = binary_search(0, n, lambda x: nums[x] >= target)
        if i==n or nums[i]!=target:
            return [-1, -1]
        j = binary_search(i, n, lambda y: nums[y] > target)
        #print(j)
        return [i, j-1]
    return [-1, -1]
```


[Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)
```python
def search(self, nums: List[int], target: int) -> bool:
        
        def binary_search2(start, end, function):
            while start < end:
                mid = start+(end-start>>1)
                if function(mid):
                    end=mid
                else:
                    start=mid+1
            return start
        
        def binary_search1(lo, hi, target):
            while lo<=hi:
                mid = lo+(hi-lo>>1)
                if nums[mid]==target:
                    return True
                elif nums[mid]>target:
                    hi=mid-1
                else:
                    lo=mid+1
            return False
        
        if nums:
            n = len(nums)
            j=n-1
            while j and nums[j]==nums[0]:
                j-=1
            if j==0:
                return nums[j]==target
            else:
                # rotated
                j+=1
                p = binary_search2(0, j, lambda x:nums[x]<nums[0])
                if p==j:
                    return binary_search1(0, j-1, target)
                else:
                    if target<nums[0]:
                        return binary_search1(p, j-1, target)
                    else:
                        return binary_search1(0, p-1, target)
        return False
```

[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
```python
def findMin(self, nums: List[int]) -> int:
        
    def binary_search2(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    if nums[-1]<nums[0]:
        return nums[binary_search2(0, len(nums), lambda x: nums[x]<nums[0])]
    return nums[0]
```

[Find Peak Element](https://leetcode.com/problems/find-peak-element)
```python
 def findPeakElement(self, nums: List[int]) -> int:
        
    def binary_search2(start, end, function):
        while start < end:
            mid = start+(end-start>>1)
            if function(mid):
                end=mid
            else:
                start=mid+1
        return start
    
    if nums:
        return binary_search2(0, len(nums)-1, lambda x:nums[x]>nums[x+1])
    return -1
```

[H-Index II](https://leetcode.com/problems/h-index-ii)
```python
def hIndex(self, citations: List[int]) -> int:
        
    def binary_search2(lo, hi, function):
        while lo < hi:
            mid = lo+(hi-lo>>1)
            if function(mid):
                hi=mid
            else:
                lo=mid+1
        return lo
    
    if citations:
        n = len(citations)
        return n - binary_search2(0, n, lambda x: n-x<=citations[x])
    return 0
```

[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)
```python

#https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
def lengthOfLIS(self, nums: List[int]) -> int:
        
        def binary_search2(lo, hi, function):
            while lo < hi:
                mid = lo+(hi-lo>>1)
                if function(mid):
                    hi=mid
                else:
                    lo=mid+1
            return lo

        tails, size = [0]*len(nums), 0
        for num in nums:
            i = binary_search2(0, size, lambda x: tails[x] >= num)
            tails[i], size = num, max(i + 1, size)
        return size
```

[Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square)
```python
def isPerfectSquare(self, num: int) -> bool:
    if num==1: 
        return num
    
    def binary_search2(lo, hi, function):
        while lo < hi:
            mid = lo+(hi-lo>>1)
            if function(mid):
                hi=mid
            else:
                lo=mid+1
        return lo
    return binary_search2(2, num>>1, lambda x: x**2 >= num)**2 == num
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
        
        
        def binary_search2(lo, hi, function):
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
                
        
        return binary_search2(lower, total, possible)
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

