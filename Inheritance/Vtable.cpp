#include <iostream>
using namespace std;

class NonVirtualClass {
 public:
  void foo() {}
};

class VirtualClass {
 public:
  virtual void foo() {}
};

int main() {
  cout << "Size of NonVirtualClass: " << sizeof(NonVirtualClass) << endl;
  cout << "Size of VirtualClass: " << sizeof(VirtualClass) << endl;
}
