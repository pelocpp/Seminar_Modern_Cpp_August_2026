
#include <vector>
#include <print>
#include <list>
#include <algorithm>

void main_seminar_stl_introduction_01()
{
    std::vector<std::size_t> numbers;

     numbers.reserve(80);
    // numbers.resize (20);

    // std::size_t n = -1;

    for (std::size_t i = 0; i != 100; i++) {

        numbers.push_back(2 *i);

        std::println("{:3d}: Size: {:3d}, Cap.: {:3d}", i, numbers.size(), numbers.capacity());
    }

    numbers.shrink_to_fit();

    std::println("Size: {:3d}, Cap.: {:3d}", numbers.size(), numbers.capacity());
}


void main_seminar_stl_introduction_02()
{
    std::vector<std::size_t> numbers;
    
    // Geht nicht ...
    //std::list<std::size_t> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (std::size_t i = 0; i != numbers.size(); i++) {

        std::println("{:3d}: {}", i, numbers[i]);  // []-Operator an std::list nicht vorhanden: Wegen Performanz
    }
}

void main_seminar_stl_introduction_03()
{
    std::vector<std::size_t> numbers;
    //std::list<std::size_t> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<std::size_t>::iterator pos = numbers.begin();

    if (pos == numbers.end()) {
        std::println("Done.");
        return;
    }
    std::size_t n = *pos;
    std::println("{}", n);

    ++pos;

    if (pos == numbers.end()) {
        std::println("Done.");
        return;
    }
    n = *pos;
    std::println("{}", n);


    ++pos;

    if (pos == numbers.end()) {
        std::println("Done.");
        return;
    }
    n = *pos;
    std::println("{}", n);

    ++pos;
    if (pos == numbers.end()) {
        std::println("Done.");
        return;
    }
    n = *pos;
    std::println("{}", n);
}

void main_seminar_stl_introduction_04()
{
    // std::vector<std::size_t> numbers;
    std::list<std::size_t> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    //std::vector<std::size_t>::iterator pos = numbers.begin();
    //std::vector<std::size_t>::iterator end = numbers.end();

    auto pos = numbers.begin();
    auto end = numbers.end();

    for (; pos != end; ++pos) {

        std::size_t n = *pos;
        std::println("{}", n);
    }
}

class Addierer
{
public:
    // static int add(int a, int b) { return a + b; };

    int operator () (int a, int b)
    {
        return a + b;
    }

    int operator () (int a, int b, int c)
    {
        return a + b + c;
    }
};


void main_seminar_stl_introduction_05()
{
    Addierer myAdder;

    int result = myAdder(3, 4, 5);

    result = myAdder.operator()(6, 7, 8);  // Spielerei
}

// void fun(const Type& a);

// globale Funktion // freie Funktion
void printMe(std::size_t n)
{
    std::println("==> {}", n);
}

class Printer
{
private:
    std::string m_header;

public:
    Printer() : m_header("==>") {}
    Printer(std::string header) : m_header(header) {}

    //void printMeToo(std::size_t n)
    //{
    //    std::println("{} {}", m_header, n);
    //}

    void operator() (std::size_t n)
    {
        std::println("{} {}", m_header, n);
    }
};



//void printMe(std::string header, std::size_t n)
//{
//    std::println("{} {}", header, n);
//}

void main_seminar_stl_introduction_06()
{
    std::vector<std::size_t> numbers;
    //std::list<std::size_t> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    Printer myPrinter("--> ");

    std::for_each(
        numbers.begin(),
        numbers.end(),
        myPrinter
    );

}

void main_seminar_stl_introduction()
{
    main_seminar_stl_introduction_06();
}
