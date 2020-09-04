#include <iostream>
#include <vector>

int numIndenticalPairs(std::vector<int>& nums)
{
    int res = 0;
    for(int i = 0 ; i < nums.size(); ++i)
    {
        for(int j = i + 1; j < nums.size(); ++j)
        {
            res += nums[i] == nums[j];
        }
    }

    return res;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 1}; 
    std::cout << numIndenticalPairs(nums) << std::endl;

    return 0;
}
