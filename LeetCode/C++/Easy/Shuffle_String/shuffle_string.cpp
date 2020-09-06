#include <iostream>
#include <string>
#include <vector>

std::string restoreString(const std::string& s, const std::vector<int>& indices)
{
   std::string res;
   res.resize(s.size(), ' ');

   for(int i = 0 ; i < indices.size(); ++i)
   {
       res.replace(indices.at(i),1,1, s.at(i));
   } 

   return res;
}


int main()
{
    std::string str = "aiohn";
    std::vector<int> indices = {3,1,4,2,0};

    std::cout << restoreString(str, indices) << std::endl;
    return 0;
}
