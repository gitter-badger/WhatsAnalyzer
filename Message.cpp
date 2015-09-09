//
// Created by beatbrot on 01.09.15.
//

#include "Message.h"

std::string Message::addMessage(Message::processedMsg msg) {
    content = msg.content;
    time = msg.time;
    participant = msg.participant;
    return participant;
}
