#include <iostream>
#include <vector>
#include <deque>

bool ifAllNumsHaveDuplicates(std::vector<int> vec_nums)
{
	std::deque<int> nums;
	int arr[32];
	int mod = 0;
	int n = 0;
	int max = n;
	int tmp;
	int zero_count = 0;
	int res = 0;
	std::vector<std::deque<int>> binary_vec;

	for (int i = 0; i < vec_nums.size(); i++)
	{
		int num = vec_nums[i];

		while (num > 0)
		{
			mod = num % 2;
			arr[i] = mod;
			num = num / 2;
			nums.push_front(arr[i]); 
			
			tmp = n;
			n = nums.size();

			if (n > tmp)
			{
				max = n;
				tmp = max;
			}
		}
		binary_vec.push_back(nums);
		nums.clear();
	}

	for (int i = 0; i < binary_vec.size(); i++)
	{
		for (int j = 0; j < binary_vec[i].size(); j++)
		{
			if (binary_vec[i].size() < max)
			{
				zero_count = max - binary_vec[i].size();
				binary_vec[i].push_front(0);
			}
			std::cout << "binary_nums[" << i << "][" << j << "]" << binary_vec[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::vector<int> result_vec(binary_vec[0].begin(), binary_vec[0].end());

	for (int i = 1; i < binary_vec.size(); i++)
	{
		for (int j = 0; j < max; j++)
		{
			res = result_vec[j] ^ binary_vec[i][j];
			result_vec[j] = res; 

			std::cout << res << " ";
		}
		std::cout << std::endl;
	}

	auto it = std::find_if(result_vec.begin(), result_vec.end(), [](int xor_res) {return xor_res == 1; });
	if (it != result_vec.end())
	{
		std::cout << "One number does not have duplicate\n";
		return false;
	}
	else
	{
		std::cout << "All numbers have duplicates\n";
		return true;
	}
}

int main()
{
	std::vector<int> vec;

	vec.push_back(3);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(9);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(8);

	bool func = ifAllNumsHaveDuplicates(vec);

	return 0;
}

