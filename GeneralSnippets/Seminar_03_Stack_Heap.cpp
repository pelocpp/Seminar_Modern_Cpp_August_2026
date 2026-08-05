
#include <print>


struct Point
{
    int x;
    int y;
};


void demo(int&& n)
{
}

void zuReferenzen()
{
    int n = 123;

    demo(123);

//    int& rn = nullptr;

    Point p = { 1, 2 };

    Point& rp = p;
}

void malZwei(int value)
{
    int m = value;

    value = value * 2;
}


void malZweiEx(int& value)
{
    int m = value;

    value = value * 2;
}

void stack_vs_heap()
{
    int n = 123;   // STACK !!!!!!!

    int* heapVar = new int(123);  // HEAP

    // irgendwann: MUSS delete kommen
    delete heapVar;
}


void main_seminar_stack_heap()
{
    int n = 10;

    std::println("{}", n);

    malZwei(n);
    malZweiEx(n);

    std::println("{}", n);

    stack_vs_heap();
}
