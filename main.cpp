#include <iostream>
#include <regex>

#include "Dialogue.h"

void test() {
    std::string content_p = "05.09.15 13:07:36: Chrissy ♛♡: xdddd";
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9][0-9]:\\s*(.*?):\\s(.*)",
                   std::regex_constants::icase);
    std::cmatch res;
    std::regex_search(content_p.c_str(), res, e);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res.str(i) << std::endl;
    }
}

int main() {
    bool testmode = true;
    if (!testmode) {
        Dialogue d;
        std::string lesen = "test.txt";
        d.setContentAndProcess(lesen);
        getchar();
        return 0;
    }
    test();
    getchar();
}
