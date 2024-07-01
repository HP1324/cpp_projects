#include <iostream>

int main()
{
    std::cout << "\n**********Welcome to Tasktio**********\n\n";
    std::cout << "Manage your tasks like a pro.....\n\n";
    std::cout << "**************************************\n";
 
    int n;

    std::cout << "You don't have any tasks yet, please create some tasks first,\n";
    std::cout << "How many tasks do you want to create? : ";
    std::cin >> n;
    std::string tasks[n * 2];
    int size = sizeof(tasks) / sizeof(tasks[0]);
    std::string title;
    std::string description;
    int counter = 0;
    for (int i = 0; i < size; i += 2)
    {
        std::cout << "Task " << ++counter << "--> Enter the title: ";
        std::getline(std::cin >> std::ws, title);
        std::cout << "          Enter the description: ";
        std::getline(std::cin >> std::ws, description);
        tasks[i] = title;
        tasks[i + 1] = description;
    }
    std::cout << n << " tasks created successfully\n\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout<< "Task ";
        if((i  + 1) %2 == 0) std::cout << i+ -1 << "--> "<< "Description: ";
        else std::cout << i + 1 << "--> " << "Title: ";
        std::cout << tasks[i] << '\n';
    }
}