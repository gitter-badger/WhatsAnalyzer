//
// Created by beatbrot on 01.09.15.
//

#ifndef WHATSANALYZER_MESSAGE_H
#define WHATSANALYZER_MESSAGE_H

#include <string>
#include <iostream>
#include <time.h>

class Message {

public:
    struct processedMsg {
        std::string content;
        std::string participant;
        struct tm time = {0};
    };

    std::string addMessage(processedMsg msg);
    std::string content;
    std::string participant;
    struct tm time = {0};
};


#endif //WHATSANALYZER_MESSAGE_H
