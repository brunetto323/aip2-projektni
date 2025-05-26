#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>

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

const int Crveni_brojevi[VELICINA_CRVENI] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
const int Crni_brojevi[VELICINA_CRNI] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

int zavrtiRulet()
{
    return rand() % 37; // 0-36
}

void prikazRuleta(int broj, int polje[VELICINA][VELICINA])
{
    const char *kotac[37] = {
        "00", " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
        "31", "32", "33", "34", "35", "36"};

    system("clear");
    printf("\nRulet je pao na broj: [%s]\n", kotac[broj]);
    polje[VELICINA / 2][VELICINA / 2] = broj;

    for (int i = 0; i < VELICINA; i++)
    {
        for (int j = 0; j < VELICINA; j++)
        {
            printf("%2d ", polje[i][j]);
        }
        printf("\n");
    }
}

void rotirajPolje(int polje[VELICINA][VELICINA])
{
    int temp[VELICINA][VELICINA];
    for (int i = 0; i < VELICINA; i++)
    {
        for (int j = 0; j < VELICINA; j++)
        {
            temp[j][VELICINA - 1 - i] = polje[i][j];
        }
    }
    for (int i = 0; i < VELICINA; i++)
    {
        for (int j = 0; j < VELICINA; j++)
        {
            polje[i][j] = temp[i][j];
        }
    }
}