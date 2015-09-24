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
        std::string _content;
        std::string _sender;
        struct tm _time = {0};
        int flag;
    };


    int flag;
//    #####################################
//    FLAG EXPLAINS THE TYPE OF THE Message
//        Flag -> Meaning
//        1 -> normal Message
//        2 -> multiline Message
//        3 -> Alert
//    #####################################

    void addMessage(processedMsg msg);
    std::string content;
    std::string participant;
    struct tm time = {0};
};


#endif //WHATSANALYZER_MESSAGE_H
