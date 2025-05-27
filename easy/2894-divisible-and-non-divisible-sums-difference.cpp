/**
 * @file 2894-divisible-and-non-divisible-sums-difference.cpp
 * @author Perry Huang
 * @date 2025-05-26
 * 2894. Divisible and Non-divisible Sums Difference
 * You are given positive integers n and m.
 * Define two integers as follows:
 * num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
 * num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
 * Return the integer num1 - num2.
 */

int differenceOfSums(int n, int m) {
  // sum formula of all numbers 1 to n
  int num1 = (n * (n + 1)) / 2;
  int num2 = 0;
  for (int i = m; i <= n; i += m) {
    num2 += i;
  }
  return num1 - 2 * num2;
}
