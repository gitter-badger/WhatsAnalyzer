#include <iostream>
#include "Dialogue.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    Dialogue d;
    std::string lesen = "ios.txt";
    d.setContentAndProcess(lesen);
    //testt();
    return 0;
}
