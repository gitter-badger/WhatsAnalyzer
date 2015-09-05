#include <iostream>
#include <regex>

#include "Dialogue.h"

void test(std::string s) {
    //std::regex e("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4}),\\s([0-9]{2}:[0-9]{2})\\s\\-\\s*(.*?):\\s(.*)", std::regex_constants::icase);
    //02.19.2015, 17:50 - BöserBoy: Mei dad lasst mi ause weil i grad no döner essen war mit erm
    std::regex e("\\d");
    bool t = std::regex_match(s, e);
    std::cout << (t ? "richtig" : "falsch") << std::endl;
}
int main() {
//    Dialogue d;
//    std::string lesen = "test.txt";
//    d.setContentAndProcess(t("6");
    test("5");
    getchar();
    return 0;
}
