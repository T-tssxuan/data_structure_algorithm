## Problems List and Describe [click the title to get the source]
#### 1. [xor](./code/xor.cpp)
```
Describe: Given N positive numbers, and a number m, calculate the number of pairs
whose result with 'xor' operator greater than m.

Source: toutiao

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

Source: yidian

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
#### 17. [Graph Valid Tree](./code/graph_valid_tree.cpp)
```
Describe: Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to check whether these edges 
make up a valid tree.
Suppose there is no duplicated edges;

Source: lintcode http://www.lintcode.com/en/problem/graph-valid-tree/

Solution: 
    a. BFS
    b. DFS
    c. get the root of the node, and check the root is equal.
    d. Given different color for each node, and merge.
```

#### 18. [Binary Representation](./code/binary_representation.cpp)
```
Describe: Given a (decimal - e.g. 3.72) number that is passed in as a string, 
return the binary representation that is passed in as a string. If the 
fractional part of the number can not be represented accurately in binary with 
at most 32 characters, return ERROR.

Source: lintcode http://www.lintcode.com/en/problem/binary-representation/

Solution:
    a. Using divide two get remainder to process the integer.
    b. Using multiple 2 get the integer to get the fractional value.
```
#### 19. [Largest Number](./code/largest_number.cpp)
```
Describe: Given a list of non negative integers, arrange them such that they 
form the largest number.
Note: Return string instead of number;

Source: lintcode http://www.lintcode.com/en/problem/largest-number/

Solution:
    a. Using the priority queue.
    b. The compare function is need to recursive compare the rest of the string
       and the origin string.
```
#### 20. [Gas station](./code/gas_station.cpp)
```
Describe: The problem please reference to the lintcode.
Extend: Giving a series of number, find position which go a circle gets no 
negative value at all position.

Source: lintcode http://www.lintcode.com/en/problem/gas-station/

Solution:
    a. Get the subtraction of each position.
    b. If the sum is less than zero, none result.
    c. Scan the sequence and accumulate the value, if less than zore at some 
       position, start new accumulate at the next positon.
    d. Do it in O(n).
```
#### 21. [Find First Missing Positive](./code/find_first_missing_positive.cpp)
```
Describe: Given a series of number, find the first missing positive number.

Source: lintcode http://www.lintcode.com/en/problem/first-missing-positive/

Solution:
    a. Move a number in range [1...len] to it's corresponed position in the
       array.
    b. Check for the first one which missed.
    c. If all positions get it's value, just return len + 1.
    d. Do it in O(n)
```
#### 22. [Wildcard Matching](./code/wildcard_matching.cpp)
```
Descirbe: Implement wildcard pattern matching with support for '?' and '\*'.
Do it in O(len(source) * len(pattern).

Source: lintcode http://www.lintcode.com/en/problem/wildcard-matching/

Solution:
    a. Dynamic programming.
    b. If the previous position is matched, the following position can based on
       the one preceding it.
```
#### 23. [Permutation Index](./code/permutation_index.cpp)
```
Descirbe: Given a series of element, find its index in all permutation. Suppose
the index start at 1.

Variation: Element in it can be duplicated.

Source: lintcode http://www.lintcode.com/en/problem/permutation-index/ 

Solution:
    a. All element less than current in the following sequence can make the 
       full permutation, so the result is: 
            [A[i] + count_less(A[i]) * (len - i)! (i -> (0...len - 1))] + 1
    b. The time complexity is O(n ^ 2)
    c. For the duplicated variation, need to consider the identity permutation.
       For each permutation, we need to divide the identity case.
```
#### 24. [Count of Smaller Number before itself](./code/count_of_smaller_numbers_before_itself.cpp)
```
Describe: Given an array of number, for each element finds the number of elements 
which less than it and exist before the give number.

Source: lintcode http://www.lintcode.com/en/problem/count-of-smaller-number-before-itself/

Solution:
    a. Using a binary search tree to record each elements info which includes 
       the number of element equals to it and the number of elements which 
       less than it.
    b. We need to scan from beginning to the end and construct the binary 
       search tree.
    c. The time cost is O(log(n!))
```
#### 25. [Sliding Window Maximum](./code/sliding_window_maximum.cpp)
```
Describe: Given an array of number and a window with size k, the window slides
from left to right, find maximum value at the window at each sliding.

Source: lintcode http://www.lintcode.com/en/problem/sliding-window-maximum/

Solution:
    a. Using deque.
    b. Iterating the deque left the element which greater than current value.
```
#### 26. [Trapping Rain Water](./code/trapping_rain_water.cpp)
```
Describe: Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after raining.

Source: lintcode http://www.lintcode.com/en/problem/trapping-rain-water/

Solution:
    a. Using to anchor the back highest Ab, and the front highest Af, if Af < Ab
       find the next af with af > Af, otherwise find ab > Ab.
    b. Time O(n), Space O(1)
```
#### 27. [Count 1 in Binary](./code/count_1_binary.cpp)
```
Describe: Count how many 1 in binary representation of a 32-bit integer. If 
there is m bit setted in the number, please making the time is O(m).

Source: lintcode http://www.lintcode.com/en/problem/count-1-in-binary/#

Solution:
    a. num & (num - 1) elimilate the last 1 in the number.
```
#### 28. [Convert Expression to Reverse Polish Notation](./code/reverse_polish_notation.cpp)
```
Describe: Given an expression string array, return the Reverse Polish notation 
of this expression. (remove the parentheses)

Source: lintcode http://www.lintcode.com/en/problem/convert-expression-to-reverse-polish-notation/

Solution:
    a. expression_a op expression_b 
       ==> [convert(expression_a), convert(expression_b), op]
    b. note the order of the expression.
```
#### 29. [minimal number](./code/minimal_number.cpp)
```
Describe: Given a series of number, reorder it gets the minimal number the 
formed, not return a string.

Source: lintcode http://www.lintcode.com/en/problem/reorder-array-to-construct-the-minimum-number/
Reference: problem 19 largest number.

Solution:
    a. Using a priority queue to manage.
    b. Return the minimal number first.
    c. Time O(nlog(n))
```
#### 30. [Best Time to Buy and Sell Stock IV](./code/best_time_to_buy_and_sell_stock.cpp)
```
Describe: Say you have an array for which the ith element is the price of a 
given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k 
transactions.

Source: lintcode http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iv/

Solution:
    a. Get a local max, with the meaning that current day the jth sell happened.
    b. The local max can merge to the previous transaction.
    c. Another, merger the consective transaction with least lost till left k 
       transaction with O(k * lg(n)).
```
#### 31. [Flipping coins]
```
Describe: Given a series of coins, and two players. Each time their can flip x 
or y coins, decide the first player will win or lose.

Source: none

Solution:
    a. If the first can makes the coins reach m * (x + y) first, he will win the
       game.
```
#### 32. [Coins in a line ii](./code/coins_in_a_line_ii.cpp)
```
Describe: There are n coins with different value in a line. Two players take 
turns to take one or two coins from left side until there are no more coins left. 
The player who take the coins with the most value wins.

Could you please decide the first player will win or lose?

Source: lintcode http://www.lintcode.com/en/problem/coins-in-a-line-ii/

Solution:
    a. Game theory.
    b. Current best is the better of two method, and each method gets from the
       worst result selected by the other one.
```
#### 33. [Gray Code](./code/gray_code.cpp)
```
Describe: The gray code is a binary numeral system where two successive values 
differ in only one bit.
Given a non-negative integer n representing the total number of bits in the 
code, find the sequence of gray code. A gray code sequence must begin with 0 and 
with cover all 2n integers.

Source: lintcode http://www.lintcode.com/en/problem/gray-code/#

Solution:
    a. Reverse back.
```
#### 34. [Valid number](./code/valid_number.cpp)
```
Describe: Validate if a given string is numeric.

Source: lintcode http://www.lintcode.com/en/problem/valid-number/

Solution:
    a. Each condition, preceding zeros and padding zeros.
```
#### 35. [Generate Parentheses](./code/generate_parentheses.cpp)
```
Describe: Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

Source: lintcode http://www.lintcode.com/en/problem/generate-parentheses/

Solution:
    a. Using common recursive algorithm
```
#### 36. [Copy Books](./code/copy_books.cpp)
------------------
```
Describe: Given an array A of integer with size of n( means n books and number 
of pages of each book) and k people to copy the book. You must distribute the 
continuous id books to one people to copy. (You can give book A[1],A[2] to one 
people, but you cannot give book A[1], A[3] to one people, because book A[1] and 
A[3] is not continuous.) Each person have can copy one page per minute. Return 
the number of smallest minutes need to copy all the books.

Source: lintcode http://www.lintcode.com/en/problem/copy-books/

Solution:
    a. The dp[x][y] array represented the minimal value for x people process the 
       preceding y books. And then we can conclude that the x + 1 people process
       preceding j books, can be max(dp[x][i - 1], sum(i...j)) for some i.
    b. We notice that the dp[x][y] is a nondecrease for some x, so when deal
       with the max(dp[x][i - 1], sum(i...j)), we can increase i when we make 
       sure there is dp[x][i] > sum(i...j). So we can make a O(n * k) algorithm
       form this problem.
    c. Time O(n * k)
```
#### 37. [Wiggle sort](./code/wiggle_sort.cpp)
```
Describe: Given an unsorted array nums, reorder it such that
nums[0] < nums[1] > nums[2] < nums[3]....

Source: lintcode http://www.lintcode.com/en/problem/wiggle-sort-ii/

Solution:
    a. https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
```
#### 38. [Maximal Rectangle](./code/maximal_rectangle.cpp)
```
Desribe: Given a 2D boolean matrix filled with False and True, find the largest 
rectangle containing all True and return its area.

Source: lintcode http://www.lintcode.com/en/problem/maximal-rectangle/

Solution:
    a. Dynamic program.
    b. The maximum rectange for a sequence.
    c. O(m * n)
```
#### 39. [Perfect Squares](./code/perfect_squares.cpp)
```
Describe: Given a positive integer n, find the least number of perfect square 
numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Source: lintcode http://www.lintcode.com/en/problem/perfect-squares/#

Solution: 
    a. https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
```
#### 40. [Super Ugly Number](./code/super_ugly_number.cpp)
```
Describe: Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given 
prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 
28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 
7, 13, 19] of size 4.

Source: lintcode http://www.lintcode.com/en/problem/super-ugly-number/

Solution:
    a. The next number it the mulitiple of the primes[i] * dp[idx[i]], and the 
       index correspond to primes[i] is increase.
    b. O(n * length)
```
#### 41. [Create Maximum Number](./code/create_maximum_number.cpp)
```
Describe: Given two arrays of length m and n with digits 0-9 representing two 
numbers. Create the maximum number of length k <= m + n from digits of the two. 
The relative order of the digits from the same array must be preserved. Return 
an array of the k digits. You should try to optimize your time and space 
complexity.

Source: lintcode http://www.lintcode.com/en/problem/create-maximum-number/

Solution:
    a. Get the maximum subarray from a longer array.
    b. Merge two array.
```
