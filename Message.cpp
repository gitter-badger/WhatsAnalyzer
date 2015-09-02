//
// Created by beatbrot on 01.09.15.
//

#include <iostream>
#include <boost/algorithm/string.hpp>

#include "Message.h"

using namespace std;

string Message::processMessage(string text) {
    string::size_type pos = text.find('-', 0);
    string first = text.substr(0, pos);
    string second = text.substr(pos + 1);
    boost::erase_all(first, " ");
    string::size_type posComma = first.find(',', 0);
    string date = first.substr(0, posComma); //DATUM
    string time = first.substr(posComma + 1);  //ZEIT
    cout << date << endl;
    cout << time << endl;
    second = second.substr(1);
    string::size_type posDoublePoint = second.find(':', 1);
    string participant = second.substr(0, posDoublePoint);
    string message = second.substr(posDoublePoint + 2);
    cout << participant << endl;
    cout << message << endl;
    cout << "--------------------------------------" << endl;
    return participant;
}

void Message::processDateOfMsg(string date) {
    //02.08.2015
    std::vector<unsigned short> parts;
    boost::split(parts, date, boost::is_any_of('.'));
    boost::gregorian::date t(parts[0], parts[1], parts[2]);
    dateOfMsg = t;
}