#include <iostream>


class Person{
    std::string name;
    int age;
    public:
        
        Person( std::string name, int age){
            // self object alias this .
            //  if formal argument is equal member variable
            //  use this pointer avoiding name conflict.
            this->name = name;  
            this->age = age;
        }
        Person& operator=( const Person& person){
            this->name = person.name;
            return *this;
        }

        ~Person(){
            std::cout << " call Destructor: name=";
            std::cout << name ;
            std::cout << " age="<<age << std::endl;
        }
        std::string toString()
        {
            return name;
        }

};

int main( int argc,char** argv)
{
    std::cout << "START" << std::endl;
    Person a("A",40);
    Person b("B",10);
    a = b;
    std::cout << "a.toString():"<<a.toString() << std::endl;
    
    return 0;
}

