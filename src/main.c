#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int handle_cmd(char *cmd, bool *running) {
    if(strcmp(cmd, "quit") == 0) {
        *running = false;
    } else if(strcmp(cmd, "clear") == 0) {
        system("clear");
        printf("===DEFENSE GAME===\n\n");
    } else {
        printf("INVALID COMMAND!\n");
    }
    
    return 0;
}

int main() {
    bool running = true;
    char cmd[20];
    system("clear");
    printf("===DEFENSE GAME===\n\n");
    while(running) {
        printf("#: ");
        scanf("%19s", &cmd);
        handle_cmd(cmd, &running);
    }
    return 0;
}

