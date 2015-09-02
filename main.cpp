#include <iostream>
#include "fstream"
#include "boost/algorithm/string.hpp"
#include "Dialog.h"


using namespace std;

void test(string t);
int main() {
    ifstream lesen("test.txt");
    Dialog d;
    d.setContent(lesen);
    getchar();
    return 0;
}
void test(string t){
    //string t = "02.08.2015, 19:08 - BöserBoy: I know";
    //string t = "02.19.2015, 17:50 - BöserBoy: Mei dad lasst mi ause weil i grad no d�ner essen war mit erm";
    string::size_type pos = t.find('-', 0);
    string first = t.substr(0, pos);
    string second = t.substr(pos+1);
    boost::erase_all(first, " ");
    string::size_type posComma = first.find(',', 0);
    string date = first.substr(0, posComma); //DATUM
    string time = first.substr(posComma+1);  //ZEIT
    cout << date << endl;
    cout << time << endl;
    second = second.substr(1);
    string::size_type posDoublePoint = second.find(':', 1);
    string participant = second.substr(0, posDoublePoint);
    string message = second.substr(posDoublePoint+2);
    cout << participant << endl;
    cout << message << endl;
    cout << "--------------------------------------" << endl;
}