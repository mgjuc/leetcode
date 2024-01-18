#include <iostream>
#include <string>
#include <vector>

// Remove Duplicates from Sorted Array 
// Time Complexity: O(n)，Space Complexity: O(1)
class Solution {
public:
    static int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            //必须是有序的
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];  //++slow 先加一再取加一后的值进行后续计算
            }
        }
        return slow+1;
    }
};

int main() {

    std::cout << "Remove Duplicates from Sorted Array" << std::endl;
    std::vector<int> A {1,1,1,4,5,5,5,6,6};

    std::cout << Solution::removeDuplicates(A) << std::endl;
    return 0;
}