#include <stdio.h>
#include <stdlib.h>

int fuelValue(int mass) {
    float fvf = (float) mass / 3;
    int fvi = (int) fvf;
    fvi -= 2;
    return fvi;
}

int recFuelValue(int mass) {
    int sum = 0;
    while (1) {
        int fuel = fuelValue(mass);
        if (fuel <= 0) {
            break;
        }
        sum += fuel;

        mass = fuelValue(fuel);
        if (mass <= 0) {
            break;
        }
        sum += mass;
    }
    return sum;
}

int main(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int mass;
    int tot_fuel = 0;
    int tot_fuel_rec = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((getline(&line, &len, fp)) != -1) {
        mass = (int) (strtol(line, NULL, 10));
        tot_fuel += fuelValue(mass);
    }
    printf("Part a: %i\n", tot_fuel);

    rewind(fp);
    while ((getline(&line, &len, fp)) != -1) {
        mass = (int) (strtol(line, NULL, 10));
        tot_fuel_rec += recFuelValue(mass);
    }
    printf("Part b: %i\n", tot_fuel_rec);

    free(line);
    line = NULL;
    fclose(fp);

    exit(EXIT_SUCCESS);
}

//Part a: 3337766
//Part b: 5003788
