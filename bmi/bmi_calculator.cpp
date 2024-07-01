#include<iostream>
double calculateBmi(double weight, double height)
{
    height/=100;
    double bmi = weight /(height * height);
    return bmi;
}
int main()
{
    double weight;
    double height;
    std::cout << "Weight: ";
    std::cin >> weight;
    std::cout << "Height: ";
    std::cin >> height;


    std::cout << calculateBmi(weight, height);
}