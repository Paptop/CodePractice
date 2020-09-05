#include <iostream>
#include <vector>

void to_console(const std::vector<int>& arr)
{
    std::for_each(arr.begin(), arr.end(),[](int v){ std::cout << v << " "; });
    std::cout << std::endl; 
}

std::vector<int> decompress_rlelist(std::vector<int>& nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i += 2)
    {
        const int freq = nums[i];
        const int value = nums[i + 1];
        
        for(int j = 0; j < freq; ++j)
        {
            res.push_back(value);
        }
    }

    return res;
}

int main()
{
    std::vector<int> input = {1, 1, 2, 3};
    to_console(decompress_rlelist(input));
    return 0;
}
