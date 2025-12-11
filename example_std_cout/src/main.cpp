#include <std_cout/std_cout.hpp>

int main() {
    StdCout cout;
    cout.info("hello~ information");
    cout.info("1234");
    cout.info(10.0);
    cout.info(true);
    cout.info(false);
    cout.info("name", ": Gunther", "a:", 10.0, "b:", true, "c:", 1);
    cout.info("name", ": Gunther", "a:", 10.0, "b:", false, "c:", 1);
    std::cout << std::endl;
    
    std::cout << "-----------------------\n";
    cout.good("Successful!");
    cout.good("1234");
    cout.good(100.0);
    cout.good(true);
    cout.good(false);
    cout.good("My name", ": Gunther", "a:", 10.0, "b:", true, "c:", 5);
    cout.good("Your name:", "Who are you", "a:", 25.10, "b:", false, "c:", 1111);
    std::cout << std::endl;
    
    std::cout << "-----------------------\n";
    cout.warn("hello", "world");
    float a = 1.5;
    bool b = true;
    int c = 10;
    cout.warn("hello", "world", "a:", a, "b:", b, "c:", c);
    cout.warn("hello", "yellow", "a:", a, "b:", b, "c:", c, "res:", true);
    std::cout << std::endl;

    std::cout << "-----------------------\n";
    cout.warnDev("dev-hello", "dev-world");
    a = 101.5;
    b = false;
    c = 30;
    cout.warnDev("dev", "warning", "a:", a, "b:", b, "c:", c);
    cout.warnDev("warning", "green", "a:", a, "b:", b, "c:", c, "res:", true);
    std::cout << std::endl;
    
    std::cout << "-----------------------\n";
    cout.error("ERROR" ": unknown");
    std::string world = "WORLD";
    a = 3.14;
    b = false;
    c = 100;
    cout.error("hello", world, "a:", a, "b:", b, "c:", c);
    cout.error("red", world, "a:", a, "b:", b, "c:", c, "res:", false);

    std::cout << "----- etc ----\n";
    struct MyCustom {
        int my_number;
    };
    MyCustom myCustom;
    myCustom.my_number = 1234;

    enum MyEnum {
        MY_CASE_1=0, MY_CASE_2, MY_CASE_DEFAULT
    };

    cout.info("my number:", myCustom.my_number);
    cout.good("My case:", MyEnum::MY_CASE_2);

}