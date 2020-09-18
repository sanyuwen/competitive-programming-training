<!-- Problem2: Given an array of integers, find the subarray with maximum XOR.
Solution:
Let's say F(L,R) is XOR of subarray from L to R.
Here we use the property that F(L,R)=F(1,R) XOR F(1,L-1). How?
Let's say our subarray with maximum XOR ended at position i. Now, we need to maximise F(L,i) ie. F(1,i) XOR F(1,L-1) where L<=i. Suppose, we inserted F(1,L-1) in our trie for all L<=i, then it's just problem1.

ans=0 
pre=0 
Trie.insert(0) 
for i=1 to N: 
    pre = pre XOR a[i] 
    Trie.insert(pre) 
    ans=max(ans, Trie.query(pre)) 
print ans  -->