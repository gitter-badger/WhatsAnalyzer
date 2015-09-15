//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "MessageProcessor.h"
#include "Dialogue.h"


bool Dialogue::processFile() {
    std::string temp;
    //02.09.2015, 17:16 - Christoph: Reuschl
    std::regex android("([0-9]{2})\\.([0-9]{2})\\.[0-9]{2}([0-9]{2}),\\s([0-9]{2}):([0-9]{2})\\s\\-\\s*(.*?):\\s(.*)",
                       std::regex_constants::icase | std::regex_constants::ECMAScript);
    std::regex iOS("([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9]{2}:\\s*(.*):\\s([^.|.]*)",
                   std::regex_constants::icase | std::regex_constants::ECMAScript);
    if (_file.good()) {
        int i = 0;
        while (getline(_file, temp)) {
            if (temp != "") {
                Message m;
                std::string participant = m.addMessage(MessageProcessor::process(temp, android, iOS));
                if (participant == "") {
                    _nachrichten[_nachrichten.size()].content += m.content;
                }
                else {
                    addParticipant(participant);
                    _nachrichten.push_back(m);
                }
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
