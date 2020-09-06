#include <iostream>
#include <string>

// 0 1 2
// 1 . 1
//
//
// 0 1 2 3 4
//
// 1 [ . ] 2
//
//
std::string defangIPAddr(std::string& address)
{
    std::size_t pos = 0;
    while( (pos = address.find('.', pos + 1)) != std::string::npos)
    {
        address.insert(pos + 1, 1, ']');
        address.insert(pos,     1, '[');
        pos++;
    }

    return address;
}

int main()
{
    std::string str = "1.1.1.1";
    std::string res = defangIPAddr(str);
    std::cout << res << std::endl; 
    return 0;
}
