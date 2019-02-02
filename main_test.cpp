#include <iostream>

template<typename T>
class Test{
public:
    T x;

    explicit Test(T x):
            x(x)
    {};

    void printX(){
        std::cout<<x<<std::endl;
    }
};

template<typename T>
void call_method(Test<T> test){
    test.printX();
}

template<typename ...TVals>
void f(int val, Test<TVals> ... args) {
    __attribute__((unused)) int dummy[] =  {0,((void)call_method(std::forward<Test<TVals>>(args)),0) ... };
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto t1 = Test<int>(1);
    auto t2 = Test<char>('a');
    auto t3 = Test<int>(3);

    f(0, t1, t2, t3);

    return 0;
}