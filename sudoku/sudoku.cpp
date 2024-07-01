#include <iostream>
#include <array>
using namespace std;
void print(array<int,9> arr){
    for(int i =0; i < (int)arr.size();++i ){
        cout << arr[i] << ' ';
        if(i == 2 || i == 5) cout << '\n';
    }
}
int main()
{
    array<int, 9> sudokuBox = {};
    srand(time(0));
    print(sudokuBox);
    for(int i =0; i< 4 )
    
}