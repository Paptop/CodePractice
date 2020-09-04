#include <iostream>

int number_of_steps(int num)
{
   int steps = 0;
   while(num != 0)
   {
       if(num % 2 == 0)
       {
           num /= 2;
       }
       else
       {
           num--;
       }

       steps++;
   }

   return steps;
}


int main()
{
    std::cout << number_of_steps(123) << std::endl;
    return 0;
}
