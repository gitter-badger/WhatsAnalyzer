//
// Created by beatbrot on 06.09.15.
//

#ifndef WHATSANALYZER_MESSAGEPROCESSOR_H
#define WHATSANALYZER_MESSAGEPROCESSOR_H

#include <string>
#include <regex>

#include <time.h>
#include "Message.h"

class MessageProcessor {

public:
    struct processedMsg {
        std::string content;
        std::string participant;
        struct tm time = {0};
    };

    static Message::processedMsg process(std::string content_p, std::regex android, std::regex iOS);

};


#endif //WHATSANALYZER_MESSAGEPROCESSOR_H
