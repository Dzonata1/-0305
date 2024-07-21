#include <iostream>
#include <queue>
 
int main()
{
    std::queue<std::string> queue;  
     if(queue.empty())
    {
        std::cout << "queue is empty" << std::endl;
    }
    std::cout << "queue size: " << queue.size() << std::endl;
    queue.push("ваня");
    queue.push("игорь");
    queue.push("костя");
 
    std::cout << "queue size: " << queue.size() << std::endl;
    std::cout << "First: " << queue.front() << std::endl;  
    std::cout << "Last: " << queue.back() << std::endl;
    while (!queue.empty())  
    {
        std::cout << queue.front() << std::endl;
        queue.pop();    
    }
}





  





   