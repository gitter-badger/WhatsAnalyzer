#include <iostream>
#include <regex>
#include "Dialogue.h"

void test() {
    std::string content_p = "07.05.15 18:00:06: Brudiii ❤️: SCHO SCHLIMM!!";
    std::string droid = "08.27.2015, 19:54 - Christoph: Dann kimma uns ja no überlegen was ma nachher macha";
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9][0-9]:\\s*(.*?):\\s(([.]|[^.])*)",
                   std::regex_constants::icase);
    std::regex android("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4}),\\s([0-9]{2}):([0-9]{2})\\s\\-\\s*(.*?):\\s(([.]|[^.])*)",
                       std::regex_constants::icase);
    std::cmatch res;
    std::regex_search(droid.c_str(), res, android);
    for (int i = 0; i < res.size(); i++) {
        std::cout << i << "::::" << res.str(i) << std::endl;
    }
}

void testt() {
    std::string content_p = "08.27.2015, 19:54 - Christoph: Dann kimma uns ja no überlegen was ma nachher macha";
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9][0-9]:\\s*(.*?):\\s(([.]|[^.])*)",
                   std::regex_constants::icase);
    std::regex android("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4}),\\s([0-9]{2}):([0-9]{2})\\s\\-\\s*(.*?):\\s(([.]|[^.])*)",
                       std::regex_constants::icase);
    bool androidmode = false;
    std::regex regex;
    if (std::regex_match(content_p, android)) {
        androidmode = true;
        std::cout << "androidmode selected" << std::endl;
        regex = android;
    }
    else if (std::regex_match(content_p, iOS)) {
        std::cout << "iOS selected" << std::endl;
        regex = iOS;
    }
    std::cmatch res;
    std::regex_search(content_p.c_str(), res, regex);
    Message::processedMsg msg = {};
    struct tm time = {0};
    time.tm_mday = std::atoi(res.str(1).c_str());
    time.tm_mon = std::atoi(res.str(2).c_str());
    time.tm_hour = std::atoi(res.str(4).c_str());
    time.tm_min = std::atoi(res.str(5).c_str());
    msg.time = time;
    msg.participant = res.str(6);
    msg.content = res.str(7);
    if (androidmode) {
        time.tm_year = std::atoi(res.str(3).c_str());
    }
    else {
        time.tm_year = 2000 + (std::atoi(res.str(3).c_str()));
    }
    std::cout << 7 << "::::::" << res[7].str() << std::endl;
    return;
}


int main() {
    Dialogue d;
    std::string lesen = "ios.txt";
    d.setContentAndProcess(lesen);
    //testt();
    return 0;

}
