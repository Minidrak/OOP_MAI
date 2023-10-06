#include <iostream>
#include "Three.h"


int main(){

    
    Three ds1 {'1','2','0','1'};
    ds1.print(std::cout) << std::endl;

    Three ds2 {'2','1','0'};
    ds1.print(std::cout) << std::endl;

    std::cout << ds1.equals(ds2) << std::endl;
    std::cout << ds1.operator<(ds2) << std::endl;
    std::cout << ds1.operator>(ds2) << std::endl;
    return 1;
}