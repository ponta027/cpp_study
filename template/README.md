# template


## function template

create add function.

compile source and confirm object related add function 


```
$ nm --demangle template_sample  | grep add

00010fd8 W Sample add<Sample>(Sample, Sample)
00010fa8 W float add<float>(float, float)
00010f40 W int add<int>(int, int)
00010f70 W std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > add<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
```

object correspoding to type of used in source code was generated.



