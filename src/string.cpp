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
}

// returns 0 if strings are equal
int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && left[i] == right[i])
        ++i;
    return (unsigned char)left[i] - (unsigned char)right[i];
}

int String::strncmp(const char *left, const char*right, int n) {
    for (int i = 0; i < n; ++i) {
        if (left[i] != right[i] || left[i] == '\0')
            return (unsigned char)left[i] - (unsigned char)right[i];
    }
    return 0;
}

void String::reverse_cpy(char *dest, const char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

const char *String::strchr(const char *str, char c) {
    int i = 0;
    for ( ; str[i] != '\0'; ++i)
        if (str[i] == c)
            return str + i;
    return c == '\0' ? str + i : nullptr;
}

const char *String::strstr(const char *haystack, const char *needle) {
    int nlen = strlen(needle);
    for (int i = 0; ; ++i) {
        if (strncmp(haystack + i, needle, nlen) == 0)
            return haystack + i;
        if (haystack[i] == '\0')
            return nullptr;
    }
}

String::String(const char *s) {
    strncpy(buf, s, MAXLEN - 1);
}

String::String(const String &s) {
