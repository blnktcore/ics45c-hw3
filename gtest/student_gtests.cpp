#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("a"), 1);
    EXPECT_EQ(String::strlen("foo"), 3);
    EXPECT_EQ(String::strlen("hi there!"), 9);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];
    EXPECT_EQ(String::strncpy(result, "hello", 3), result);
    EXPECT_STREQ(result, "hel");

    EXPECT_EQ(String::strncpy(result, "hi", 5), result);
    EXPECT_STREQ(result, "hi");

    EXPECT_EQ(String::strncpy(result, "abc", 3), result);
    EXPECT_STREQ(result, "abc");

    EXPECT_EQ(String::strncpy(result, "abc", 0), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "", 4), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
    char a[20] = "foo";
    EXPECT_EQ(String::strcat(a, "bar"), a);
    EXPECT_STREQ(a, "foobar");

    char b[20] = "";
    EXPECT_EQ(String::strcat(b, "x"), b);
    EXPECT_STREQ(b, "x");

    char c[20] = "abc";
    EXPECT_EQ(String::strcat(c, ""), c);
    EXPECT_STREQ(c, "abc");
}

TEST(StringFunction, strncat) {
    char a[20] = "foo";
    EXPECT_EQ(String::strncat(a, "barbaz", 3), a);
    EXPECT_STREQ(a, "foobar");

    char b[20] = "ab";
    EXPECT_EQ(String::strncat(b, "cd", 10), b);
    EXPECT_STREQ(b, "abcd");

    char c[20] = "ab";
    EXPECT_EQ(String::strncat(c, "cd", 0), c);
    EXPECT_STREQ(c, "ab");

    char d[20] = "";
    EXPECT_EQ(String::strncat(d, "xyz", 2), d);
    EXPECT_STREQ(d, "xy");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_EQ(String::strcmp("", ""), 0);
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
    EXPECT_LT(String::strcmp("ab", "abc"), 0);
    EXPECT_GT(String::strcmp("abc", "ab"), 0);
    EXPECT_LT(String::strcmp("", "a"), 0);
    EXPECT_LT(String::strcmp("Z", "a"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abcX", "abcY", 3), 0);
    EXPECT_GT(String::strncmp("b", "a", 1), 0);
    EXPECT_EQ(String::strncmp("abc", "xyz", 0), 0);
    EXPECT_EQ(String::strncmp("ab", "ab", 10), 0);
    EXPECT_LT(String::strncmp("ab", "abc", 3), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[10];
    String::reverse_cpy(result, "abc");
    EXPECT_STREQ(result, "cba");

    String::reverse_cpy(result, "a");
    EXPECT_STREQ(result, "a");

    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");

    String::reverse_cpy(result, "ab!");
    EXPECT_STREQ(result, "!ba");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";
    EXPECT_EQ(String::strchr(s, 'h'), s);
    EXPECT_EQ(String::strchr(s, 'l'), s + 2);
    EXPECT_EQ(String::strchr(s, 'o'), s + 4);
    EXPECT_EQ(String::strchr(s, 'z'), nullptr);
    EXPECT_EQ(String::strchr(s, '\0'), s + 5);
    EXPECT_EQ(String::strchr("", 'a'), nullptr);
}

TEST(StringFunction, strstr) {
    const char *s = "hello world";
    EXPECT_EQ(String::strstr(s, "hello"), s);
    EXPECT_EQ(String::strstr(s, "world"), s + 6);
    EXPECT_EQ(String::strstr(s, "o"), s + 4);
    EXPECT_EQ(String::strstr(s, "xyz"), nullptr);
    EXPECT_EQ(String::strstr(s, "worlds"), nullptr);
    EXPECT_EQ(String::strstr(s, ""), s);
    EXPECT_EQ(String::strstr("", "a"), nullptr);
}