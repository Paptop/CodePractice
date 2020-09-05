#include <iostream>
#include <unordered_map>
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

int binary_search(const std::vector<int>& arr, int l, int r, int value)
{
    while(l <= r)
    {
        int m = l + (r - l) / 2;

        if(arr[m] == value)
        {
            return m;
        }

        if(arr[m] < value)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return -1;
}

void remove_duplicates(std::vector<int>& arr)
{
    std::vector<int>::iterator it = arr.begin();

    int prev_value = -1;
    while(it != arr.end())
    {
        if(prev_value == (*it))
        {
            it = arr.erase(it);
        }
        else
        {
            prev_value = (*it);
            it++;
        }
    }
}

void to_console(const std::vector<int>& vec)
{
    std::for_each(vec.begin(), vec.end(), [](int i) { std::cout << i << " "; });
}

std::vector<int> improved_smaller_numbers(std::vector<int>& nums)
{
    std::vector<int> current_nums = nums;

    std::vector<int> res;
    res.resize(current_nums.size());

    std::sort(nums.begin(), nums.end());

    for(int i = 0 ; i < current_nums.size(); ++i)
    {
        const int value = current_nums[i];
        int index = binary_search(nums, 0, nums.size(), value);
        while(index > 0 && nums[index - 1] == value)
        {
            index--;
        }
        res[i] = index;
    }

    return res;
}

int main()
{
    std::vector<int> input = {7, 7, 7, 7, 7};
    auto output = improved_smaller_numbers(input);
    to_console(output);
    std::cout << std::endl;
    return 0;
}
