#include "Figures.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    rect r(2, 3);
    r.cdraw();
    r.draw();
    cout << endl;
    square sq(4);
    sq.cdraw();
    sq.draw();
    return 0;
}