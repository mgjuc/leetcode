#include <iostream>
#include <vector>
#include <map>


class Solution {
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result(2, -1);	//count, init value
		std::map<int, int> buffer ;	// key是值，value是所在数组下标

		for (int i = 0; i < nums.size(); i++) {
			//判断机加是否等于目标
			if (buffer.count(target - nums[i]))
			{
				result[0] = buffer.at(target - nums[i]);
				result[1] = i;
				break;
			}

			//向Buffer记录已经算过的值
			buffer[nums[i]] = i;
		}
		return result;
	}
};

int main()
{
	std::cout << "两数之和" << std::endl;

	std::vector<int> nums = {3,2,4};

	std::vector<int> result = Solution::twoSum(nums, 6);

	for (int it : result)
	{
		std::cout << it << " ";
	}
	return 0;
}


