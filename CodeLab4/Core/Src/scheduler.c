/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2024
 *      Author: MY LE
 */
#include "scheduler.h"

// Task array
sTask SCH_tasks_G[SCH_MAX_TASKS];

// Initialize scheduler
void SCH_Init(void) {
    for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_tasks_G[i].pTask = 0;
        SCH_tasks_G[i].Delay = 0;
        SCH_tasks_G[i].Period = 0;
        SCH_tasks_G[i].RunMe = 0;
    }
}

// Add a task to the scheduler
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].pTask == 0) { // Found an empty slot
            SCH_tasks_G[i].pTask = pFunction;
            SCH_tasks_G[i].Delay = DELAY;
            SCH_tasks_G[i].Period = PERIOD;
            SCH_tasks_G[i].RunMe = 0;
            return i; // Return task ID
        }
    }
    return SCH_MAX_TASKS; // No available task slot
}

// Delete a task from the scheduler
uint8_t SCH_Delete_Task(uint32_t taskID) {
    if (taskID < SCH_MAX_TASKS && SCH_tasks_G[taskID].pTask != 0) {
        SCH_tasks_G[taskID].pTask = 0;
        SCH_tasks_G[taskID].Delay = 0;
        SCH_tasks_G[taskID].Period = 0;
        SCH_tasks_G[taskID].RunMe = 0;
        return 0; // Success
    }
    return 1; // Error
}

// Update tasks
void SCH_Update(void) {
    for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].pTask != 0) {
            if (SCH_tasks_G[i].Delay == 0) {
                SCH_tasks_G[i].RunMe++;
                if (SCH_tasks_G[i].Period) {
                    SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
                }
            } else {
                SCH_tasks_G[i].Delay--;
            }
        }
    }
}

// Dispatch tasks
void SCH_Dispatch_Tasks(void) {
    for (uint32_t i = 0; i < SCH_MAX_TASKS; i++) {
        if (SCH_tasks_G[i].RunMe > 0) {
            (*SCH_tasks_G[i].pTask)(); // Run the task
            SCH_tasks_G[i].RunMe--;
            if (SCH_tasks_G[i].Period == 0) {
                SCH_Delete_Task(i);
            }
        }
    }
}


