#include <iostream>
#include "Dialogue.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    el::Configurations conf("cfg.txt");
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    Dialogue d;
    std::string lesen = "droid.txt";
    d.setContentAndProcess(lesen);
    d.givePercentages();
    std::cout << "ende";
    return 0;
}