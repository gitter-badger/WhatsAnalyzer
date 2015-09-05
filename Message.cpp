//
// Created by beatbrot on 01.09.15.
//

#include <iostream>
#include <boost/algorithm/string.hpp>

#include "Message.h"

std::string Message::processMessage(std::string text) {
    std::string::size_type pos = text.find('-', 0);
    std::string first = text.substr(0, pos);
    std::string second = text.substr(pos + 1);
    boost::erase_all(first, " ");
    std::string::size_type posComma = first.find(',', 0);
    std::string date = first.substr(0, posComma); //DATUM
    std::string time = first.substr(posComma + 1);  //ZEIT
    std::cout << date << std::endl;
    std::cout << time << std::endl;
    second = second.substr(1);
    std::string::size_type posDoublePoint = second.find(':', 1);
    std::string participant = second.substr(0, posDoublePoint);
    std::string message = second.substr(posDoublePoint + 2);
    std::cout << participant << std::endl;
    std::cout << message << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    return participant;
}

void Message::processDateOfMsg(std::string date) {
    //02.08.2015
    std::vector<std::string> parts;
    boost::split(parts, date, boost::is_any_of("."));
    boost::gregorian::date t(std::atoi(parts[0].c_str()), std::atoi(parts[1].c_str()), std::atoi(parts[2].c_str()));
    dateOfMsg = t;
}