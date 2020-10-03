#include "hello.h"
#include <stdint.h>
#include<iostream>

bool Hello(std::string& name) {
    if(name.empty())
        return false;
    std::cout << "Hello, "<< name << std::endl;
    return true;
}