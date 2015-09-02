//
// Created by beatbrot on 31.08.15.
//

#ifndef WHATSANALYZER_DIALOGUE_H
#define WHATSANALYZER_DIALOGUE_H

#include <boost/algorithm/string.hpp>
#include <string>
#include <fstream>

#include "Message.h"

class Dialogue {

public:
    Dialogue() { };

    virtual ~Dialogue() { }

    void setContentAndProcess(std::string filename);

private:
    std::ifstream _file;
    std::vector<std::string> _participants;
    std::vector<Message> _nachrichten;

    bool processFile();

    void addParticipant(std::string p);
};


#endif //WHATSANALYZER_DIALOGUE_H
