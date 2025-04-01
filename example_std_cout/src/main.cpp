#include <std_cout/std_cout.hpp>

int main() {
    StdCout cout;
    cout.info("hello");
    cout.info("1234");
    cout.info(10.0);
    cout.info(true);
    cout.info(false);
    cout.info("name", ": Gunther", "a:", 10.0, "b:", true, "c:", 1);
    cout.info("name", ": Gunther", "a:", 10.0, "b:", false, "c:", 1);
    std::cout << std::endl;
    
    cout.warn("hello", "world");
    float a = 1.5;
    bool b = true;
    int c = 10;
    cout.warn("hello", "world", "a:", a, "b:", b, "c:", c);
    cout.warn("hello", "world", "a:", a, "b:", b, "c:", c, "res:", true);
    std::cout << std::endl;
    
    cout.error("ERROR" ": unknown");
    std::string world = "WORLD";
    a = 3.14;
    b = false;
    c = 100;
    cout.error("hello", world, "a:", a, "b:", b, "c:", c);
    cout.error("hello", world, "a:", a, "b:", b, "c:", c, "res:", false);
}