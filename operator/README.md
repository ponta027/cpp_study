# operator 演算子

C++ではoperator演算子のオーバーロードすることができる。

演算子のoverloadはクラスのメンバー関数として定義。

基本的な型として以下のようになる。


```
type operator operator-symbol ( parameter-list )
```

| param | desc   |
|-------|--------|
|type|戻り値の型|
|operator-symbol|overloadする演算子|
|parameter-list|2項目のオペランドを受け取ります。<br/>左辺のオペランドは、暗黙的に this ポインタとして渡されます。<br/>演算子が受け取るオペランドの数を変更することはできません|

```
a + b 
```

を以下のように実行したものと考える。

```
a.+(b)
```

これにより、+ operatorの引数の型を何を実装すればよいか理解できる。
他のoperatorについても同様のアプローチでできる。



オーバーロードできる演算子

```
+	-	*	/	%	^
!	=	<	>	+=	-=
^=	&=	|=	<<	>>	<<=
<=	>=	&&	||	++	--
( )	[ ]	new	delete	&	|
~	*=	/=	%=	>>=	==
!=	,	->	->*

```



[samplecode](/operator/src/operator.cpp)
