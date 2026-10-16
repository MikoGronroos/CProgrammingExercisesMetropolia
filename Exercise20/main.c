#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main(void) {
    int user_level;

    printf("Enter debug level (0-4): ");
    if (scanf("%d", &user_level) != 1) {
        return 1;
    }

    set_debug_level(user_level);

    srand((unsigned int)time(NULL));

    for (int i = 1; i <= 5; i++) {
        int random_level = rand() % 5; 
        dprintf(random_level, "This is message number %d\n", i);
    }

    return 0;
}
