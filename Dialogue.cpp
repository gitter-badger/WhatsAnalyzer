//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "MessageFactory.h"
#include "Dialogue.h"

//INIT-STUFF
void Dialogue::processFile(std::string filename) {
    MessageFactory messageFactory = {};
    std::pair<std::vector<Message>, std::unordered_map<std::string, int>> pair;
    pair = messageFactory.processFile(filename);
    pair.first = _messages;
    pair.second = _participants;
}

//END OF INIT-STUFF

void Dialogue::givePercentages() {
    for (auto p: _participants) {
        int percentage = (int) (((float) p.second / (float) _messages.size()) * 100);
        std::cout << p.first << " schrieb " << (float) percentage << "% der Nachrichten" << std::endl;
    }
}
