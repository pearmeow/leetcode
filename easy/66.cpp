/*
66. Plus One
Description of problem:
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/

#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
  int carry = 0;
  for (std::size_t digit = digits.size(); digit > 0; --digit) {
    digits[digit - 1] += 1;
    carry = digits[digit - 1] / 10;
    digits[digit - 1] = digits[digit - 1] % 10;
    if (!carry) return digits;
  }
  if (carry) digits.insert(digits.begin(), 1);
  return digits;
}

int main() { return 0; }