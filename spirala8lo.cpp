// spirala8lo.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
using namespace std;

int main()
{
    // wielkosc tablicy(potrzebne do obliczen)
    static int size = 10;    
    // wierz i kolumna
    int row = 0, col = 0;
    // do mierzenia kolumn i tabeli
    int boundary = size - 1;
    int sizeLeft = size - 1;
    int flag = 1;
    // Zmienna do określenia ruchu
    // r = right, l = left, d = down, u = upper
    char move = 'r';
    int tab[10][10] = { 0 };
    for (int i = 1; i < size * size + 1; i++)
    {
        tab[row][col] = i;
        // switch-case do sprawdzenia nastepnego ruchu
        switch (move)
        {
        case 'r':
            col += 1;
            break;

        case 'l':
            col -= 1;
            break;

        case 'u':
            row -= 1;
            break;

        case 'd':
            row += 1;
            break;
        }
        if (i == boundary)
        {
            // Dodaje lewy rozmiar dla następnej granicy
            boundary += sizeLeft;
            // Jeśli zostały wykonane 2 obroty,
            // zmniejsz rozmiar w lewo o 1
            if (flag != 2)
            {
                flag = 2;
            }
            else
            {
                flag = 1;
                sizeLeft -= 1;
            }
            // switch-case aby obracac ruch
            switch (move)
            {
                // jesli prawa odwroc w dol
            case 'r':
                move = 'd';
                break;

                // jesli dol odwroc w lewo
            case 'd':
                move = 'l';
                break;

                // jesli lewo odwroc w gore
            case 'l':
                move = 'u';
                break;

                // jesli gora odwroc w prawo
            case 'u':
                move = 'r';
                break;
            }
        }
    }
    // wypisywanie tablicy
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            int n = tab[row][col];
            if (n < 10)
                cout << n << "\t";
            else
                cout << n << "\t";
        }
        cout << endl;
    }

    return 0;
}