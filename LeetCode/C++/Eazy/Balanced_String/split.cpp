#include <iostream>
#include <algorithm>
#include <string>

int balanced_string(std::string str)
{
    int total_balanced = 0;
    int l_count = 0;
    for_each(str.begin(), str.end(), [&l_count, &total_balanced](char c)
            {
                l_count += c == 'L';
                l_count -= c == 'R';
                total_balanced += l_count == 0;
            });

    return total_balanced;
}

int main()
{
    std::cout << balanced_string("RLRRLLRLRL") << std::endl;
    return 0;
}
