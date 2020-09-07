#include <iostream>
#include <vector>

int find_numbers(const std::vector<int>& nums)
{
    int even_count = 0;

    for(int i = 0 ; i < nums.size(); ++i)
    {
        int value = nums[i];
        int digit_count = 0; 

        while(value)
        {
            digit_count++;
            value /= 10;
        }

        even_count += (digit_count % 2 == 0);
    }

    return even_count;
}

int main()
{
    std::cout << find_numbers({555, 901, 482, 1771}) << std::endl;
    return 0;
}
