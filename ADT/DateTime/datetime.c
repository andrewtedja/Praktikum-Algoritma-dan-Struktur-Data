#include "datetime.h"
#include <stdio.h>

/* *** Helper Functions *** */
int GetMaxDay(int M, int Y) {
    if (M == 2) { // February
        if ((Y % 400 == 0) || (Y % 4 == 0 && Y % 100 != 0)) {
            return 29; // Leap year
        }
        return 28; // Non-leap year
    }
    // April, June, September, November have 30 days
    if (M == 4 || M == 6 || M == 9 || M == 11) {
        return 30;
    }
    return 31; // All other months have 31 days
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    return (Y >= 1900 && Y <= 2030) &&
        (M >= 1 && M <= 12) &&
        (D >= 1 && D <= GetMaxDay(M, Y)) &&
        (h >= 0 && h <= 23) &&
        (m >= 0 && m <= 59) &&
        (s >= 0 && s <= 59);
}

/* *** Constructors *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    if (IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
        Year(*D) = YYYY;
        Month(*D) = MM;
        Day(*D) = DD;
        CreateTIME(&Time(*D), hh, mm, ss);
    } else {
        printf("DATETIME is not valid\n");
    }
}

/* *** Input/Output *** */
void BacaDATETIME(DATETIME *D, char *currentLine) {
    int DD, MM, YYYY, hh, mm, ss;
    do {
        sscanf(currentLine, "%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
        if (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
            printf("DATETIME tidak valid\n");
        }
    } while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss));
