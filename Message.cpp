//
// Created by beatbrot on 01.09.15.
//

#include "Message.h"

void Message::addMessage(Message::processedMsg msg) {
    content = msg._content;
    time = msg._time;
    participant = msg._sender;
    flag = msg.flag;
}
