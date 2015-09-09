//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "MessageProcessor.h"
#include "Dialogue.h"


bool Dialogue::processFile() {
    std::string temp;
    std::regex android("([0-9]{2})\\.([0-9]{2})\\.([0-9]{4}),\\s([0-9]{2}:[0-9]{2})\\s\\-\\s*(.*?):\\s(([.]|[^.])*)",
                       std::regex_constants::icase);
    //08.05.15 07:01:56: Brudiii ❤️: Jaa
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9][0-9]:\\s([^:]*):\\s(.*)",
                   std::regex_constants::icase);
    if (_file.good()) {
        int i = 0;
        while (getline(_file, temp)) {
            if (temp != "") {
                Message m;
                addParticipant(m.addMessage(MessageProcessor::process(temp, android, iOS)));
                _nachrichten.push_back(m);
                std::cout << i++ << std::endl;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void Dialogue::addParticipant(std::string p) {
    if (std::find(_participants.begin(), _participants.end(), p) != _participants.end()) {
        _participants.push_back(p);
    }
}

void Dialogue::setContentAndProcess(std::string filename) {
    _file.open(filename);
    processFile();
}
