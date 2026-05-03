#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;
int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compareCars);

    int fleets = 0;
    double currentSlowest = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > currentSlowest) {
            fleets++;
            currentSlowest = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}
