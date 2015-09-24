//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "MessageProcessor.h"
#include "Dialogue.h"

//INIT-STUFF
bool Dialogue::processFile() {
    std::string temp;
    if (_file.good()) {
        while (getline(_file, temp)) {
            if (temp != "") {
                Message m = Message();
                std::string participant = m.addMessage(MessageProcessor::process(temp));
                if (m.flag == 2) {
                    _nachrichten.back().content += m.content;
                }
                else if (m.flag == 1) {
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
    _participants.emplace(p, 0);
}

void Dialogue::setContentAndProcess(std::string filename) {
    _file.open(filename);
    processFile();
}

//END OF INIT-STUFF

void Dialogue::givePercentages() {
    std::cout << _participants.size() << std::endl;
    for (auto &i : _nachrichten) {
        _participants[i.participant] += 1;
    }
}
