#include <iostream>
#include "Three.h"


int main(){

    
    Three a ("10000");
    Three b ("1");
    a.remove(b);
    std::cout << a << '\n';


    Three a2("120000");
    Three b2("2000");
    std::cout << a2 - b2 << '\n';
    return 0;
}