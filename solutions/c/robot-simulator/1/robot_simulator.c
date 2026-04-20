#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    return (robot_status_t){
        .direction = direction, 
        .position = {.x = x, .y = y}
    };
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void robot_move(robot_status_t *robot, const char *commands) {
    char instruction;
    while ((instruction = *commands++)) {
        switch (instruction) {
        case 'R':
            robot->direction++;
            robot->direction %= DIRECTION_MAX;
            break;
        case 'L':
            robot->direction--;
            robot->direction %= DIRECTION_MAX;
            break;
        case 'A':
            robot->position.x += dx[robot->direction];
            robot->position.y += dy[robot->direction];
            break;
        default:
            break;
        }
    }
}
