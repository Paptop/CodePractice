#include <iostream>

int subtractProductAndSum(int n)
{
    int sum = 0;
    int prod = 1;

    while(n)
    {
        int digit = n % 10;
        sum += digit;
        prod *= digit;
        n /= 10;
    }

    return (prod - sum);
}

int main()
{
    std::cout << subtractProductAndSum(4421) << std::endl;
    return 0;
}
