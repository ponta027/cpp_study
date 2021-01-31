# lambda 式

サンプル

```cpp
int main( int argc,char** argv)
{
auto plus = [](int a, int b) { return a + b; };
int result = plus(2, 3); // result == 5
return 0;
}
```

簡易的な関数オブジェクトをその場で定義できる機能。関数オブジェクトを一時的に作り名前をつけなくて良いため、[無名関数](https://ja.wikipedia.org/wiki/%E7%84%A1%E5%90%8D%E9%96%A2%E6%95%B0)と呼ぶ。

無名関数を定義した場合、コンパイラが一時的にオブジェクトを生成する。
caller側で一時的なオブジェクトが渡される様になる。



サンプルプログラムのオブジェクトｗ確認する。



```cpp
#include <iostream>

int main(int argc, char* argv[]) {
  auto plus = [](int a , int b ) {return a+b;};
  int ret = plus(2,3);
  return 0;
}
```

```
> nm --demangle lambda_sample
         U abort@@GLIBC_2.4
         U __aeabi_atexit@@CXXABI_ARM_1.3.3
00021038 B __bss_end__
00021038 B _bss_end__
00021030 B __bss_start
00021030 B __bss_start__
000104d4 t call_weak_fn
00021030 b completed.10395
00021028 D __data_start
00021028 W data_start
000104f8 t deregister_tm_clones
00010560 t __do_global_dtors_aux
00020ef8 t __do_global_dtors_aux_fini_array_entry
0002102c D __dso_handle
00020f00 d _DYNAMIC
00021030 D _edata
00021038 B _end
00021038 B __end__
00010714 T _fini
00010588 t frame_dummy
00020ef0 t __frame_dummy_init_array_entry
0001072c r __FRAME_END__
00021000 d _GLOBAL_OFFSET_TABLE_
00010694 t _GLOBAL__sub_I_main
         w __gmon_start__
00010430 T _init
00020ef8 t __init_array_end
00020ef0 t __init_array_start
0001071c R _IO_stdin_used
         w _ITM_deregisterTMCloneTable
         w _ITM_registerTMCloneTable
00020efc d __JCR_END__
00020efc d __JCR_LIST__
         w _Jv_RegisterClasses
00010710 T __libc_csu_fini
000106b0 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.4
000105f4 T main
00010528 t register_tm_clones
00010498 T _start
00021030 D __TMC_END__
00010630 t __static_initialization_and_destruction_0(int, int)
         U std::ios_base::Init::Init()@@GLIBCXX_3.4
         U std::ios_base::Init::~Init()@@GLIBCXX_3.4
00010720 r std::piecewise_construct
00021034 b std::__ioinit
000105c0 t main::{lambda(int, int)#1}::operator()(int, int) const
```
