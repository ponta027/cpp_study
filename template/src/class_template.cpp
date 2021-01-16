#include <iostream>
#include <limits.h>


template <class X,class Y>
struct some{
    X x;
    Y y;
};

// example Stack
template <class T>
class Stack
{
    T* data_;
    int index_;
    int capacity_;
    public:
        explicit Stack( int n): capacity_(n) ,index_(0)                           
    { data_ = new T[capacity_];}
        ~Stack(){ delete  data_;}
        void push(T x )
        {
            if ( index_ < capacity_ ) { data_[index_++] = x;}
        }
        T top( void ) const
        {
            return data_[index_ - 1];
        }
        void pop( void )
        {
            if( index_ > 0 ) --index_;
        }
};

int main( int argc,char** argv)
{

    some<int , long> s;
    s.x = 10;
    s.y = LONG_MAX;
    Stack<int> stack(10);
    Stack< some<int,long> > stack2(10);
    Stack< decltype(s) > stack3(10);

    stack.push(1);
    stack.push(2);
    std::cout <<"expect 2=" << stack.top() << std::endl;
    stack.pop();
    std::cout <<"expect 1=" << stack.top() << std::endl;
    stack.pop();
    
    return 0;
}
