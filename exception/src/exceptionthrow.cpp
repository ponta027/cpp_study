#include <iostream>
#include <exception>

#define START_LOG()   std::cout << "[START]:"<<__func__ << std::endl
#define END_LOG()   std::cout << "[END]:"<<__func__ << std::endl


inline void printMessage()
{
    std::cout << __func__ << std::endl;
    return;
}
void func1(){ 
    START_LOG();
    
    try{ 
        throw "Exception type char ";
    }
    catch( char const* str)
    {
        std::cout << "catch const char:" << str << std::endl;
    }
    END_LOG();
    return;
}


void func2(){ 
    START_LOG();
    try{ 
        throw "Exception type char ";
    }
    catch(...)
    {
        std::cout << "catch any" << std::endl;
    }
    END_LOG();
    return;
}

void func3(){ 
    START_LOG();
    int a = 1;
    try{ 
        if( a == 0 )
        {
            throw "Exception type char ";
        }else{
            throw 1;
        }
    }
    catch( char const* str)
    {
        std::cout << "catch const char:" << str << std::endl;
    }
    catch( int a )
    {
        std::cout << "catch int" << a  << std::endl;
    }
    END_LOG();
    return;
}


class CustomError
{
        std::string message;
    public:
        CustomError( const std::string& msg ):message(msg){};
        std::string& toString(){ return message;}


};

void func4(){ 
    START_LOG();
    try{
        throw(CustomError("custom error"));
    }catch ( CustomError& e){
        std::cout << e.toString() << std::endl;
    }
    END_LOG();
    return ;
}
void func5(){ 
    START_LOG();
    throw(CustomError("custom error"));
    END_LOG();
    return ;
}


void func_noexcept () noexcept
{
    START_LOG();
    END_LOG();
    return;
}
typedef void (*funcPtr)();
funcPtr a[]={
    func1,
    func2,
    func3,
    func4,
    func_noexcept,
};

int main( int argc,char** argv)
{

    for( int i =0; i < sizeof(a)/sizeof(funcPtr); i++)
    {
        a[i]();
    }

    try{
        func5();
    }catch(  CustomError& error)
    {
        std::cout << "Catch Error recv message:" ;
        std::cout << error.toString()<< std::endl;
    }
    
    return 0;
}
