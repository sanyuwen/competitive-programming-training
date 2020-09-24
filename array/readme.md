1. given arr and list of intervals. return how many times each num appears in any interval.

[difference array]
D[i], D[0]=A[0], 0<i<=n, D[i]=A[i]-A[i-1]
for A, update(L, R, x), D[L]+=x, D[R+1]-=x
A[i]=D[i]+A[i-1]

count = [0]*(n+1)
for s, e in intervals:
    count[s]+=1
    count[e+1]-=1
for i in range(1, n):
    count[i]+=count[i-1]


#1588. Sum of All Odd Length Subarrays
prefix sum:
sum(A[i:j]) = P[j]-P[i], 0<=i<j<=n,

brute force 1, fixate length
def sumOddLengthSubarrays(self, A: List[int]) -> int:
    P, n = list(accumulate(A, initial=0)), len(A)
    ans = P[n]
    for i in range(3, n+1, 2):
        for j in range(0, n-i+1, 1):
            ans+=P[j+i]-P[j]
    return ans

brute force 2, fixate start index
def sumOddLengthSubarrays(self, A: List[int]) -> int:
    P, n = list(accumulate(A, initial=0)), len(A)
    ans = 0
    for i in range(n):
        for j in range(i+1, n+1, 2):
            ans+=P[j]-P[i]
    return ans

O(n)
def sumOddLengthSubarrays(self, A):
    P = [0]
    for x in A:
        P.append(P[-1] + x)

    # fixate ending index, 
    # (P[j]-P[j-1])+(P[j]-P[j-3])+(P[j]-P[j-5])+(P[j]-P[j-7]).... == (j + 1 >> 1)*P[j]-sum of even/odd indexs
    ans = 0
    prevsum = [0, 0] #(sum of even index seen so far, sum of odd index seen so far)
    for j, q in enumerate(P):
        ans += (j + 1 >> 1) * q - prevsum[~j & 1]
        prevsum[j & 1] += q
    return ans

1590. Make Sum Divisible by p
# key observation: P[-1]-(P[j]-P[i]) == 0 (mod p) equavilant to P[i]==P[j]-P[-1] (mod p), i<=j, 
# if i==j, it means remove empty, and can do it in one pass, computing prefix sum on the fly
def minSubarray(self, A: List[int], p: int) -> int:
    P = [0]
    for a in A:
        P.append((P[-1]+a)%p)
    n = len(A)
    ans, last = n , {} # last[v]=i: the rightmost i such that P[i]=v 
    for j, k in enumerate(P):
        last[k]=j
        need = (k-P[-1])%p
        if need in last:
            ans=min(ans, j-last[need])
    return ans if ans<n else -1