#include <iostream>

#include "Dialogue.h"


int main() {
    Dialogue d;
    std::string lesen = "test.txt";
    d.setContentAndProcess(lesen);
    getchar();
    return 0;
}
