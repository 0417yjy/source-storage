// Concurrent State Machine structure
typedef struct Task {
	int state; // Task's current state
	unsigned long period; // Task period
	unsigned long long elapsedTime; // Time elapsed since last task tick
	int (*TickFct) (int); // Task tick function
} Task;

#define TASK_SIZE 1
Task tasks[TASK_SIZE];

enum CustomStates{C_init, C_state1};
int TickFct_CustomStates(int state) {
    switch(state) { // Transitions
        case C_init:
        state = C_state1;
        break;
        case C_state1:
        state = C_init;
        break;
    }

    switch(state) { // Actions
        case C_init:

        break;
        case C_state1:

        break;

    }

    return state;
}