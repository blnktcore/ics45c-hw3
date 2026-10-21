#include <iostream>
#include <iomanip>

#include "string.hpp"

using namespace std;

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0')
        ++len;
    return len;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    for ( ; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int end = 0;
    while (dest[end] != '\0')
        ++end;
    strcpy(dest + end, src);
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int end = 0;
    while (dest[end] != '\0')
        ++end;
    strncpy(dest + end, src, n);
    return dest;
