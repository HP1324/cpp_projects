#include<iostream>

bool isPrime(int n){
    if( n <= 1)return false;
    int factorCounter = 0;
    for(int i = 1; i <=n; ++i){
        if(n % i == 0) ++factorCounter;
    }
    return !(factorCounter > 2);
}
void testPrimeFunction(int nPrime){
    for(int i =1; i < nPrime; ++i){
        std::cout<< i << (isPrime(i) ? ": prime\n" : ": not prime\n");
    }
}
int main()
 {    
     //if(isPrime(6)) std::cout << "The number is a prime";
    //else std::cout << "The number is not a prime";
    testPrimeFunction(1000);
    
    return 0;
}