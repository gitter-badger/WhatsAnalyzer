//
// Created by beatbrot on 06.09.15.
//

#include "MessageProcessor.h"

Message::processedMsg MessageProcessor::process(std::string content_p, std::regex android, std::regex iOS) {
    bool androidmode = false;
    std::regex regex;
    if (std::regex_match(content_p, android)) {
        androidmode = true;
        //std::cout << "androidmode selected" << std::endl;
        regex = android;
    }
    else if (std::regex_match(content_p, iOS)) {
        //std::cout << "iOS selected" << std::endl;
        !androidmode;
        regex = iOS;
    }
    else {
        Message::processedMsg m;
        return m;
    }
    std::cmatch res;
    std::regex_search(content_p.c_str(), res, regex);
    Message::processedMsg msg = {};
    struct tm time = {0};
    time.tm_mday = std::atoi(res[1].str().c_str());
    time.tm_mon = std::atoi(res[2].str().c_str());
    time.tm_hour = std::atoi(res[4].str().c_str());
    std::cout << "n" << res[7].str() << "m" << std::endl;
    time.tm_min = std::atoi(res[5].str().c_str());
    if (androidmode) {
        time.tm_year = std::atoi(res[3].str().c_str());
    }
    else {
        time.tm_year = 2000 + (std::atoi(res[3].str().c_str()));
    }
    msg.time = time;
    msg.participant = res[6].str();
    msg.content = res[7].str();
    return msg;
}
