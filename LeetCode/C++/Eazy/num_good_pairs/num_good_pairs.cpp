#include <iostream>
#include <unordered_map>
#include <vector>


//Brute force
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

//Knowing basic combinations 
//
// n * (n - 1) / 2 
//
// Finding the number of equal elements N
// Find the number of unique pairs using formula C(k,n) where

int num_indentical_pairs(std::vector<int>& nums)
{    
    std::unordered_map<int,int> pairs;
    int res = 0;

    for(int i = 0; i < nums.size(); ++i)
    {
        const int num = nums[i];

        if(pairs.find(num) == pairs.end())
        {
            pairs[num] = 1;
        }
        else
        {
            ++pairs[num];
        }
    }

    for(const auto& values : pairs)
    {
        res += values.second * (values.second - 1) / 2;
    }

    return res;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 1}; 
    std::cout << num_indentical_pairs(nums) << std::endl;

    return 0;
}
