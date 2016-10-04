## Problems List and Describe [click the title to get the source]
#### 1. [xor](./code/xor.cpp)
```
Describe: Given N positive numbers, and a number m, calculate the number of pairs
whose result with 'xor' operator greater than m.

Source: 今日头条

Solution:
    Using the trie tree and record each subtree elements number.
    O(n)
```
#### 2. [maximum reverse sum of sequence](./code/maximum_reverse_sum_of_sequence.cpp)
```
Describe: Given a series of numbers, we can reverse the suffix, prefix or both. 
Get the maximum subarray sum of the numbers.

Note: reverse must beginning at the first one or the last one.
such as: 2 2 3 4 -2 -3 can transform to: -2 -2 3 4 -2 3

Source: 一点资讯

Solution:
    1. The maximum sequence comes from 2 kind, a: all reverse, b: reverse and 
       no reverse. 
    2. So the maximum result can be: max subsequence of reversed one, or the 
        sequence composed in the form:
        [max prefix reversed sum][origin sequence sum][max suffix reversed sum]
    O(n ^ 2)

```
#### 3. [distinct subsequences](./code/distinct_subsequences.cpp)
```
Describe: Given a string S and a string T, count the number of distinct 
subsequences of T in S.

Note: A subsequence of a string is a new string which is formed from the 
original string by deleting some (can be none) of the characters without 
disturbing the relative positions of the remaining characters. (ie, "ACE" is a 
subsequence of "ABCDE" while "AEC" is not).

Source: lintcode: http://www.lintcode.com/en/problem/distinct-subsequences/

Solution:
    Dynamic programming
    For each element in the string T, scan the string S, record each position 
    in S which equals to element in T based on the element previous in S which 
    equals to the previous position.
    O(S.length() * T.length())
```
#### 4. [minimal shift](./code/minimal_shift.cpp)
```
Describe: Give a string 'str', shift the last k element to the first can make 
the shifted string equals the origin one. Calculate the minimal k.

Source: 今日头条

Solution:
    Each shift i should fill the condition that str.length() % i == 0
    O(n * sqrt(n))
```
#### 5. [edit distance](./code/edit_distance.cpp)
```
Describe: Given two string str1, str2, calculate the distance between str1
and str2. The distance increase by one when do either operation of the
Insert, Delete, Replace.

Source: wikipedia: https://en.wikipedia.org/wiki/Edit_distance 
        lintcode: http://www.lintcode.com/en/problem/edit-distance/

Solution:
    Dynamic problem, using the previous result makes the current minimal result
    O(n * m)
```
#### 6. [word ladder](./code/word_ladder.cpp)
```
Describe: Given two words (start and end), and a dictionary, find the length of
shortest transformation sequence from start to end, such that:
1. Only one letter can be changed at a time
2. Each intermediate word must exist in the dictionary
3. What if you need to get all path for it?

Source: lintcode: http://www.lintcode.com/en/problem/word-ladder/

Solution: 
    a. Regard it as a graph, so each step is the transfer between the two 
       neighbors. Each word can have 25 * str.length() beighbors at most.
       O(depth * 25 * word.length())
    b. If need get all path for it, you need to using a data structure to
       record all previous point for current step. At last you can use it to
       reconstruct the path where comes from.
```
#### 7. [Largest Rectangle in Histogram](./code/largest_rectangle_in_histogram.cpp)
```
Describe: Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle in the 
histogram.
a. what if you the bar is different width?

Source: lintcode: http://www.lintcode.com/en/problem/largest-rectangle-in-histogram/

Solution:
    a. Every bar can be expanded in two deriection, both the forward and 
       backward direction. But we should note that the expanding process can
       be interrupted at the point which the height of less than. So we can
       using a stack to manipulate it, what we can make sure is that the
       element in the stack is the ascending order from the bottom to the top.
       Each element in the stack is composed with the start position and the
       height of it.
    b. If the bars are given different width, the process is identical.
```
