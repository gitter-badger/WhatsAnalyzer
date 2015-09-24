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
                m.addMessage(MessageProcessor::process(temp));
                if (m.flag == 2) {
                    _messages.back().content += m.content;
                }
                else if (m.flag == 1) {
                    auto po = _participants.emplace(m.participant, 0);
                    po.first->second += 1;
                    _messages.push_back(m);
                }
            }
        }
        return true;
    }
    else {
        return false;
    }
}
void Dialogue::setContentAndProcess(std::string filename) {
    _file.open(filename);
    processFile();
}

//END OF INIT-STUFF

void Dialogue::givePercentages() {
    for (auto p: _participants) {
        int percentage = (int) (((float) p.second / (float) _messages.size()) * 100);
        std::cout << p.first << " schrieb " << (float) percentage << "% der Nachrichten" << std::endl;
    }
}
