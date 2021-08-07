#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "intcode.h"
//#include "utils.h"

int day2_1(const char prog[]) {
    struct Intcode *ic = 0;
    int ret = 0;

    if ((ic = intcode_new()) == NULL) {
        printf("Could not create intcode computer!\n");
        return -1;
    }

    (void) load_program(ic, prog);
    (void) write_position(ic, 1, 12);
    (void) write_position(ic, 2, 2);
    (void) execute_program(ic);

    ret = read_position(ic, 0);
    printf("Position 0 after program halt: %d\n", ret);
    intcode_free(ic);
    return ret;
}

int day2_2(const char prog[], int target_output) {
    int in1;
    int in2;
    struct Intcode *ic = 0;

    if ((ic = intcode_new()) == NULL) {
        printf("Could not create intcode computer!\n");
        return -1;
    }

    for (in1 = 0; in1 <= 99; in1++) {
        for (in2 = 0; in2 <= 99; in2++) {
            (void) load_program(ic, prog);
            (void) write_position(ic, 1, in1);
            (void) write_position(ic, 2, in2);
            (void) execute_program(ic);
            if (read_position(ic, 0) == target_output) {
                printf("Found inputs: %d, %d!\n", in1, in2);
                goto end;
            }
        }
    }
    end:
    printf("100 * noun + verb = %d.\n", (100 * in1) + in2);
    intcode_free(ic);
    return (100 * in1) + in2;

}

int main(int argc, char *argv[]) {
    const char day2_intcode_program[] = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,2,9,19,23,2,13,23,27,1,6,27,31,2,6,31,35,2,13,35,39,1,39,10,43,2,43,13,47,1,9,47,51,1,51,13,55,1,55,13,59,2,59,13,63,1,63,6,67,2,6,67,71,1,5,71,75,2,6,75,79,1,5,79,83,2,83,6,87,1,5,87,91,1,6,91,95,2,95,6,99,1,5,99,103,1,6,103,107,1,107,2,111,1,111,5,0,99,2,14,0,0";

    printf("--- Day 2 ---\n");
    assert(day2_1(day2_intcode_program) == 2890696);
    assert(day2_2(day2_intcode_program, 19690720) == 8226);

    return EXIT_SUCCESS;

}
