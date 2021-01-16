#include <iostream>
#include <limits.h>
#include "../inc/template_separate.h"


template <class X,class Y>
struct some{
    X x;
    Y y;
};

template <class T>
void Stack<T>::push(T x )
{
    if ( index_ < capacity_ ) { data_[index_++] = x;}
}
template <class T>
T Stack<T>::top () const
{
    return data_[index_ - 1];
}
template <class T>
void Stack<T>::pop( void )
{
    if( index_ > 0 ) --index_;
}

int main( int argc,char** argv)
{

    some<int , long> s;
    s.x = 10;
    s.y = LONG_MAX;
    Stack<int> stack(10);
    stack.push(1);
    stack.push(2);
    std::cout <<"expect 2=" << stack.top() << std::endl;
    stack.pop();
    std::cout <<"expect 1=" << stack.top() << std::endl;
    stack.pop();
    
    Stack< some<int,long> > stack2(10);
    Stack< decltype(s) > stack3(10);
    stack2.push({1,2});
    stack2.push({3,4});
    s = stack2.top();
    std::cout << s.x << std::endl;
    stack2.pop();
    s = stack2.top();
    std::cout << s.x << std::endl;
    

   
    return 0;
}
