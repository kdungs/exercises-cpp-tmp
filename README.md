# C++ Template Metaprogramming

My solutions to the exercises in the book by David Abrahams and Aleksey
Gurtovoy. Other than the book, I'm using C++11/14 where applicable.  _Work in
progress_.

```
mkdir build
cd build
cmake -GNinja ../
ninja
```

You should get warnings about libraries with empty tables of content. That is
intended and fine, it means the code compiles which is all we care about here.
The actual tests are implemented in terms of `static_assert`.
