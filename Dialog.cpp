//
// Created by beatbrot on 31.08.15.
//

#include <iostream>
#include "Dialog.h"
#include "fstream"
#include "algorithm"
#include "Nachricht.h"

using namespace boost;
using namespace std;


void Dialog() {
}

bool processFile() {
    string temp;
    if (file.good()) {
        while (getline(file, temp)) {
            Nachricht n;
            //Dialog::participants.push_back("yolo");
        }
    }
    return true;
}

void Dialog::setContent(ifstream& f) {
    Dialog::file << f;
    processFile();
}

bool addParticipant(string p){
    if(find(Dialog::participants.begin(), Dialog::participants.end(), p)!=Dialog::participants.end()){
        Dialog::participants.push_back(p);
    }
}
