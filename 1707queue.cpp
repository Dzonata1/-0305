#include <iostream>
#include <list>
 
int main()
{
    std::list<int> numbers{ 1, 2, 3, 4, 5 };
  
    int first {numbers.front() };  
    int last { numbers.back() };  
 
    std::cout << "First: " << first << std::endl;
    std::cout << "Last: " << last << std::endl;
  
    
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
  
    
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    return 0; 
}





  





   