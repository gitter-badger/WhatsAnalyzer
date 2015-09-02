//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "Dialogue.h"


bool Dialogue::processFile() {
    std::string temp;
    if (_file.good()) {
        while (getline(_file, temp)) {
            Message n;
            addParticipant(n.processMessage(temp));
            _nachrichten.push_back(n);
        }
        return true;
    }
    return false;
}

void Dialogue::addParticipant(std::string p) {
    if (std::find(Dialogue::_participants.begin(), Dialogue::_participants.end(), p) != Dialogue::_participants.end()) {
        Dialogue::_participants.push_back(p);
    }
}

void Dialogue::setContentAndProcess(std::string filename) {
    Dialogue::_file.open(filename);
    processFile();
}
