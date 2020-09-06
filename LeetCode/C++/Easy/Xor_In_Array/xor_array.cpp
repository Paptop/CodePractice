#include <iostream>

int xorOperation(int n, int start)
{
    int res = 0;
    
    for(int i = 0; i < n ; ++i)
    {
        res ^= start + 2 * i;
    }

    return res;
}

int main()
{    
    std::cout << xorOperation(5, 0) << std::endl;
    return 0;
}
