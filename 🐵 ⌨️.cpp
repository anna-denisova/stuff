#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int main(){

    printf("Enter an input and see how much time it takes to generate that input from random characters.\n");
    printf("Similar to the infinite monkey theorem: https://en.wikipedia.org/wiki/Infinite_monkey_theorem \n> ");

    srand((unsigned)time(0));

    string text; 
    getline(cin, text);

    bool running = true;
    unsigned  long  long total_chars = 0;
    int current_character = 0;
    int count = 0;

    auto start = chrono::high_resolution_clock::now();
    
    while(running){
        ++total_chars;

        current_character = 32 + (rand() % 94);

        if (current_character != text[count]){
            printf("%c", current_character);
            count = 0;
        }else{
            //bolds only on unix/macos
            printf("\e[1m%c\e[0m", current_character);
            ++count;
        }

        if (count == text.length()){
            running = false;
        }
    }

    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start) / 24;

    int ms = duration.count() ;
    int s = floor(ms / 1000);
    ms %= 1000;

    int m = floor(s/60);
    s%=60;

    cout<<"\nFound "<<text<<" after "<<total_chars<<" chars generated in ";
    printf("%im, %is, %ims.\n", m, s, ms);

    return 0;
}
