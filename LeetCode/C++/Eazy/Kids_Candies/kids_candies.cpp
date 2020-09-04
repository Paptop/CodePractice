#include <iostream>
#include <vector>

std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
{
    std::vector<bool> res;
    res.resize(candies.size());

    int max = 0;
    for(int i = 0 ; i < candies.size(); ++i)
    {
        if(candies[i] >= max)
        {
            max = candies[i];
        }
    }

    for(int i = 0 ; i < candies.size(); ++i)
    {
        res[i] = (candies[i] + extraCandies) >= max;
    }

    return res;
}

void to_console(const std::vector<bool>& res)
{
    for(bool b : res)
    {
        std::cout << b << " ";
    }

    std::cout << std::endl;
}

int main()
{
   std::vector<int> candies = {4, 2, 1, 1, 2};
   std::vector<bool> res = kidsWithCandies(candies, 1);
   to_console(res);

   return 0;
}
