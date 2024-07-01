#ifndef project_h
#define project_h

std::string reverse(const std::string& str){
    int size = str.length();
    std::string reverse(size, '\0');
    
    for(int i = size - 1; i >=0; --i){
        reverse[(size -1) -i] = str[i];
    }
    // str = reverse;
    return reverse;
}

#endif