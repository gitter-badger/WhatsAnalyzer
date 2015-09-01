//
// Created by beatbrot on 01.09.15.
//

#include <iostream>
#include "Nachricht.h"
#include "string"
#include "boost/algorithm/string.hpp"

using namespace std;

void Nachricht(){

}
string addText(string t){
    string::size_type pos = t.find('-', 0);
    string first = t.substr(0, pos);
    string second = t.substr(pos+1);
    boost::erase_all(first, " ");
    string::size_type posComma = first.find(',', 0);
    string date = first.substr(0, posComma); //DATUM
    string time = first.substr(posComma+1);  //ZEIT
    cout << date << endl;
    cout << time << endl;
    second = second.substr(1);
    string::size_type posDoublePoint = second.find(':', 1);
    string participant = second.substr(0, posDoublePoint);
    string message = second.substr(posDoublePoint+2);
    cout << participant << endl; // TEILNEHMER
    cout << message << endl; // NACHRICHT
    return participant;
}

string Nachricht::nachricht(string text) {
    return NULL; //
}
