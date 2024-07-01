#include <iostream>
double convertTemperature(double temperature, char from, char to)
{
    switch (std::toupper(from))
    {
    case 'C':

        switch (std::toupper(to))
        {
        case 'F':
            return (temperature * 9 / 5) + 32.0;

        case 'K':
            return temperature + 273.15;

        default:
            return temperature;
        }

    case 'K':

        switch (std::toupper(to))
        {
        case 'F':
            return (temperature - 273.15) * 9 / 5 + 32;

        case 'C':
            return temperature - 273.15;

        default:
            return temperature;
        }

    case 'F':

        switch (std::toupper(to))
        {
        case 'C':
            return (temperature - 32) * 5 / 9;

        case 'K':
            return (temperature - 32) * 5 / 9 + 273.15;

        default:
            return temperature;
        }
        break;
    default:
        return temperature;
    }
}
int main()
{
    double temperature;
    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    char from, to;
    while (true)
    {
        std::cout << "Convert from: Type C for 'Celsius', K for 'Kelvin', F for 'Fahrenheit': ";
        std::cin >> from;
        if (std::toupper(from) == 'C' || std::toupper(from) == 'K' || std::toupper(from) == 'F')
        {
            break;
        }
        else
        {
            std::cout << "Invalid input! Please enter a valid character (C, K, F).\n";
        }
    }
    while (true)
    {
        std::cout << "Convert to: Type C for 'Celsius', K for 'Kelvin', F for 'Fahrenheit': ";
        std::cin >> to;
        if (std::toupper(to) == 'C' || std::toupper(to) == 'K' || std::toupper(to) == 'F')
        {
            break;
        }
        else
        {
            std::cout << "Invalid input! Please enter a valid character (C, K, F).\n";
        }
    }

    double result = convertTemperature(temperature, from, to);
    std::cout << "Result: " << result << '\n';
}
