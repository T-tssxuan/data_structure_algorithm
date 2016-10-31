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
#### 8. [Find the ith number in dictionary order and all number less than n](./code/ith_dictionary_order_lt_N.cpp)
```
Describe: Given a N, find the ith number with the dictionary order.(such as
0 < 1 < 2 < 3....< 9), all number no greater than N. All preceding '0' is not 
considered.

Source: None

Solution:
    a. Suppose the length of the N in decimal is Len, the most significant
       position is 1.
    b. For all number with the length N, each number should no greater than 
       the conrespond position at N if the preceding number is equal N.
    c. For all number with the length N, the conresp
    d. For all number with a shorter length, all digitals are considered.
```
#### 9. [Building Outline](./code/building_outline.cpp)
```
Describe: Given a series of pairs with [start_point, end_point, height], merge
the pairs with the following rules:
1. The pairs with overlaped range need to merge, the higher one will cover the
lower one.
2. After merged, the rest of the pair need to consider.
3. The pairs with the same height need to merge if the range overlaped

Source: lintcode http://www.lintcode.com/en/problem/building-outline/

Solution:
    a. Using a heap the get the pair with the smallest start_point.
    b. Using the last valid pair in the result to produce the comming pairs,
       if the range of their with no overlapping, just skip to the newer, or
       if the height is the same, just merge them
       if the height is not the same, using the higher to split the lower one.
```
#### 10. [Longest words online](./code/longest_words.cpp)
```
Describe: Given a series of words, find all words with the longest length.
Please provide a online algorithm.

Source: lintcode http://www.lintcode.com/en/problem/longest-words/

Solution:
    Just like the split method using in the fast sorting algorithm
```
#### 11. [Split and scatter entries](./code/split_and_scatter_entries.cpp)
```
Describe: Given a bunch of entries(string), each entry has two parts, the first
part is the id, the second part is the content. Split the entris into the given
size, the entris have the same id should be scattered at best. In other word, 
each segment should get kinds of id as much as possible. Note: the origin order
of the entries should be peserved.

Source: None

Solution:
    a. Using a queue to record the position of elements with the same id.
    b. Using a min heap to get each turns result. When building the heap,
       scattering is the first consideration, and then considering the order.
```
#### 12. [Get the next second of given time string](./code/get_next_second.cpp)
```
Describe: Give you a time string with the format: YYYY-MM-DD HH:MM:SS get the 
next second of the moment. Times of 400 is leap year, times of 100 is not leap
year, time of 4 year is leap year.

Source: none
```
#### 13. [Get the maximum string without pattern in given list](./code/find_maximum_string_remove_illegal_patter.cpp)
```
Describe: Alice writes an English composition with a length of N characters. 
However, her teacher requires that M illegal pairs of characters cannot be 
adjacent, and if 'ab' cannot be adjacent, 'ba' cannot be adjacent either.
In order to meet the requirements, Alice needs to delete some characters.
Please work out the minimum number of characters that need to be deleted.

Source: hihocoder http://hihocoder.com/problemset/problem/1400

Solution:
    a. Using dynamic programming based the priveous maximum value.
```
#### 14. [Powers of two](./code/powers_of_two.cpp)
```
Describe: Given a positive integer N, it is possible to represent N as the sum 
of several positive or negative powers of 2 (± 2k for some k). For example 7 can
be represented as 22 + 21 + 20 and 23 + (-20).
Your task is to find the representation which contains the minimum powers of 2.

Source: hihocoder http://hihocoder.com/contest/hihointerview21/problem/3

Solution:
    a. We note that a sequence of binaries, if we partition it by the 2 
       consecutive zeros or mores, and each split's twos can be represented with
       sum of each partition min(numbers of ones, 2 + number of zeros).
```
#### 15. [Set Matrix zero](./code/set_matrix_zero.cpp)
```
Descirbe: Given a m x n matrix, if an element is 0, set its entire row and 
column to 0. Do it in place.

Source: lintcode http://www.lintcode.com/en/problem/set-matrix-zeroes/

Solution:
    a. Record each row and column status in the first row and the first column
       of the matrix.
    b. Set correspond row and column to zero except the first row and the first
       column.
```
#### 16. [Burst Ballons](./code/burst_ballons.cpp)
```
Describe: Given n balloons, indexed from 0 to n-1. Each balloon is painted with 
a number on it represented by array nums. You are asked to burst all the 
balloons. If the you burst balloon i you will get:
        nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and 
right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
- You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can 
  not burst them.
- 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Source: lintcode http://www.lintcode.com/en/problem/burst-balloons/

Solution:
    a. Suppose we get the last burst ballons in each range[i...j] is k, so the 
       max value of this range is some k range[i...k - 1] + range[k + 1...j] + 
       nums[k] * nums[i] * nums[j].
    b. The reverse thinking.
```

