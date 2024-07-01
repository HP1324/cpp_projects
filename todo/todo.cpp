#include <iostream>
const int MAX_TASKS = 100;
struct Task
{
    std::string title;
    std::string description;
};
Task tasks[MAX_TASKS];
int taskCount = 0;
void createTask()
{

    if (taskCount >= MAX_TASKS)
    {
        std::cout << "Task list is full!";
        return;
    }
    std::cout << "Enter task title: ";
    std::getline(std::cin, tasks[taskCount].title);
    std::cout << "Enter task description: ";
    std::getline(std::cin, tasks[taskCount].description);
    ++taskCount;
}
void viewTasks()
{
    if (taskCount == 0)
    {
        std::cout << "No tasks available\n";
        return;
    }
    std::cout << "********YOUR TASKS********\n\n";
    for (int i = 0; i < taskCount; ++i)
    {
        std::cout << i + 1 << ". " << tasks[i].title << " : " << tasks[i].description << '\n';
    }
}
void deleteTask()
{
    if (taskCount == 0)
    {
        std::cout << "No tasks to delete! " << '\n';
        return;
    }
    int taskNumber;
    std::cout << "Enter the task number to delete: ";
    std::cin >> taskNumber;
    std::cin.ignore();

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        std::cout << "Invalid Task Number! " << '\n';
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; ++i)
    {
        tasks[i] = tasks[i + 1];
    }
    --taskCount;
    std::cout << "Task deleted! " << '\n';
}
void showMenu()
{
    std::cout << "\nTo-Do List Application" << std::endl;
    std::cout << "1. Create task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Delete task" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose an option: ";
}
int main()
{
    int choice;
    while (true)
    {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
            createTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            deleteTask();
            break;
        case 4:
            std::cout << "Exiting...";
            return 0;
        default:
            std::cout << "That's not a valid input! try again.\n";
            break;
        }
    }
}