# [leetcode-Longest-Substring-Without-Repeating-Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

My solution for leetcode Longest Substring Without Repeating Characters.

## Problem Description 

Given a string s, find the length of the longest substring without repeating characters.

 

## Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

## Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

## Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

## Example 4:

Input: s = ""
Output: 0
 

## Constraints:

- 0 <= s.length <= 5 * 104
- s consists of English letters, digits, symbols and spaces.

## My Approach 

We think of a table like this -

|   i   | j = f(i)| 
|-------|---------|
|   0   |    ?    |
|   1   |    ?    |
|  .... |   ....  |
|   n   |     ?   |

Where f(i) is the end index of the longest substring that starts from ith index and maintains all the constraints . 

for exmaple for s = "abca" the table would look like this 

|   i   | j = f(i)| length | substring |
|-------|---------|--------|-----------|
|   0   |    2    |   3    |    abc    |
|   1   |    3    |   3    |    bca    |
|   2   |    3    |   2    |    ca     |
|   3   |    3    |   1    |    a      |


for every i we have to calculate f(i) . Then we can find the length of the longest substring from that . We can do that easily in n^2 with 2 nested loops. 

But if we notice in the table we can see , it'll always be 

f(i+1) >= f(i) 

so if we already calculated j1 = f(i1) for i1 , we can start looking for f(i2) where i2 = i1+1 from j2 = i1 instead of j2 = i2. So a sliding window or two pointer solution can work for this which will reduce the complexity to linear . 


We need to have a hashmap/hashset to keep track of if we have any repeated character in the current window . 

Complexity : O(n) time and O(C) space where C is number of possible unique characters. 
