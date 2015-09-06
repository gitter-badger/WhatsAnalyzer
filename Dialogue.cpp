//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "MessageProcessor.h"
#include "Dialogue.h"


bool Dialogue::processFile() {
    std::string temp;
    if (_file.good()) {
        while (getline(_file, temp)) {
            Message m;
            addParticipant(m.addMessage(MessageProcessor::process(temp)));
            _nachrichten.push_back(m);
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
