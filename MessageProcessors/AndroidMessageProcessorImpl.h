#include "../MessageFactory.h"

class AndroidMessageProcessorImpl : public MessageProcessor {
public:
    virtual ~AndroidMessageProcessorImpl() { };

    static const std::regex &get_regex() {
        static std::regex reg(
                "([0-9]{2})\\.([0-9]{2})\\.[0-9]{2}([0-9]{2}),\\s([0-9]{2}):([0-9]{2})\\s\\-\\s*(.*?):\\s(.*)",
                std::regex_constants::icase | std::regex_constants::ECMAScript);
        return reg;
    }
};