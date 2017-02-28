## Algorithm Problem:

#### Q1: array split problem.
```
Source: beauty of programming
NOTE: 
```

#### Q2: Longest Common Increasing Subsequence (LCS + LIS)
```
Source: http://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
NOTE: 
1. Loop one array, and one array served as auxiliary
```

#### Q3: every element appears two times except two
```
Source: https://leetcode.com/discuss/60408/sharing-explanation-of-the-solution
NOTE: divided into to group
```

#### Q4: every element appear n times except some.
```
Source: https://leetcode.com/problems/single-number-ii/
NOTE: bit count
```

#### Q5: Given a array, find the maximum sum of subsequence which less than k.
```
Source: none
NOTE: Using the prefix sum. The sum of arr[i…j] = pre[j] - pre[i] + arr[i]. We using a binary search tree to record the prefix sum, and each time we get a prefix sum, we search the tree to find the maximum element which not greater than prefix[x] - k, and we can get the subsequence sum according to this value.
ANALYSIS: O(nlog(n))
```

#### Q6: Max Sum of Rectangle No Larger Than K
```
Source: https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/
NOTE: 
1. Get the prefix sum of the row or column according to the length of each dimension.
2. Using the shorter dimension to generate n*n or m*m sub range.
3. Using the method applied in Q5 to get the value
ANALYSIS: O( less(m, n)^2 * larger(m, n)* log(larger(m, n)) ) 
```

#### Q7: Get the Preorder, Postorder, Inorder traversal of a Binary Tree.
```
Source: null
NOTE:
1. Recursive traversal the tree can get these result easily
2. Preorder using stack and traverse the left child first
3. Postorder using stack and traverse the right child first, and then the reverse of the sequence is the postorder traversal result.
4. Inorder using the Stack push the left child and iterator, when a element has no left child just pop the stack find the element gets right child and iterate again.
```

#### Q8: Word Search II
```
Source: https://leetcode.com/problems/word-search-ii/
NOTE: Using the trie to record the less variation elements.
```

#### Q9: Populating Next Right Pointers in Each Node
```
Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
NOTE: Using the preceding result to get the rest result.

Q10: Palindrome Partitioning
Source: https://leetcode.com/problems/palindrome-partitioning-ii/
NOTE:
1. The to check the longer string is palindrome can base the shorter one
2. Using the dynamic programing
```

#### Q11:  Find K Pairs with Smallest Sums
```
Source: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
NOTE: Using a heap to manage the minimum one.
```

#### Q12: Binary Tree Maximum Path Sum
```
Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
NOTE: Subtree result forms the parent result.
```

#### Q13: Longest Valid Parentheses
```
Source: https://leetcode.com/problems/longest-valid-parentheses/
NOTE: Split the string into different substring like (((()))), and count the right accumulate according to the relative length. Conditions as following:
1. left > right.  left_left < left_right, left_left > left_right
2. left < right.  left_left < left_right, left_left > left_right
```

#### Q14: Min Stack, given the minimum element in the stack with O(1) time
```
Source: http://www.lintcode.com/en/problem/min-stack/
NOTE: save the 2 * number - min
```

#### Q15: N-Queue problem solve without recursive.
```
Source: http://www.lintcode.com/en/problem/n-queens/
NOTE:
1. Simulating the process of recursive.
2. Record the correspond state including: current search row, searched row end column number.
```

#### Q16: O(n) time and O(1) space inorder scan the binary tree.
```
Source: null
NOTE: The left-right most node next one is the current one.
```

#### Q17: O(n) time and O(1) space search the element in a range with given binary search tree.
```
Source: http://www.lintcode.com/problem/search-range-in-binary-search-tree
NOTE: The morris scan.
```

#### Q18: Given an array of integers, find two non-overlapping subarrays which have the largest sum.  The number in each subarray should be contiguous. Return the largest sum. You should solve it with the O(n) time consume
```
Source: http://www.lintcode.com/en/problem/maximum-subarray-ii/
NOTE: 
1. Calculate each index forward and reverse max subarray till this index.
2. The max two subarray sum must be in some forward[i] + reverse[i + 1]
3. So the total time consume is 3*O(n).
```

#### Q19: Given an array of integers and a number k, find k-non-overlapping subarrays which have the largest sum. The number in each subarray should be contiguous. Return the largest sum.
```
Source: http://www.lintcode.com/en/problem/maximum-subarray-iii/
NOTE:
1. The value of m can get from m-1 by scan [z—k][k—end].
2. Time is O(k * n * n)
```

#### Q20: Given N numbers which can be duplicated, and given limit memory and the memory space is less than the total memory need to sort the numbers.
```
Source: None
NOTE:
1. Using split get each element count.
2. Using minimal heap to get the max X number of numbers
3. trie tree to count the number.
```

#### Q21: Find the Majority number in array with O(n) time and O(1) space.
```
Source: http://www.lintcode.com/en/problem/majority-number/
NOTE:
1. Method 1: Moore’s Voting Algorithm
2. Method 2: shrink the array by the former subtract the last, left the value when the result is 0, until no size shrink or the size of the element is 1.
3. See the note I add at the lintcode majority III
```

#### Q22: Given a array permutation calculate the previous or the next permutation of the array.
```
Source: http://www.lintcode.com/en/problem/previous-permutation/  http://www.lintcode.com/en/problem/next-permutation/
Note: 
1. Get the first element which violate correspond order.
2. Swap the element find in the first step and swap with the first element follow some order.
3. Reverse all the left element
```

#### Q23: 3Sum problem, 3 sum of 3 array problem and this problem gets a lot of variance, example: 4 element sum problem, 3 element sum closest problem, and so on.
```
Source: https://en.wikipedia.org/wiki/3SUM  http://www.lintcode.com/problem/3sum-closest
Note:
1. This problem can be solved in O(n^2) and 2014 there is a solution approximate to O(n + nlog(n)) 
```

#### Q24: The boundary of the binary search, especially for the missing of the target. Search the range of the given number in the array.
```
Source: None
Note:
1. Start with “0, size - 1”, exit when “start_idx <= end_idx”
```

#### Q25: Search in the sorted pivot array.
```
Source: http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/
Note:
1. Find the pivot point using binary search
2. If get duplicated element in the array, adjust the search pivot algorithm
```

#### Q26: Longest Increasing Subsequence
```
Source: http://www.lintcode.com/en/problem/longest-increasing-subsequence/
Note:
1. Base the previous sequence.
2. Substitute the first element which greater than current element in the sequence.
3. The later element greater than the previous element, and then there can construct a  increasing subsequence.
```

#### Q27: random disorder a array
```
Source: http://blog.csdn.net/cxllyg/article/details/7986352
```

#### Q28: The multiple device data synchronization conflict detect and solve algorithm.
```
Source: https://developer.android.com/training/cloudsave/conflict-res.html#simple
Note:
1. Using a drawer for each device.
```

#### Q29: A n-tree with n degree node a(n), n - 1 degree node a(n-1), ….. calculate the node of leaves in this tree.
```
Source: none
Note:
1. The n degree tree add n - 1 leaves in this tree.
```

#### Q30: Given a tree “root” and two node “A, B” in the tree, find the lowest ancestor of the two node in the tree.
```
Source: http://www.lintcode.com/en/problem/lowest-common-ancestor/
Note:
1. Inorder scan the tree, some node between A and B must be the lowest ancestor.
2. we should record the depth when we scan the tree, the node get the minimal depth between A and B is the lowest ancestor.
```

#### Q31: Given n distinct positive integers, integer k (k <= n) and a number target.  Find k numbers where sum is target. Calculate how many solutions there are?
```
Source: http://www.lintcode.com/en/problem/k-sum/
Note:
1. Using dynamic program
2. The length of leni,  posj and sumt, get form len(i - 1), posj and sumt + len(i - 1), pos(j - 1) and sum(t - i).
3. If we need to get the list which forms the value, what we should do is using the deep first search and using some subtree cut method to estimate whether the result can be reach.
```

#### Q32: Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
```
If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|
/** You can assume each number in the array is a positive integer and not greater than 100 **/
Source: http://www.lintcode.com/en/problem/minimum-adjustment-cost/
Note:
1. Get the current expectation for the former culculation.
2. Constrain the current value base the previous value.
```

#### Q33: Backpack
```
Given a backpack with volume m, and a sequence of object n. How full you can fill this backpack.
Source: http://www.lintcode.com/en/problem/backpack/
Note:
1. Current value based on the previous element in the backpack
```

#### Q34: Binary Tree Maximum Path Sum
```
The path may start and end at any node in the tree.
Source: http://www.lintcode.com/en/problem/binary-tree-maximum-path-sum/
Note:
1. Using the maximum subarray algorithm.
```

#### Q35: Detect cycle in a linked list
```
Source: https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
Note:
1. Using different speed point
2. Using the math relationship between the point
```

#### Q36: Set element in a backpack with some volume, and a sequence of object with different size, put the elements into the backpack, minimize the number of object put into the backpack and with the maximum capacity.
```
Source: none
Note:
1. From the bigger to smaller can accelerate the procedure.
```

#### Q37: Palindrome pairs problem
```
Source: leetcode
Note:
1. The empty string
2. Sub of the string can concat with the other one.
3. Using map record the prefix and suffix with the left is palindrome.
```

#### Q38: Given a list of number, totally N, and a number M, calculate the number of pairs which the xor of them greater than M.
```
Source: None
Note:
1. Using a trie tree to record each number, and the number of element on each node
2. Search the result by down ward the tree and add the greater subtree, remove the less subtree and move on until the given leave.
```

#### Q39: Given a string and some characters, find the minimal length of the substring which contain all of the characters
```
Variation: the string can be a circle
Source: None
Note:
1. Current node record of the nearest position of these characters based on the previous one.
2. To calculate the minimal string your should find the minimal and the maximum pos of these characters.
3. If there is a circle, you should consider both inner substring or the outer substring.
```

#### Q40: Given a series of numbers, calculate the combination number which can forms the given number k.
```
Source: None
Note:
1. Using dynamic programming
2. Using a table [0…k] record combination number for each number every step.
3. The time consume can be O(n * k).
4. Backpack problem
```

#### Q41: Levenshtein distance
```
the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other. 
Source: https://en.wikipedia.org/wiki/Levenshtein_distance
Note:
1. Dynamic programming
```

#### Q42: minimal cost make parentheses close
```
Give a series of parentheses whit length L, they may close or not, and a sequence number with length L+1, each gap a number stands for the cost. Calculate the minimal cost to make the parentheses close.
Source: None
Note:
1. whenever left parentheses less than right parentheses, must insert a left parentheses, and we choose the smallest one to insert.
2. At last if the right parentheses less than the left parentheses, we need choose the 
```

#### Q43:  Given a series of numbers, we can reverse the suffix, prefix or both. Get the maximum subarray sum of the numbers. Reverse must beginning at the first one or the last one.
```
Source: None
Note:
1. The maximum sequence comes from 2 kind, 1: all reverse, 2. reverse and no reverse. 
2. So the maximum result can be: max subsequence of reversed one, or the sequence composed in the form [max prefix reversed sum][origin sequence sum][max suffix reversed sum]
```

#### Q44: Given a string S and a string T, count the number of distinct subsequences of T in S.
```
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE"while "AEC" is not).
Source: http://www.lintcode.com/en/problem/distinct-subsequences/
Note:
1. For each element in the string T, scan the string S, record each position in S which equals to element in T based on the element previous in S which equals to the previous position.
2. O(m * n) time, O(m) space.
Solution: https://github.com/T-tssxuan/data_structure__algorithm/blob/master/algorithm/code/distinct_subsequences.cpp
```

#### Q45:  Give a string 'str', shift the last k element to the first can make the shifted string equals the origin one. Calculate the minimal k.
```
Source: None
Note: 
1. Each shift i should fill the condition that str.length() % i == 0;
2. O(n√n) time.
Solution: https://github.com/T-tssxuan/data_structure_algorithm/blob/master/algorithm/code/minimal_shift.cpp
```

#### Q46: Edit Distance
```
Given two string str1, str2, calculate the distance between str1 and str2. The distance increase by one when do either operation of the rest: Insert, Delete, Replace
Source: http://www.lintcode.com/en/problem/edit-distance/
Note:
1. Using the longer one forms the shorter one.
2. Scan the shorter one, and evaluate for each position in the longer one the minimal cost to forms the shorter one.
3. The wiki solution: https://en.wikipedia.org/wiki/Edit_distance
4. O(n * m) time, o(max(n, m)) space
Solution: https://github.com/T-tssxuan/data_structure_algorithm/blob/master/algorithm/code/edit_distance.cpp
```

#### Q47: Word ladder
```
Given two words (start and end), and a dictionary, find the length of
shortest transformation sequence from start to end, such that:
1. Only one letter can be changed at a time
2. Each intermediate word must exist in the dictionary
Source: http://www.lintcode.com/en/problem/word-ladder/   http://www.lintcode.com/en/problem/word-ladder-ii/
Note:
1. View it as a graph, and using width first search method.
2. If need to build the path, using a previous pointer to point the previous one.
```

#### Q48: Building Outline
```
Describe: Given a series of pairs with [start_point, end_point, height], merge
the pairs with the following rules:
1. The pairs with overlaped range need to merge, the higher one will cover the
lower one.
2. After merged, the rest of the pair need to consider.
3. The pairs with the same height need to merge if the range overlaped
Source: http://www.lintcode.com/en/problem/building-outline/
Note:
1. Using a heap the get the pair with the smallest start_point.
2. Using the last valid pair in the result to produce the comming pairs,
       if the range of their with no overlapping, just skip to the newer, or
       if the height is the same, just merge them
       if the height is not the same, using the higher to split the lower one.
```

#### Q49: Word search and Trie tree
```
Given a word table, and a dictionary, search all word in the table.
Source: http://www.lintcode.com/en/problem/word-search-ii/
Note:
1. Using recursive.
2. Building a trie tree for the dictionary and scan.
```

#### Q50: Given list a of positive integers, the value of the element is the time it can be visited, we cannot visit a element in tow adjacent visiting. Count the max number of visiting we can do.
```
Source: amazon
Note:
1. Selecting the highest two to construct the visiting pair, and decrease their value if not equals zero, add them to the next round. O(log(n) * rst)
2. The x(n - 1) gets tow value: the legal number a, the left times b. And the x(n):  t0 = min(x[n], b), t1 = max(x[n], b), t2 = t1 - t0, b = a > t2? 0: t2 - a - 1, a = a + t0 * 2 + min(t2, a) + t2 != a. O(n)
```

#### Q51: Count how many 1 in binary representation of a 32-bit integer. If there is m bits using O(m) time.
```
Source: lintcode http://www.lintcode.com/en/problem/count-1-in-binary/
Note: 
1. NUM & (NUM) elimination the last setted bit in the number.
```
 
#### Q52: There are n coins with different value in a line. Two players take
```
turns to take one or two coins from left side until there are no more coins left.
The player who take the coins with the most value wins.
Could you please decide the first player will win or lose?
```

#### Q52: Wildcard Matching
```
Implement wildcard pattern matching with support for '?' and '*'.
Awesome solution: 
https://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html

Source: lintcode http://www.lintcode.com/en/problem/coins-in-a-line-ii/
```
