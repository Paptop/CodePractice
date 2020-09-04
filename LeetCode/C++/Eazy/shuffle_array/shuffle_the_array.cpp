#include <iostream>
#include <algorithm>
#include <vector>

// 0 (0 + 3) 1 (1 + 3) 2 (2 + 3) 
// 0   1     2    3    4    5


//Solution not effective memory cost
std::vector<int> shuffle(const std::vector<int>& nums, int n)
{
    std::vector<int> res;

    for(int i = 0 ; i < n; ++i)
    {
        const int jj = i + n;

        res.push_back(nums[i]);
        res.push_back(nums[jj]);
    }

    return res;
}

std::vector<int> shuffle_memory(std::vector<int>& nums, int n)
{
    std::vector<int> res;
    res.resize(nums.size());

    for(int i = 0 ; i < n; ++i)
    {
        const int jj = i + n;
        res[i * 2] = nums[i];
        res[i * 2 + 1] = nums[jj];
    }
    
    return res;
}

void to_console(const std::vector<int>& arr)
{
    for(int i : arr)
    {
        std::cout << i << " " ; 
    }
    
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr  = {1, 2, 3, 4, 4, 3, 2, 1};
    std::vector<int> output  = shuffle_memory(arr, arr.size() / 2);
    to_console(output);
}
