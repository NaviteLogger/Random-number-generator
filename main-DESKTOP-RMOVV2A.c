#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool testLogiczny(int arr[], int ileLiczb, int zmienna) // funkcja sprawdzajaca, czy podany argument jest juz elementem tablicy. Jesli tak, zwraca 1, w przeciwnym wypadku zwraca 0
{
    for (int i = 0; i < ileLiczb; i++)
    {
        if (arr[i] == zmienna)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int czyKontynuowacDzialanie = 1;

    do
    {

        srand(time(NULL));
        printf("Generator liczb losowych generuje losowo liczby, bez powtorzen, z podanego zakresu.\n");
        int ileLiczb = 0;

        while (1) // petla sprawdzajaca wejscie uzytkownika odnoscie ilu liczb oczekuje od programu
        {
            printf("Podaj ile chcesz liczb:\n > ");
            scanf("%i", &ileLiczb);
            if (ileLiczb < 1)
            {
                printf("Podaj liczbe wieksza od 0!\n");
            }
            else
            {
                break; // wyjscie z petli po podaniu przez uzytkownika dodatniej wartosci
            }
        }

        int przedzial = 0;

        while (1)
        {
            printf("Podaj przedzial losowania:\n > ");
            scanf("%i", &przedzial);
            if (przedzial > ileLiczb)
            {
                break;
            }
            else if (przedzial == ileLiczb) // jesli uzytkownik poda zakres losowania rowny ilosci oczekiwanych liczb, to otrzymane liczby nie beda losowe, a jedynie w losowej kolejnosci
            {
                printf("Liczby nie beda losowe, a jedynie w losowej kolejnosci\n");
                break;
            }
            else
            {
                printf("Podano nieprawidlowy przedzial, liczby nie beda losowe! Sprobuj ponownie\n");
            }
        }

        int myArr[ileLiczb]; // wlasciwa tablica wylosowanych liczb
        int temp[ileLiczb];  // tablica tymczasowa uzywana do sprawdzenia, czy nowo wylosowany element juz istnieje w tablicy
        int zmienna = 0;     // zmienna tymczasowa uzywana do sprawdzenia, czy nowo wylosowany element juz istnieje w tablicy

        for (int i = 0; i < ileLiczb; i++)
        {
            do
            {
                zmienna = rand() % przedzial + 1;         // wylosowanie liczby z korekta odnosnie przedzialu, tak, aby program nie wylosowal 0
                if (testLogiczny(myArr, i, zmienna) == 1) // jesli element istnieje w tablicy
                {
                    continue; // przejdz do kolejnego losowania
                }
                else // w przeciwnym razie
                {
                    myArr[i] = zmienna; // dodaj go do tablicy
                    break;              // i przejdz do losowania kolejnej liczby
                }

            } while (testLogiczny(myArr, i, zmienna) == 1);
        }

        printf("Oto Twoje liczby losowe:\n");
        for (int i = 0; i < ileLiczb; i++) // petla wyswietlajaca tablice
        {
            printf("%i", myArr[i]);
            printf(" ");
        }
        printf("\n");

        printf("Czy chcesz ponowic losowanie? [T/N]\n > ");
        char odpowiedzUzytkownika;
        scanf(" %c", &odpowiedzUzytkownika);
        if (odpowiedzUzytkownika == 'T' || odpowiedzUzytkownika == 't') // jesli uzytkownik wpisze 'T' lub 't', program wroci do poczatku
        {
            czyKontynuowacDzialanie = 1;
        }
        else // w przeciwnym wypadku zakonczy dzialanie
        {
            czyKontynuowacDzialanie = 0;
            printf("OK, koncze program");
        }

    } while (czyKontynuowacDzialanie == 1);

    return 0;
}