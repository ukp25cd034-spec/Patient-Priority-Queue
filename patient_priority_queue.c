#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[30];
    int priority;
    int order;
};

struct Patient queue[MAX];
int size = 0;
int orderCount = 0;

// Add a patient
void addPatient(char name[], int priority) {
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(queue[size].name, name);
    queue[size].priority = priority;
    queue[size].order = ++orderCount;
    size++;

    printf("Patient %s added with priority %d.\n", name, priority);
}

// Treat the highest-priority patient
void treatNext() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    int index = 0;

    // Find highest priority.
    // If priorities are equal, earlier arrival is selected.
    for (int i = 1; i < size; i++) {
        if (queue[i].priority < queue[index].priority ||
            (queue[i].priority == queue[index].priority &&
             queue[i].order < queue[index].order)) {
            index = i;
        }
    }

    printf("Treating patient: %s (Priority %d)\n",
           queue[index].name, queue[index].priority);

    // Remove patient from queue
    for (int i = index; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

int main() {
    // Add P1-P6 as given in the challenge
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreatment Order:\n");

    while (size > 0) {
        treatNext();
    }

    // Test: add patients again
    printf("\n--- Emergency Patient Test ---\n");

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    // Treat 3 patients
    printf("\nTreating first 3 patients:\n");
    treatNext();
    treatNext();
    treatNext();

    // Add new Emergency patient
    printf("\nAdding new Emergency patient:\n");
    addPatient("Emergency", 1);

    printf("\nRemaining Treatment Order:\n");

    while (size > 0) {
        treatNext();
    }

    return 0;
}
