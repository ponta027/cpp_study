## cast

* static_cast
    * 比較的安全な変換に使用。(int -> short , void* -> int* など)
* const_cast
    * const やvolatileを除去するために使用。
* dynamic_cast
    * ダウンキャストを行う際に使用。
* reinterrupt_cast
    * 互換性のないポインタの変換や整数型からポインタ型の変換に使います。

```eval_rst

.. literalinclude:: /_static/cast/cast.cpp
   :language: cpp
   :linenos:
   
```
