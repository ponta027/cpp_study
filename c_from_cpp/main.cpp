#include <iostream>
#include "sample.h"

void function2( void )
{
    std::cout << "function2" <<std::endl;
    return ;
}
int main(int argc,char** argv)
{
   function();
   function2();
   return 0;
}
