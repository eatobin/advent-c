#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void day1_1(const char *in) {
    const char delim[] = "\n";
    char *r;
    char *end;
    char *tk;
    r = strdup(in);
    end = r;

    int total_fuel = 0;
    tk = strsep(&end, delim);
    while (tk != NULL) {
        float f = strtof(tk, NULL);
        f = f / 3;
        int x = (int) f;
        x -= 2;
        total_fuel += x;
        tk = strsep(&end, delim);
    }
    printf("%d\n", total_fuel);
    free(r);
}

void day1_2(const char *in) {
    const char delim[] = "\n";
    char *r;
    char *end;
    char *tk;
    float fuel;

    r = strdup(in);
    end = r;

    int tot_fuel = 0;
    tk = strsep(&end, delim);
    while (tk != NULL) {
        // Module mass
        float mass = strtof(tk, NULL);

        while (1) {
            fuel = mass / 3;
            int x = (int) fuel;
            x -= 2;
            if (x <= 0) {
                break;
            }
            tot_fuel += x;
            mass = (float) x;
        }

        tk = strsep(&end, delim);
    }

    printf("%d\n", tot_fuel);
    free(r);
}

int main() {
    const char day1_in[] = "68958\n"
                           "82218\n"
                           "54333\n"
                           "59177\n"
                           "51874\n"
                           "100259\n"
                           "95468\n"
                           "124006\n"
                           "75078\n"
                           "113631\n"
                           "90315\n"
                           "147580\n"
                           "68233\n"
                           "81025\n"
                           "133084\n"
                           "90959\n"
                           "81196\n"
                           "92443\n"
                           "124832\n"
                           "65871\n"
                           "57704\n"
                           "140203\n"
                           "113053\n"
                           "76337\n"
                           "72195\n"
                           "115917\n"
                           "87843\n"
                           "131768\n"
                           "105816\n"
                           "131153\n"
                           "59714\n"
                           "94107\n"
                           "50933\n"
                           "139545\n"
                           "94969\n"
                           "149463\n"
                           "60042\n"
                           "66028\n"
                           "111190\n"
                           "63257\n"
                           "50020\n"
                           "88783\n"
                           "81428\n"
                           "73977\n"
                           "149240\n"
                           "137152\n"
                           "74738\n"
                           "55067\n"
                           "128829\n"
                           "56465\n"
                           "81962\n"
                           "67242\n"
                           "94121\n"
                           "92303\n"
                           "68477\n"
                           "88595\n"
                           "64324\n"
                           "82527\n"
                           "134717\n"
                           "140344\n"
                           "132026\n"
                           "137558\n"
                           "95643\n"
                           "79010\n"
                           "146346\n"
                           "86246\n"
                           "52341\n"
                           "147564\n"
                           "89159\n"
                           "66456\n"
                           "83190\n"
                           "128675\n"
                           "130658\n"
                           "122857\n"
                           "134538\n"
                           "122151\n"
                           "133900\n"
                           "117462\n"
                           "117791\n"
                           "139254\n"
                           "86366\n"
                           "66165\n"
                           "92897\n"
                           "121218\n"
                           "135962\n"
                           "143061\n"
                           "129220\n"
                           "114623\n"
                           "98257\n"
                           "76722\n"
                           "121014\n"
                           "77713\n"
                           "137858\n"
                           "133282\n"
                           "103595\n"
                           "118981\n"
                           "149137\n"
                           "101141\n"
                           "70765\n"
                           "141113";

    printf("--- Day 1 ---\n");
    day1_1(day1_in);  // 3337766
    day1_2(day1_in);  // 5003788

    return EXIT_SUCCESS;

}
