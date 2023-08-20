#include <iostream>
#include <vector>
#include <map>


class Solution {
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result(2, -1);	//count, init value
		std::map<int, int> buffer ;

		for (int i = 0; i < nums.size(); i++) {
			//�жϻ����Ƿ����Ŀ��
			if (buffer.count(target - nums[i]))
			{
				result[0] = buffer.at(target - nums[i]);
				result[1] = i;
				break;
			}

			//��Buffer��¼�Ѿ������ֵ
			buffer[nums[i]] = i;
		}
		return result;
	}
};

int main()
{
	std::cout << "����֮��" << std::endl;

	std::vector<int> nums(3);
	nums[0] = 3;
	nums[1] = 2;
	nums[2] = 4;

	std::vector<int> result = Solution::twoSum(nums, 6);

	for (int it : result)
	{
		std::cout << it << std::endl;
	}
	return 0;
}


