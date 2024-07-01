#include <iostream>
#include<sstream>
int main()
{
    std::string input = "Test string";

    std::istringstream iss(input);

    std::string word;
    int wordCount = 0;
    while(iss >> word){
        ++wordCount;
    }

    std::cout << "Number of words: " << wordCount;
}