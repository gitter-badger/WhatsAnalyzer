//
// Created by beatbrot on 31.08.15.
//

#ifndef WHATSANALYZER_DIALOGUE_H
#define WHATSANALYZER_DIALOGUE_H

#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Message.h"

class Dialogue {
public:
    Dialogue() { };

    ~Dialogue() { };

    std::ifstream _file;
    std::unordered_map<std::string, int> _participants;
    std::vector<Message> _nachrichten;
    void setContentAndProcess(std::string filename);

    void givePercentages();

private:
    bool processFile();
    void addParticipant(std::string p);
};


#endif //WHATSANALYZER_DIALOGUE_H
