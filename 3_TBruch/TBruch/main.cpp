#include <iostream>
#include "bruch.h"

using namespace std;

int main()
{

CBruch bruch(12.45);

cout << "Der bruch ist: " << bruch.zaehler << "/" << bruch.nenner << endl;
}
