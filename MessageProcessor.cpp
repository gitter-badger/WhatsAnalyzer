//
// Created by beatbrot on 06.09.15.
//

#include "MessageProcessor.h"

Message::processedMsg MessageProcessor::process(std::string content_p) {
    std::regex android("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4}),\\s([0-9]{2}:[0-9]{2})\\s\\-\\s*(.*?):\\s(.*)",
                       std::regex_constants::icase);
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9][0-9]:\\s*(.*?):\\s(.*)",
                   std::regex_constants::icase);
    bool androidmode;
    std::regex regex;
    if (std::regex_match(content_p.begin, content_p.end(), android)) {
        androidmode;
        std::regex regex = android;
    }
    else if (std::regex_match(content_p.begin, content_p.end(), iOS)) {
        !androidmode;
        std::regex regex = iOS;
    }
    else {
        return NULL;
    }
    std::cmatch res;
    std::regex_search(content_p.c_str(), res, regex);
    Message::processedMsg msg = {};
    struct tm time = {0};
    time.tm_mday = std::atoi(res.str(0).c_str());
    time.tm_mon = std::atoi(res.str(1).c_str());
    if (androidmode) {
        time.tm_year = std::atoi(res.str(2).c_str());
    }
    else {
        time.tm_year = 2000 + (std::atoi(res.str(2).c_str()));
    }
    time.tm_hour = std::atoi(res.str(3).c_str());
    time.tm_min = std::atoi(res.str(4).c_str());
    msg.time = time;
    msg.participant = res.str(5);
    msg.content = res.str(6);
    return msg;
}
