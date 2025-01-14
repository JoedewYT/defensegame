#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_TARGETS 20
#define DAY_CYCLES 999
#define CANNON_MAX_HEALTH 100
int current_targets = 0;
int cycles = 0;
int days = 0;

struct Cannon {
    int pitch;
    int yaw;
    int motor_health;
    int laser_health;
    int electronics_health;
};
struct Cannon cannon = {0,0,100,100,100};

struct Target {
    int required_pitch;
    int required_yaw;
    int impact_time;
    int difficulty;
};
struct Target* targets[MAX_TARGETS];

void create_target(int index, int required_pitch, int required_yaw, int impact_time, int difficulty) {
    if (index < MAX_TARGETS) {
        targets[index] = (struct Target*)malloc(sizeof(struct Target));

        if (targets[index] != NULL) {
            targets[index]->required_pitch = required_pitch;
            targets[index]->required_yaw = required_yaw;
            targets[index]->impact_time = impact_time;
            targets[index]->difficulty = difficulty;
        }
        current_targets++;
    }
    return;
}

void create_new_random_target_set(int amount) {
    int i;
    for (i = 0; i<MAX_TARGETS; i++) {
        if (targets[i] != NULL) {
            free(targets[i]);
        }
    }
    current_targets = 0;
    for (i = 0; i<amount; i++) {
        create_target(i, rand()%361 - 180, rand()%361 - 180, rand()%40 + 10, rand()%5 + 1);
    }
    return;
}

void display_targets() {
    int i;
    for (i = 0; i<current_targets; i++) {
        printf("TARGET %d:\n", i);
        printf("required pitch: %d\n", targets[i]->required_pitch);
        printf("required yaw: %d\n", targets[i]->required_yaw);
        printf("impact time: %d\n", targets[i]->impact_time);
        printf("difficulty: %d\n\n", targets[i]->difficulty);
    }
    return;
}

void disp_info() {
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
    printf(" cannon electronics health: %d\n", cannon.electronics_health);
    printf("\n");
    return;
}

void disp_help() {
    printf("AVAILABLE COMMANDS:\n");
    printf(" help - displays this help screen\n");
    printf(" clear - clears the screen\n");
    printf(" quit - quits the game\n");
    printf(" info - displays important info\n");
    printf(" pitch - adjust cannon pitch\n");
    printf(" yaw - adjust cannon yaw\n");
    printf("\n");
    return;
}

void adjust_pitch() {
    printf("current pitch: %d\n", cannon.pitch);
    printf("new pitch: ");
    scanf("%d", &cannon.pitch);
    printf("OK\n\n");
    cycles++;
    return;
}

void adjust_yaw() {
    printf("current yaw: %d\n", cannon.yaw);
    printf("new yaw: ");
    scanf("%d", &cannon.yaw);
    printf("OK\n\n");
    cycles++;
    return;
}

void init() {
    // just as a note this first printf clears the screen (it's not very obvious, hence the note)
    printf("\e[1;1H\e[2J");
    printf("===DEFENSE GAME===\n\n");
    disp_info();
    return;
}

void handle_cmd(char *cmd, bool *running) {
    if(strcmp(cmd, "quit") == 0) {
        *running = false;
        printf("\e[1;1H\e[2J");
    } else if(strcmp(cmd, "clear") == 0) {
        init();
    } else if(strcmp(cmd, "info") == 0) {
        disp_info();
    } else if(strcmp(cmd, "pitch") == 0) {
        adjust_pitch();
    } else if(strcmp(cmd, "yaw") == 0) {
        adjust_yaw();
    } else if(strcmp(cmd, "help") == 0) {
        disp_help();
    } else {
        printf("INVALID COMMAND!\n\n");
    }
    return;
}

void main() {
    bool running = true;
    char cmd[20];

    srand(time(NULL));
    init(cycles);
    create_new_random_target_set(3);
    display_targets();

    while(running) {
        if (cycles == DAY_CYCLES) {
            cycles = 0;
            days++;
        }
        printf("#: ");
        scanf("%19s", &cmd);
        handle_cmd(cmd, &running);
    }

    return;
}

