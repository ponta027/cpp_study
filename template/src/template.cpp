#include <iostream>

class Sample{
    public:
        int num;
       Sample(int i ) { num = i;};
       // Sample operator+(Sample x , Sample y)
       Sample& operator+(Sample& x )
       {
           std::cout << "Input:"<<x.num << std::endl;
           std::cout << "Output:"<<this->num << std::endl;
           this->num = x.num + this->num;
           return *this ;
       }
};
struct coord
{
    int x;
    int y;
};


// function template
template <typename T>
T add( T a , T b )
{
    return a + b;
}


template <>
coord add( coord a, coord b)
{
    coord result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}


int main( int argc ,char** argv)
{
    std:: cout << add ( 1,2) << std::endl;
    /* compile error
    std:: cout << add ( 1,'A') << std::endl;
    */
    std:: cout << add<int> ( 1,'A') << std::endl;
    std:: cout << add<std::string> ("A","B") << std::endl;
    std:: cout << add<float> ( 1.1 ,'A') << std::endl;

    Sample a1(1);
    Sample a2(2);
    Sample a3(0);
//    a3= a1 + a2;
    a3 = add<Sample>(a1,a2);
    std::cout << "RESULT:" << a3.num << std::endl;

    coord a ={1,2};
    coord b ={1,2};
    coord c = add<coord>(a,b);


    std::cout <<"{c.x,c.y}={"<<  c.x <<":"<< c.y <<"}"<< std::endl;

    return 0;
}
