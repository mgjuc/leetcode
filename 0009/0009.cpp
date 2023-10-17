#include <iostream>
#include <vector>

class Solution {
public:
	//取所有字符，然后首尾比较 性能差o(log2n)
	static bool isPalindrome(int x) {

		//负数
		if (x < 0) return false;

		//1位数
		if (x < 10) return true;

		//TODO 尾数0特化，我没考虑到
		if (x % 10 == 0 && x != 0) return false;

		//整数转数组
		std::vector<int> nums;
		while (x / 10 > 0)
		{
			nums.push_back(x % 10);
			x = x / 10;
		}
		nums.push_back(x);

		//首尾判断
		//最后的数，分奇偶处理
		int mind = nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2;
		int i = 0;
		while (nums[i] == nums[nums.size() - 1 - i]) {
			if (i == mind) return true;
			i++;
		}

		return false;
	}

	//标准答案：算出倒序整数，直接比较 ，一次循环
	static bool isPalindrome_nice(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;
		int t = x;
		long rev = 0;
		//整数倒序
		while (t != 0) {
			rev = t % 10 + rev * 10;
			t = t / 10;
		}

		return rev == x;
	}
};

int main()
{
	std::cout << "回文数" << std::endl;
	int x = 121;
	std::cout << Solution::isPalindrome(x) << std::endl;
	return 0;
}