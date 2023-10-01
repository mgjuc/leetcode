//
// Created by yan on 23-10-1.
//

#include <stdio.h>
#include <iostream>
#include <vector>

class Solution {
public:
    static std::string longestCommonPrefix(std::vector<std::string> &strs) {
        if (!strs.size()) {
            return "";
        }
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

    static std::string longestCommonPrefix(std::vector<std::string> &strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }
        int mid = (start + end) / 2;
        std::string lcpleft = longestCommonPrefix(strs, start, mid);
        std::string lcpright = longestCommonPrefix(strs, mid + 1, end);

        return commonPrefix(lcpleft, lcpright);

    }

    static std::string commonPrefix(const std::string &lcpleft, const std::string &lcpright) {
        int minLenght = std::min(lcpleft.length(), lcpright.length());
        for (int i = 0; i < minLenght; i++) {
            if (lcpright[i] != lcpleft[i]) {
                return lcpleft.substr(0, i);
            }
        }

        return lcpleft.substr(0, minLenght);

    }

};


int main() {

    std::cout << "最长公共前缀" << std::endl;
    std::vector<std::string> *strs = new std::vector<std::string>();
    strs->push_back("flower");
    strs->push_back("flow");
    strs->push_back("flight");

    for (std::string s: *strs) {
        std::cout << s << std::endl;
    }

    std::cout << "结果为" << std::endl;

    std::cout << Solution::longestCommonPrefix(*strs) << std::endl;
    return 0;
}