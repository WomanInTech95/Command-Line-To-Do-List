#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 256

typedef struct {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int taskCount;
} ToDoList;

void addTask(ToDoList *list) {
    if (list->taskCount < MAX_TASKS) {
        printf("Enter task: ");
        scanf(" %[^\n]%*c", list->tasks[list->taskCount]);
        list->taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("To-Do List is full!\n");
    }
}

void viewTasks(ToDoList *list) {
    if (list->taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("\nTo-Do List:\n");
    for (int i = 0; i < list->taskCount; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]);
    }
}

void deleteTask(ToDoList *list) {
    int taskNumber;
    viewTasks(list);
    if (list->taskCount > 0) {
        printf("Enter the task number to delete: ");
        scanf("%d", &taskNumber);
        if (taskNumber < 1 || taskNumber > list->taskCount) {
            printf("Invalid task number.\n");
        } else {
            for (int i = taskNumber - 1; i < list->taskCount - 1; i++) {
                strcpy(list->tasks[i], list->tasks[i + 1]);
            }
            list->taskCount--;
            printf("Task deleted successfully!\n");
        }
    }
}

int main() {
    ToDoList myList = { .taskCount = 0 };
    int choice;

    do {
        printf("\nTo-Do List Menu\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(&myList);
                break;
            case 2:
                viewTasks(&myList);
                break;
            case 3:
                deleteTask(&myList);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
