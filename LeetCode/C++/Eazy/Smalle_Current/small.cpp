#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

//brute force solution
std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums)
{
    std::unordered_map<int,int> mins;
    std::vector<int> res;
    res.resize(nums.size());

    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums.size(); ++j)
        {
            const int num = nums[i];

            if(mins.find(i) == mins.end())
            {
                mins[i] = 0;
            }

            if(nums[j] < num)
            {
                res[i] = ++mins[i];
            }
        }
    }

    return res;
}

std::vector<int> improved_smaller_numbers(std::vector<int>& nums)
{
    std::vector<int> res;
    res.resize(nums.size());

    std::multimap<int,int> tree;

    for(int i = 0 ; i < nums.size(); ++i)
    {
        tree.insert({nums[i], i});
    }

    int count = 0;
    int prev_value = -1;
    int prev_count = -1;
    for(const auto& values : tree)
    {
       if(prev_value != values.first)
       {
           res[values.second] = count;
           prev_count = count;
       }
       else
       {
           res[values.second] = prev_count;
       }

       prev_value= values.first;
       count++;
    }

    return res;
}

int main()
{
    std::vector<int> input = {7, 7, 7, 7, 7};
    std::vector<int> output = improved_smaller_numbers(input);
    std::for_each(output.begin(), output.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
