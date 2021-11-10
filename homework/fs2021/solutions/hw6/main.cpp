#include <iostream>

#include "Contestant.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Contestant theTeam[3];
    cout << endl;
    for(int i=0; i<3; i++) {
        theTeam[i].prepare();
        cout << endl;
    }

    cout << "Contest Summary:" << endl;
    for(int i=0; i<3; i++){
        theTeam[i].print();
        cout << endl;
    }

    skillLookUp(theTeam, 3);
    return 0;
}
