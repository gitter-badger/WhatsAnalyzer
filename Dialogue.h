//
// Created by beatbrot on 31.08.15.
//

#ifndef WHATSANALYZER_DIALOGUE_H
#define WHATSANALYZER_DIALOGUE_H

#include <string>
#include <fstream>
#include <vector>

#include "Message.h"

class Dialogue {
public:
    Dialogue() { };

    ~Dialogue() { };

    std::ifstream _file;
    std::vector<std::string> _participants;
    std::vector<Message> _nachrichten;
    void setContentAndProcess(std::string filename);

private:
    bool processFile();
    void addParticipant(std::string p);
};


#endif //WHATSANALYZER_DIALOGUE_H
