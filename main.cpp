#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int VELICINA = 10;
const int MAX_IGRACA = 4;
const int MAX_IME = 50;

int Crveni_brojevi[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
int Crni_brojevi[] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

struct Igrac
{
    char ime[MAX_IME];
    float novac;
    int tipOklade;
    int brojOklade;
    float iznosOklade;
};

 