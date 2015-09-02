//
// Created by beatbrot on 01.09.15.
//

#ifndef WHATSANALYZER_MESSAGE_H
#define WHATSANALYZER_MESSAGE_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Message {

public:
    Message() { }

    std::string processMessage(std::string text);

    const boost::posix_time::ptime &getTimeOfMsg() const { return timeOfMsg; }

    const boost::gregorian::date &getDateOfMsg() const { return dateOfMsg; }

private:
    std::string content;
    boost::gregorian::date dateOfMsg;
    boost::posix_time::ptime timeOfMsg;

    void processDateOfMsg(std::string Date);
};


#endif //WHATSANALYZER_MESSAGE_H
