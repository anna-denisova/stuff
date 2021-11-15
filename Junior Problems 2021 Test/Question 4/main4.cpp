#include "std_lib_facilities.h"

// Bubble sort algorithm
void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int bubbleSort(string books)
{
    int counter = 0;
    int i, j;
    bool swapped;
    for (i = 0; i < books.size() - 1; i++)
    {
        swapped = false;
        for (j = 0; j < books.size() - i - 1; j++)
        {
            if (books[j] > books[j + 1])
            {
                swap(&books[j], &books[j + 1]);
                swapped = true;
                counter++;
            }
        }
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }

    return counter;
}

//calls bubbleSort func & couts max swaps 
int main()
{
    string str_books;
    cin >> str_books;

    int max_swaps = bubbleSort(str_books);
    cout << max_swaps;
    return EXIT_SUCCESS;
}
