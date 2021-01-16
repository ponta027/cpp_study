# cpp_sample


## container



## call C function from C++

sample code 
c_from_cpp/main.cpp
c_from_cpp/sample.c
c_from_cpp/sample.h

```
$ nm sample.o
00000000 T function
         U printf
```

```
$ nm main.o
         U __aeabi_atexit
         U __aeabi_unwind_cpp_pr1
         U __dso_handle
         U function
000000c8 t _GLOBAL__sub_I__Z9function2v
00000038 T main
00000064 t _Z41__static_initialization_and_destruction_0ii
00000000 T _Z9function2v
         U _ZNSolsEPFRSoS_E
         U _ZNSt8ios_base4InitC1Ev
         U _ZNSt8ios_base4InitD1Ev
         U _ZSt4cout
         U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
00000000 r _ZStL19piecewise_construct
00000000 b _ZStL8__ioinit
         U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
```

function is different from function2 in symbol table.
In C lang, symbol name is same with function name.
but In C++, symbol name isn't equal with function name.
various compiler have diffrent symbol.


* name mangling 
In C++ , information such as argument type is added to function symbol name
in order to support multiple definition of function.

demangle function

```
nm --demangle main.o
         U __aeabi_atexit
         U __aeabi_unwind_cpp_pr1
         U __dso_handle
         U function
000000c8 t _GLOBAL__sub_I__Z9function2v
00000038 T main
00000064 t __static_initialization_and_destruction_0(int, int)
00000000 T function2()
         U std::ostream::operator<<(std::ostream& (*)(std::ostream&))
         U std::ios_base::Init::Init()
         U std::ios_base::Init::~Init()
         U std::cout
         U std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)
00000000 r std::piecewise_construct
00000000 b std::__ioinit
         U std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
```

C function is compiled by ex. gcc .
symbol name of function is not mangled. 
source code including main function is compiled by g++
so linker request mangling symbol.
Link error occured because the symbol can not found.

There are C Linkage and C++ Linkage in C++.
In default, set C++ Linkage.
C Linkage can be enabled by explicitly declaring it.
so , linker refer symbol of no mangling,
link object normaly.





