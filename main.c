#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool testLogiczny(int arr[], int temp[], int ileLiczb, int zmienna)
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
    srand(time(NULL));
    printf("Generator liczb losowych generuje losowo liczby, bez powtorzen.\n");
    printf("Podaj ile chcesz liczb:\n > ");
    int ileLiczb;
    scanf("%i", &ileLiczb);
    int przedzial;
    bool wartoscLogiczna = 1;

    while (1)
    {
        printf("Podaj przedzial losowania:\n > ");
        scanf("%i", &przedzial);
        if (przedzial <= ileLiczb)
        {
            printf("Wszystkie liczby nie beda losowe! Sprobuj ponownie\n");
        }
        else
        {
            break;
        }
    }

    int myArr[ileLiczb];
    int temp[ileLiczb];
    int zmienna;

    for (int i = 0; i < ileLiczb; i++)
    {
        do
        {
			zmienna = rand() % przedzial + 1;
            if (testLogiczny(myArr,temp,ileLiczb,zmienna)==1 == 1)
            {
                continue;
            }
            else
            {
				myArr[i] = zmienna;
				break;
            }
			
        } while (testLogiczny(myArr,temp,ileLiczb,zmienna)==1);
    }

    printf("\nOto Twoje liczby losowe:\n");
    for (int i = 0; i < ileLiczb; i++)
    {
        printf("%i", myArr[i]);
        printf(" ");
    }

    return 0;
}
