#ifndef PERSON_H
#define PERSON_H

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


#endif
