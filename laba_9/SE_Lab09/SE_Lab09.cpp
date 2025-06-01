#include <iostream>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "ivarparm" << endl;
    cout << ivarparm(1, 5) << endl;
    cout << ivarparm(2, 5, 6) << endl;
    cout << ivarparm(3, 5, 6, 7) << endl;
    cout << ivarparm(7, 1, 2, 3, 4, 5, 6, 7) << endl;

    cout << endl << "svarparm" << endl;
    cout << svarparm(1, 5) << endl;
    cout << svarparm(2, 5, 6) << endl;
    cout << svarparm(3, 5, 6, 7) << endl;
    cout << svarparm(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;

    cout << endl << "fvarparm" << endl;
    cout << fvarparm(5.0, FLT_MAX) << endl;
    cout << fvarparm(5.0, 6.0, FLT_MAX) << endl;
    cout << fvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, FLT_MAX) << endl;

    cout << endl << "dvarparm" << endl;
    cout << dvarparm(5.0, DBL_MAX) << endl;
    cout << dvarparm(5.0, 6.0, DBL_MAX) << endl;
    cout << dvarparm(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, DBL_MAX) << endl;
    return 0;
}
