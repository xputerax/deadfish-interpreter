#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *parse(char* program)
{
    int output = 0, n = 0, tmp = 0;
    int *container = NULL;

    for (int i=0; i<strlen(program); i++) {
        if (*(program+i) == 'o') output += 1;
    }

    container = malloc(output * sizeof(int));

    for (int i=0; i<strlen(program); i++) {
        char cmd = *(program+i);
        
        if (cmd == 'i') {
            tmp += 1;
        } else if (cmd == 'd') {
            tmp -= 1;
        } else if (cmd == 's') {
            tmp *= tmp;
        } else if (cmd == 'o') {
            container[n] = tmp;
            n += 1;
        }
    }

    return container;
}

int main(void)
{
    const int MAX = 5;
    int *container;

    container = parse("iiisdoso");

    for (int i=0; i<MAX; i++) {
        printf("container[%d] = %d\n", i, container[i]);
    }

    return 0;
}