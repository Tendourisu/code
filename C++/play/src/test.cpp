#include <iostream>

class Test {
public:
    void sayHello() {
        std::cout << "Hello from Test class!" << std::endl;
    }
};

int main() {
    Test testObj;
    testObj.sayHello();
    return 0;
}