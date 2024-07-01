#include <iostream>
#include <cstdio>
using namespace std;
// int countLines(FILE * f){

// }
int main()
{
    const char *filename = "input.txt";
    const char *inputstr = "This string is meant to be written in a file called input.txt\n";
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < 10000; ++i)
    {
        fputs(inputstr, file);
    }
    fclose(file);
    int lineCount = 0;
    fopen(filename, "r");
    char buf[1024];
    while (fgets(buf, 1024, file))
    {
        // fputs(buf,stdout);
        cout << buf;
        if(buf[(sizeof(buf)/sizeof(*buf)) -1] !=0 ) ++lineCount;
    }
    fclose(file);
    cout << "File has " << lineCount << " lines\n";
    return 0;
}