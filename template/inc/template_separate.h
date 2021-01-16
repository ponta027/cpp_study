
#ifndef __TEMPLATE_SEPARATE_H__
#define __TEMPLATE_SEPARATE_H__ 

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
        void push(T x );
        T top( void ) const;
        void pop( void );
};


#endif 
