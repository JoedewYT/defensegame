#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool running = true;
    char cmd[20];
    while(running) {
        system("clear");
        printf("===DEFENSE GAME===\n\n");
        fgets(cmd, 20, stdin);
        printf("%s", cmd);
    }
    return 0;
}