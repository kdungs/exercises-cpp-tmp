#include "TMP/02/polymorphic_downcast.h"

#include <iostream>

struct A {
  virtual ~A() = default;
};

struct B : A {};


int main() {
  B b;
  A* aptr = &b;
  B* bptr = polymorphic_downcast<B*>(aptr);
  std::cout << bptr << '\n';

  A& aref = b;
  B& bref = polymorphic_downcast<B&>(aref);
  std::cout << &bref << '\n';
}
