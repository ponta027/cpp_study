## ソースコードとヘッダファイルの分離

今までのコードをソースコードヘッダファイルを分割した場合の説明。

```c
└─sample
    ├─inc
    │      person.h
    │
    └─src
            person.cpp
```


* person.cpp

```c
#include <string>
#include <iostream>

#include "../inc/person.h"

using namespace sample;
void Person::sayHello(){
    std::cout << "Hello World "<< name << std::endl;
    return;
}
```

* person.h 

```
#ifndef PERSON_H_
#define PERSON_H_


namespace sample
{
    class Person{
    public:
        int age;
        std::string name;
        void sayHello();
    };
}



#endif /* PERSON_H_ */

```

* sample.cpp

```c
#include <iostream>
#include "sample/inc/person.h"
using namespace std;

int main(int argc, char **argv) {


	sample::Person test;
	test.name ="k-shibuya";
	test.sayHello();

	return 0;
}

```
