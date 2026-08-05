
#include <string>
#include <concepts>


class IntCalculator
{
public:
    [[nodiscard]] static int add(int a, int b) { return a + b; };
    [[nodiscard]] static int sub(int a, int b) { return a - b; };
    [[nodiscard]] static int mul(int a, int b) { return a * b; };
    [[nodiscard]] static int div(int a, int b) { return a / b; };
};

class DoubleCalculator
{
public:
    [[nodiscard]] static double add(double a, double b) { return a + b; };
    [[nodiscard]] static double sub(double a, double b) { return a - b; };
    [[nodiscard]] static double mul(double a, double b) { return a * b; };
    [[nodiscard]] static double div(double a, double b) { return a / b; };
};

// andere Datentypen .................  Generischen Programmierung
// Man kann von Klassen auch eine abstrahierende Betrachtung wählen:
// Statt realer Datentypen: Stellvertreter für Datentypen
// Wo:  Im Kontext von Schablonen / Template
// Ein Template ist eine BESCHREIBUNG einer Klasse
// Wie gelange ich zu einer realen Klasse: Man instanziiert eine Schablone

template <typename T>
concept Number = std::integral<T> or std::floating_point<T>;

template <typename T>
    requires Number<T>
class Calculator
{
public:
    [[nodiscard]] static T add(T a, T b) { 
        return a + b;
    };
    [[nodiscard]] static T sub(T a, T b) { return a - b; };
    [[nodiscard]] static T mul(T a, T b) { return a * b; };
    [[nodiscard]] static T div(T a, T b) { return a / b; };
};


void main_seminar_templates()
{
    int result = IntCalculator::add(3, 4);

    double dresult = DoubleCalculator::add(6.7, 7.8);

    // Float:
    float f1 = 123.123f;
    float f2 = 13453.123f;
    float fresult = Calculator<float>::add(f1, f2);

    result = Calculator<int>::add(3, 4);

    std::string s1 = "ABC";
    std::string s2 = "DEF";

   // std::string sresult = Calculator<std::string>::add(s1, s2);
}
