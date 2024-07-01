#include<iostream>
//since it is inside the previous directory
#include "../project.h"
int main(){
    std:: string str = "gnirts desrever";
    std:: string reversed = reverse(str);
    std::cout << reversed;
    return 0;
}