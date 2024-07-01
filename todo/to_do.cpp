#include <iostream>
void instruct()
{
    std::cout << "What do you want to do: \n";
    int input;

    std::cout << "1)Create New Task\n";
    std::cout << "2)Display Existing Tasks\n";
    std::cout << "3)Remove a task\n\n";
    std::cout << "Enter one of the above choices: ";
    std::cin >> input;
   // return input;
}
std::string* createTask()
{
    int n;
    std::cout << "How many tasks do you want to create? ";
    std::cin >> n;
    std::string title;
    std::string description;
    std::string* tasks = new std::string[n *2];

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Task " << i + 1 << "--> Enter the title: ";
        std::getline(std::cin >> std::ws, title);
        std::cout << "          Enter the description: ";
        std::getline(std::cin >> std::ws, description);
        tasks[i] = title;
        tasks[i + 1] = description;
    }
    delete tasks[];
    return tasks;
}
void showTasks(std::string* tasks[])
{
    
}
int main()
{
    std::cout << "\n**********Welcome to Taskito***********\n";
 //   int input = instruct();
    std::string* tasks[] = {createTask()};
    showTasks(tasks);
}