//
// Created by Christoph on 24.09.2015.
//

class IOSMessageProcessorImpl : public MessageProcessor {
public:
    virtual ~IOSMessageProcessorImpl() { };

    static const std::regex &get_regex() {
        static std::regex reg(
                "([0-9]{2})\\.([0-9]{2})\\.([0-9]{2})\\s([0-9]{2}):([0-9]{2}):[0-9]{2}:\\s*(.*):\\s([^.|.]*)",
                std::regex_constants::icase | std::regex_constants::ECMAScript);
        return reg;
    }
};