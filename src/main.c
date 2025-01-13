#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int DAY_CYCLES = 5;
int cycles = 0;
int days = 0;

struct Cannon_Struct
{
    int pitch;
    int yaw;
    int motor_health;
    int laser_health;
    int cooler_health;
};
struct Cannon_Struct cannon = {0,0,100,100,100};

int disp_info() {
    printf("INFO:\n");
    printf(" - general -\n");
    printf(" cycles: %d\n", cycles);
    printf(" days: %d\n", days);
    printf("\n");
    printf(" - cannon info -\n");
    printf(" cannon pitch: %d\n", cannon.pitch);
    printf(" cannon yaw: %d\n", cannon.yaw);
    printf(" cannon motor health: %d\n", cannon.motor_health);
    printf(" cannon laser health: %d\n", cannon.laser_health);
    printf(" cannon cooler health: %d\n", cannon.cooler_health);
    printf("\n");
    return 0;
}

int disp_help() {
    printf("AVAILABLE COMMANDS:\n");
    printf(" help - displays this help screen\n");
    printf(" clear - clears the screen\n");
    printf(" quit - quits the game\n");
    printf(" info - displays important info\n");
    printf(" pitch - adjust cannon pitch\n");
    printf(" yaw - adjust cannon yaw\n");
    printf("\n");
    return 0;
}

int init() {
    // just as a note this first printf clears the screen (it's not very obvious, hence the note)
    printf("\e[1;1H\e[2J");
    printf("===DEFENSE GAME===\n\n");
    disp_info();

    return 0;
}

int handle_cmd(char *cmd, bool *running) {
    if(strcmp(cmd, "quit") == 0) {
        *running = false;
        printf("\e[1;1H\e[2J");
    } else if(strcmp(cmd, "clear") == 0) {
        init();
    } else if(strcmp(cmd, "info") == 0) {
        disp_info();
    } else if(strcmp(cmd, "pitch") == 0) {
        printf("current pitch: %d\n", cannon.pitch);
        printf("new pitch: ");
        scanf("%d", &cannon.pitch);
        printf("OK\n\n");
        cycles++;
    } else if(strcmp(cmd, "yaw") == 0) {
        printf("current yaw: %d\n", cannon.yaw);
        printf("new yaw: ");
        scanf("%d", &cannon.yaw);
        printf("OK\n\n");
        cycles++;
    } else if(strcmp(cmd, "help") == 0) {
        disp_help();
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
    }

    return 0;
}

