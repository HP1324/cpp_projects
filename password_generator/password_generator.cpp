#include <iostream>

char *generatePassword(int size)
{
    if (size < 4)
    {
        std::cerr << "Password must be atleast 4 characters long\n";
        return nullptr;
    }
    char chars[94]{};
    int count = 33;
    int charSize = sizeof(chars) / sizeof(*chars);
    for (auto i = 0; i < charSize; ++i)
    {
        chars[i] = (char)count++;
    }

    char *randomPass = new char[size + 1];
    // char randomPass[size];

    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        int n = rand() % charSize;
        randomPass[i] = chars[n];
    }
    randomPass[size] = '\0';
    return randomPass;
}
int main()
{
    char *password = generatePassword(10);
    if (password != nullptr)
    {
        std::cout << "Password: ";
        std::cout << password;
        delete[] password;
    }
}