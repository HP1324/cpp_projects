#include <iostream>
#include <algorithm>
bool isPalindrome(std::string &str)
{
    for (int i = 0; i < (int)str.length(); ++i)
    {
        if (!(std::toupper(str[i]) >= 'A' && std::toupper(str[i]) <= 'Z'))
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
            {
                str[i] = ' ';
            }
        }
    }
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    int size = str.length();
    int reverseCounter = size - 1;

    for (int i = 0; i < size / 2; ++i)
    {
        // std::cout<< str[i] << ' '<< str[reverseCounter];
        if (std::toupper(str[i]) != std::toupper(str[reverseCounter]))
        {
            return false;
        }
        --reverseCounter;
    }
    return true;
}

int main()
{
    std::string str = "too, bad i ,hid a ,boot";

    if (isPalindrome(str))
    {
        std::cout << str << '\n';
        std::cout << "The string is a palindrome\n";
    }
    else
    {
        std::cout << str << '\n';
        std::cout << "The string is not a palindrome\n";
    }
}