#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctime>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

#define MAX_IGRACA 4
#define MAX_IME 50
#define VELICINA 10
#define VELICINA_CRVENI 18
#define VELICINA_CRNI 18

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
    cout << "\nRulet je pao na broj: [" << kotac[broj] << "]\n";
    polje[VELICINA / 2][VELICINA / 2] = broj;

    for (int i = 0; i < VELICINA; i++)
    {
        for (int j = 0; j < VELICINA; j++)
        {
            cout << polje[i][j] << " ";
        }
        cout << "\n";
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

void prikazNaslov()
{
    cout << "\033[0;34m";
    cout << "               Boki i Brunci\n";
    cout << "\033[1;31m";
    cout << "     ______            _          _     _    \n ";
    cout << "    |  __ \\          | |        | |   | | \n";
    cout << "     | |__) |  _   _  | |   ___  | |_  | |_      \n ";
    cout << "    |  _  /  | | | | | |  / _ \\ | __| | __|  \n ";
    cout << "    | | \\ \\  | |_| | | | |  __/ | |_  | |_    \n";
    cout << "     |_|  \\_\\  \\____| |_|  \\___|  \\__|  \\__| \n";
    cout << "\033[0m";
}

void postaviOklade(Igrac *igrac)
{
    int unosIzbora = 0;

    do
    {
        cout << "Igrač " << igrac->ime << ", odaberite tip oklade:\n";
        cout << "1. Pojedinačni broj (0-36)\n";
        cout << "2. Parni brojevi\n";
        cout << "3. Neparni brojevi\n";
        cout << "4. Crveni brojevi\n";
        cout << "5. Crni brojevi\n";
        cout << "Unesite izbor (1-5): ";
        cin >> unosIzbora;

        if (unosIzbora < 1 || unosIzbora > 5)
        {
            cout << "Krivi unos. Molimo unesite broj između 1 i 5.\n";
        }
    } while (unosIzbora < 1 || unosIzbora > 5);

    igrac->tipOklade = unosIzbora;

    if (igrac->tipOklade == 1)
    {
        cout << "Unesite broj na koji želite da se kladite (0-36): ";
        cin >> igrac->brojOklade;
        while (igrac->brojOklade < 0 || igrac->brojOklade > 36)
        {
            cout << "Nevažeći broj! Molimo unesite broj između 0 i 36: ";
            cin >> igrac->brojOklade;
        }
    }

    cout << "Unesite iznos novca koji želite da uložite: ";
    cin >> igrac->iznosOklade;
    while (igrac->iznosOklade > igrac->novac || igrac->iznosOklade <= 0)
    {
        if (igrac->iznosOklade <= 0)
            cout << "Iznos mora biti pozitivan. Pokušajte ponovo: ";
        else
            cout << "Nemate dovoljno novca! Pokušajte s manjim iznosom: ";
        cin >> igrac->iznosOklade;
    }
}

bool jeCrveni(int broj)
{
    for (int i = 0; i < VELICINA_CRVENI; i++)
    {
        if (Crveni_brojevi[i] == broj)
            return true;
    }
    return false;
}

bool jeCrni(int broj)
{
    for (int i = 0; i < VELICINA_CRNI; i++)
    {
        if (Crni_brojevi[i] == broj)
            return true;
    }
    return false;
}

void provjeriOklade(Igrac *igrac, int rezultat)
{
    bool pogodak = false;

    switch (igrac->tipOklade)
    {
    case 1: 
        if (igrac->brojOklade == rezultat)
        {
            igrac->novac += igrac->iznosOklade * 36;
            pogodak = true;
            cout << "Čestitamo " << igrac->ime << "! Pogodili ste broj " << rezultat << "!\n";
        }
        break;
    case 2: 
        if (rezultat != 0 && rezultat % 2 == 0)
        {
            igrac->novac += igrac->iznosOklade * 1;
            pogodak = true;
            cout << "Čestitamo " << igrac->ime << "! Pogodili ste parni broj " << rezultat << "!\n";
        }
        break;
    case 3: 
        if (rezultat % 2 == 1)
        {
            igrac->novac += igrac->iznosOklade * 1;
            pogodak = true;
            cout << "Čestitamo " << igrac->ime << "! Pogodili ste neparni broj " << rezultat << "!\n";
        }
        break;
    case 4: 
        if (jeCrveni(rezultat))
        {
            igrac->novac += igrac->iznosOklade * 1;
            pogodak = true;
            cout << "Čestitamo " << igrac->ime << "! Pogodili ste crveni broj " << rezultat << "!\n";
        }
        break;
    case 5: 
        if (jeCrni(rezultat))
        {
            igrac->novac += igrac->iznosOklade * 1;
            pogodak = true;
            cout << "Čestitamo " << igrac->ime << "! Pogodili ste crni broj " << rezultat << "!\n";
        }
        break;
    }
    if (!pogodak)
    {
        igrac->novac -= igrac->iznosOklade;
        cout << igrac->ime << ", nažalost niste pogodili. Izgubili ste " << igrac->iznosOklade << ".\n";
    }
}
////
void spremiIgrace(const Igrac igraci[], int brojIgraca, const char *filename)
{
    ofstream f(filename);
    if (!f)
    {
        cout << "Ne mogu otvoriti datoteku za spremanje.\n";
        return;
    }
    for (int i = 0; i < brojIgraca; i++)
    {
        f << igraci[i].ime << " " << igraci[i].novac << "\n";
    }
    f.close();
}


void ucitajIgrace(Igrac igraci[], int &brojIgraca, const char *filename)
{
    ifstream f(filename);
    if (!f)
    {
        cout << "Ne mogu otvoriti datoteku za učitavanje.\n";
        return;
    }
    brojIgraca = 0;
    while (f >> igraci[brojIgraca].ime >> igraci[brojIgraca].novac)
    {
        igraci[brojIgraca].tipOklade = 0;
        igraci[brojIgraca].brojOklade = 0;
        igraci[brojIgraca].iznosOklade = 0;
        brojIgraca++;
        if (brojIgraca >= MAX_IGRACA)
            break;
    }
    f.close();
}
//
int main()
{
    srand(time(nullptr));
    Igrac igraci[MAX_IGRACA];
    int brojIgraca = 0;

    prikazNaslov();

    cout << "Unesite broj igraca (max " << MAX_IGRACA << "): ";
    cin >> brojIgraca;
    if (brojIgraca > MAX_IGRACA)
        brojIgraca = MAX_IGRACA;

    for (int i = 0; i < brojIgraca; i++)
    {
        cout << "Unesite ime igraca " << i + 1 << ": ";
        cin >> igraci[i].ime;

       