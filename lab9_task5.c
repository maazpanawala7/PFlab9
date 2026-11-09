#include <stdio.h>

void printSensorData(void *ptr, char type) {
    if (type == 'f') {
        float *val = (float *)ptr;
        printf("Temperature: %.2f C\n", *val);
    } 
    else if (type == 'i') {
        int *val = (int *)ptr;
        if (*val == 1) {
            printf("Motion Detected\n");
        } else {
            printf("No Motion\n");
        }
    } 
    else if (type == 'c') {
        char *val = (char *)ptr;
        if (*val == 'O') {
            printf("Door Open\n");
        } else if (*val == 'C') {
            printf("Door Closed\n");
        }
    }
}

int main() {
    float temp = 25.0;
    int motion = 1;
    char door = 'O';
    
    printSensorData(&temp, 'f');
    printSensorData(&motion, 'i');
    printSensorData(&door, 'c');
    
    return 0;
} 