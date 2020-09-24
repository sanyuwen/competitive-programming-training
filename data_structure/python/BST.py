from sortedcontainers import SortedSet

#https://binarysearch.com/room/Weekly-Contest-25-BTseKJ0AyN?questionsetIndex=2

class Solution:
    def solve(self, A):
        # Write your code here
        
        def floor(a):
            # return int less or equal to a in SortedSet, return -1 if not applicable
            if not ss:
                return -1
            idx = ss.bisect_left(a)
            if idx==0:
                return ss[0] if ss[idx]==a else -1
            if idx==len(ss) or ss[idx]>a:
                return ss[idx-1]
            else:
                return ss[idx]
        
        n = len(A)
        B = [0]*n
        for i in range(n-2,-1,-1):
            B[i]=max(B[i+1], A[i+1])
        ss = SortedSet(A[:1])
        ans = 0
        for j in range(1, n-1):
            pre = floor(A[j])
            #print(j, pre)
            if -1<pre and B[j]>=A[j]:
                ans=max(ans, pre+A[j]+B[j])
            ss.add(A[j])
        return ans