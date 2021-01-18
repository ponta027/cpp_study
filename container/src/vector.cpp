#include <iostream>
#include <vector>

void intVectorSample( void );
void classVector( void );

void vectorSample( void )
{
    intVectorSample();
    classVector();
    return;
}



void intVectorSample( void )
{
    std::cout << "[START]vector sample" << std::endl;
    std::vector<int> intList;

    // push 
    intList.push_back(1);
    intList.push_back(3);
    intList.push_back(5);
    intList.push_back(7);

    // iterator  
    for( std::vector<int>::const_iterator it = intList.begin() , e = intList.end() ;it != e ; it++)
    {
        std::cout << *it << ",";
    }
    std::cout << std::endl;
    // simple iterator
    for( const auto& it:intList)
    {
        std::cout << it << ",";
    }
    std::cout << std::endl;

    int size = intList.size();
    std::cout << "vector size:" << size<< std::endl;

    // index access using at  and [] operator 
    std::cout << "element.at(" << size << "):"<<intList.at(size-1) << std::endl;
    std::cout << "element[" << size << "]:"<<intList[size-1] << std::endl;

    for( int i =0 ; i < size ; i++)
    {
       intList.pop_back();
    }
    // same intList.clear();
    
    if( intList.empty()){
        std::cout << "empty " << std::endl;
    }
    return;
}

class Person
{
    private:
        std::string name;
        int age;
    public:
        Person( std::string name, int age){ this->name = name; this->age = age;}
        std::string toString( void ){
            std::string s = name ;
            s += ":"+ std::to_string(age);
            return s;
        }
       

};
void classVector()
{

    std::vector<Person> personList;
    Person a("A", 40);
    Person b("B", 45);


    personList.push_back( a );
    personList.push_back( b );

    Person c = personList[1];
    std::cout << c.toString() << std::endl;
    return ;
}


