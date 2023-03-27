//ai-ul despre care se vorbea la laboeator

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;


int main()
{
    fstream file;
    string word, t, q, filename;
    filename = "Text.txt";
    string propozitii[4][3];
    file.open(filename.c_str());
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            file >> word;
            propozitii[i][j] = word;
        }
    }
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        int random_integer;

        random_integer = 1 + (rand() % 4);
        cout << propozitii[random_integer - 1][i] << endl;
    }


}
