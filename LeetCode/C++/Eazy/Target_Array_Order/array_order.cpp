#include <iostream>
#include <algorithm>
#include <vector>

void to_console(const std::vector<int>& nums)
{
    for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;
}

std::vector<int> create_target_array(std::vector<int>& nums, std::vector<int>& indexes)
{
    std::vector<int> result;

    for(int i = 0 ; i < nums.size(); ++i)
    {
        int value = nums[i];
        int index = indexes[i];

        std::vector<int>::iterator it = result.begin() + index;
        result.insert(it,value);
    }

    return result;
}

int main()
{
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<int> indexes = {0, 1, 2, 2, 1};
    to_console(create_target_array(nums,indexes));
    return 0;
}
