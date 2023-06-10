#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}
char* SolveSuperstring(const char** v, size_t v_size) {
    bool* preso = calloc(v_size, sizeof(bool));
    int index1 = 0;
    int index2 = 0;
    int max_overlap = 0;
    //trovo il primo
    for (size_t i = 0; i < v_size; i++) {
        for (size_t j = 0; j < v_size; j++) {
            if (i == j) continue;
            int overlap = 0;
            Overlap(v[i], v[j], &overlap);
            if (overlap > max_overlap) {
                index1 = (int)i;
                index2 = (int)j;
                max_overlap = overlap;
            }
        }
    }
    if (index1 == 0 && index2 == 0) {
        free(preso);
        return NULL;
    }
    char* ris = Overlap(v[index1], v[index2], &max_overlap);
    preso[index1] = true;
    preso[index2] = true;
    
    while (1) {
        bool control = false;
        max_overlap = 0;
        for (size_t j = 0; j < v_size; j++) {
            if (preso[j] == false) {
                control = true;
                int overlap = 0;
                Overlap(ris, v[j], &overlap);
                if (overlap > max_overlap) {
                    index1 = (int)j;
                    max_overlap = overlap;
                }
            }
        }
        if (!control) break;
        ris = Overlap(ris, v[index1], &max_overlap);
        preso[index1] = true;
    }
    ris[strlen(ris)] = '\0';
    free(preso);
    return ris;
}

