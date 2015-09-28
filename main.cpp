#include <iostream>
#include "Dialogue.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    el::Configurations conf("cfg.txt");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    std::string lesen = "droid.txt";
    Dialogue d;
    d.processFile(lesen);
    d.givePercentages();
    std::cout << "ende";
    return 0;
}