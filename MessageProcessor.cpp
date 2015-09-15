//
// Created by beatbrot on 06.09.15.
//

#include "MessageProcessor.h"
#include "easylogging++.h"

Message::processedMsg MessageProcessor::process(std::string content_p, std::regex android, std::regex iOS) {
    std::regex regex;
    if (std::regex_match(content_p, android)) {
        LOG(INFO) << "androidmode selected";
        regex = android;
    }
    else if (std::regex_match(content_p, iOS)) {
        LOG(INFO) << "iOS selected for message";
        regex = iOS;
    }
    else {
        Message::processedMsg m;
        m.content = content_p;
        LOG(ERROR) << "No regex match found";
        return m;
    }
    std::cmatch res;
    std::regex_search(content_p.c_str(), res, regex);
    Message::processedMsg msg = {};
    struct tm time = {0};
    time.tm_mday = std::atoi(res[1].str().c_str());
    time.tm_mon = std::atoi(res[2].str().c_str());
    time.tm_hour = std::atoi(res[4].str().c_str());
    time.tm_min = std::atoi(res[5].str().c_str());
    time.tm_year = 2000 + (std::atoi(res[3].str().c_str()));
    msg.time = time;
    msg.participant = res[6].str();
    msg.content = res[7].str();
    return msg;
}
