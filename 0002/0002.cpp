#include <iostream>
#include <vector>

class Solution {
public:
	//ȡ�����ַ���Ȼ����β�Ƚ� ���ܲ�o(log2n)
	static bool isPalindrome(int x) {

		//����
		if (x < 0) return false;

		//1λ��
		if (x < 10) return true;

		//TODO β��0�ػ�����û���ǵ�
		if (x % 10 == 0 && x != 0) return false;

		//����ת����
		std::vector<int> nums;
		while (x / 10 > 0)
		{
			nums.push_back(x % 10);
			x = x / 10;
		}
		nums.push_back(x);

		//��β�ж�
		//������������ż����
		int mind = nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2;
		int i = 0;
		while (nums[i] == nums[nums.size() - 1 - i]) {
			if (i == mind) return true;
			i++;
		}

		return false;
	}

	//��׼�𰸣��������������ֱ�ӱȽ� ��һ��ѭ��
	static bool isPalindrome_nice(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;
		int t = x;
		long rev = 0;
		//��������
		while (t != 0) {
			rev = t % 10 + rev * 10;
			t = t / 10;
		}

		return rev == x;
	}
};

int main()
{
	std::cout << "������" << std::endl;
	int x = 121;
	std::cout << Solution::isPalindrome(x) << std::endl;
	return 0;
}