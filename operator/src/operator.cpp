#include <iostream>


using namespace std;

template<class T>
class NamedPtr{
    public:
        NamedPtr( const string& initName , T *initPtr);
        NamedPtr& operator=( const NamedPtr& rhs);
        void print(void)
        {
            cout << name << endl;
            cout << *ptr << endl;
        };
        string name;
        T* ptr;
};

template <class T>
NamedPtr<T>::NamedPtr( const string& initName, T* initPtr):name(initName),ptr(initPtr)
{
}

template <class T>
inline ostream& operator<<(ostream& out , const NamedPtr<T>& val)
{
    out << "================"<<endl;
    out <<val.name << endl;
    out <<*val.ptr << endl;
    out << "================"<<endl;

    return out;
}

template <class T>
NamedPtr<T>& NamedPtr<T>::operator=(const NamedPtr<T>& rhs)
{
    cout << "equal operator" << endl;
    if( this == & rhs)
    {
        return *this;
    }
    name = rhs.name;
    *ptr = *rhs.ptr;
    return *this;
}

//
int main( int argc,char** argv)
{
    string s = "TEST";
    string s2 = "TEST2";
    string* x = new string();
    string* y = new string();
    *y = "aaaa";
    NamedPtr<string> a( s , x);
    NamedPtr<string> b( s2 , y);

    cout << a << endl;
    a = b;
    cout << a << endl;
       
    return 0;
}
