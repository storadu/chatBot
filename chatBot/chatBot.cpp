#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

#define MORE_LINES 1024
#define MORE_CHARS 1024

char** lines;
size_t total_lines = 0;
size_t total_chars = 0;

void citire() {
    FILE* file = fopen("Text.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return ;
    }


    lines = (char**)malloc(sizeof(char*) * MORE_LINES);

    
    char c;

    do {
        c = fgetc(file);
        if (ferror(file))
        {
            printf("Error reading from file.\n");
            return ;
        }
        if (feof(file)) {
            if (total_chars != 0) {
                lines[total_lines] = (char*)realloc(lines[total_lines], total_chars + 1);
                lines[total_lines][total_chars] = '\0';
                total_lines++;
            }
            break;
        }
        if (total_chars == 0) lines[total_lines] = (char*)malloc(MORE_CHARS);
        lines[total_lines][total_chars] = c;
        total_chars++;
        if (c == '\n')
        {
            lines[total_lines] = (char*)realloc(lines[total_lines], total_chars + 1);
            lines[total_lines][total_chars] = '\0';
            total_lines++;
            total_chars = 0;
            if (total_lines % MORE_LINES == 0)
            {
                size_t new_size = total_lines + MORE_LINES;
                lines = (char**)realloc(lines, sizeof(char*) * new_size);
            }
        }
        else if (total_chars % MORE_CHARS == 0)
        {
            size_t new_size = total_chars + MORE_CHARS;
            lines[total_lines] = (char*)realloc(lines[total_lines], new_size);
        }


    } while (true);
    lines = (char**)realloc(lines, sizeof(char*) * total_lines);
    fclose(file);

}
int main()
{
    citire();
    for (size_t i = 0; i < total_lines; i++)
        printf("%s", lines[i]);
    for (size_t i = 0; i < total_lines; i++)
        free(lines[i]);
    free(lines);
    

    return 0;
    /*fstream file;
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
    }*/


}
