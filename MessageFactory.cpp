//
// Created by Christoph on 15.09.2015.
//

#include "MessageFactory.h"
#include "MessageProcessors/IOSMessageProcessorImpl.h"
#include "MessageProcessors/AndroidMessageProcessorImpl.h"
#include <fstream>

class MessageProcessorFactory {
public:
    template<typename T, typename... Args>
    static std::unique_ptr<MessageProcessor> get_processor(const std::string &line, T first) {
        return std::unique_ptr<MessageProcessor>(nullptr);
    }

    template<typename T, typename... Args>
    static std::unique_ptr<MessageProcessor> get_processor(const std::string &line, T first, Args... rest) {
        auto processed = first.process(line);
        if (processed.flag == 1) {
            return std::unique_ptr<T>(new T(first));
        }
        return get_processor(line, rest...);
    }


};


int processFile(std::string filename) {
    std::ifstream file;
    file.open(filename);
    std::unique_ptr<MessageProcessor> messageProcessor;
    try {
        std::string s;
        getline(file, s);
        auto p = MessageProcessorFactory::get_processor(s, AndroidMessageProcessorImpl(), IOSMessageProcessorImpl());
        messageProcessor.reset(p.get());
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    file.clear();
    std::string temp;
    if (file.good()) {
        while (getline(file, temp)) {
            Message m;
            m.addMessage(messageProcessor->process(temp));
            if (m.flag == 2) {
                _messages.back().content += m.content;
            }
            else if (m.flag == 1) {
                auto po = _participants.emplace(m.participant, 0);
                po.first->second += 1;
                _messages.push_back(m);
            }
        }
    }
    messageProcessor->process("");
    return 0;
}

