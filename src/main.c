#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int DAY_CYCLES = 5;
int cycles = 0;
int days = 0;

int disp_info() {
    printf("INFO:\n cycles: %d\n days: %d\n\n", cycles, days);

    return 0;
}

int init() {
    system("clear");
    printf("===DEFENSE GAME===\n\n");
    disp_info();

    return 0;
}

int handle_cmd(char *cmd, bool *running) {
    if(strcmp(cmd, "quit") == 0) {
        *running = false;
        system("clear");
    } else if(strcmp(cmd, "clear") == 0) {
        init();
    } else if(strcmp(cmd, "info") == 0) {
        disp_info();
    } else if (strcmp(cmd, "help") == 0) {
        printf("AVAILABLE COMMANDS:\n");
        printf(" help - displays this screen\n clear - clears the screen\n quit - quits the game\n info - displays info about game\n\n");
    } else {
        printf("INVALID COMMAND!\n\n");
    }
    
    return 0;
}

int main() {
    bool running = true;
    char cmd[20];
    init(cycles);
    while(running) {
        if (cycles == DAY_CYCLES) {
            cycles = 0;
            days++;
        }
        printf("#: ");
        scanf("%19s", &cmd);
        handle_cmd(cmd, &running);
        /* this is commented out because cycles should only increase on commands that matter, not on simple stuff like "clear", "info", "help", etc*/
        //cycles++;
    }
    return 0;
}

