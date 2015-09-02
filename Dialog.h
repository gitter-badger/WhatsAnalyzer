//
// Created by beatbrot on 31.08.15.
//

#ifndef WHATSANALYZER_DIALOG_H
#define WHATSANALYZER_DIALOG_H

#include "boost/algorithm/string.hpp"
#include "string"
#include "fstream"
#include "Nachricht.h"

using namespace std;
class Dialog {

public:
    static fstream file;
    Dialog();
    static vector<string> participants;
    static vector<Nachricht> nachrichten;
    virtual ~Dialog() { }
    void setContent(ifstream&);

private:

    bool processFile();
};


#endif //WHATSANALYZER_DIALOG_H
