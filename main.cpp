#include <iostream>
#include "Dialogue.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    Dialogue d;
    std::string lesen = "multiline.txt";
    d.setContentAndProcess(lesen);
    //testt();
    return 0;
}
