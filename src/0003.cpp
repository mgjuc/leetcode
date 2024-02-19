// 最长不重复子字符串长度
// Created by yan on 23-10-27.
//

#include <iostream>
#include <string>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string &s) {
        int start = 0, end = 0, result = 0, length = s.length();
        while (end < length) {
            for (int index = start; index < end; index++) {
                //滑动窗口移动左边界
                if (s[index] == s[end]) {
                    std::cout << "index " << index << " end " << end << std::endl;
                    start = index + 1;
                    break;
                }
            }
            //滑动窗口移动右边界
            end++;
            result = std::max(result, end - start);
            std::cout << "start=" << start << " end=" << end << " result=" << result << std::endl;
        }
        return result;
    }
};

int main() {

    std::cout << "最长不重复子字符串长度" << std::endl;
    std::string s = "abddaefcbf";

    std::cout << s << "长度为" << s.length() << ",结果为" << std::endl;

    std::cout << Solution::lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
