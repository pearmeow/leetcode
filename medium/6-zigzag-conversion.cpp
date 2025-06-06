/**
 * @file 6-zigzag-conversion.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 6. ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
 * rows like this: P   A   H   N A P L S I I G Y   I   R
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number
 * of rows: Adding strings to strings is faster than adding chars 1 by 1
 */

#include <iostream>
#include <string>
#include <vector>

std::string convert(const std::string& s, int numRows) {
    std::vector<std::string> rows(numRows);
    std::string res;
    int zig = 0;
    bool zag = false;
    if (numRows == 1) return s;
    for (size_t i = 0; i < s.size(); ++i) {
        if (zig == numRows - 1)
            zag = true;
        else if (zig == 0)
            zag = false;
        rows[zig] += s[i];
        if (zag)
            zig -= 1;
        else
            zig += 1;
    }
    for (size_t i = 0; i < rows.size(); ++i) {
        res += rows[i];
    }
    return res;
}
