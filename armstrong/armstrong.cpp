#include <iostream>
#include <cmath>
bool isArmstrong(int n){
    //The floor function is redundant because log10(n) + 1 will always be an integer when n is positive. Simply using static_cast<int>(log10(n)) + 1 would suffice.

    //int digits = floor(log10(n) + 1); //math formula to find number of digits in a number with any base
    if(n < 0) return false;
    int digits = static_cast<int>(log10(n)) + 1;
    int sum = 0;
    int placeholder = n;
    while(placeholder != 0){
        sum = sum + pow(placeholder%10,digits);
        placeholder/=10;
    }
    return sum == n;
}
int main()
{
    int n = -1;
    if(isArmstrong(n)) std::cout << "yes";
    else std::cout << "no!";

    //std::cout << sum;
}