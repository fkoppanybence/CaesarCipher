/*
 * Fülöp Koppány-Bence
 */

#include "CharArr_AAT.h"
#include <iostream>
#include <cstdio>

FILE *in = fopen("input.txt", "r");

CharArr::CharArr(const char *s) {
    length = 0;
    a[length] = s[length];
    while (s[length] != '\0') {
        length++;
        a[length] = s[length];
    }
}

CharArr::CharArr() {
    length = 0;
}

void CharArr::Read() {
    length = 0;
    char c;
    c = fgetc(in);
    while (c != '\n') {
        a[length] = c;
        length++;
        c = fgetc(in);
        if (c == EOF)break;
    }
    a[length] = '\0';
};

void CharArr::WriteOut() const {
    std::cout << a;
}

CharArr::~CharArr() {}

bool CharArr::IsEmpty() {
    return (length == 0);
}

bool CharArr::IsEqual(CharArr &b) {
    if (length == b.length) {
        int i = 0;
        while ((i <= length) && (a[i] == b.a[i]))
            i++;
        return i > length;
    } else return false;
}

int CharArr::length() {
    return length;
}

void CharArr::CopyChr(const char *s) {
    length = 0;
    a[length] = s[length];
    while (s[length] != '\0') {
        length++;
        a[length] = s[length];
    }
}

void CharArr::CopyChr(CharArr &b) {
    length = 0;
    a[length] = b.a[length];
    while (b.a[length] != '\0') {
        length++;
        a[length] = b.a[length];
    }
}

void CharArr::Concat(CharArr &b) {
    if (length + b.length < MAX) {
        int i = 0;
        a[length] = b.a[i];
        while (b.a[i] != '\0') {
            length++;
            i++;
            a[length] = b.a[i];
        }
    } else throw "Error.";
}

void CharArr::Prefix() {
    int k = 0;
    prefix[0] = 0;
    for (int i = 1; i < length; ++i) {
        while (k > 0 && a[k] != a[i])
            k = prefix[k];
        if (a[k] == a[i])
            k++;
        prefix[i] = k;
    }
}

int CharArr::Search_KMP(CharArr &pattern) {
    pattern.Prefix(); //building up the prefix array
    int k = 0;
    for (int i = 0; i < length; ++i) {
        while (k > 0 && pattern.a[k] != a[i])
            k = pattern.prefix[k];
        if (pattern.a[k] == a[i])
            k++;
        if (k == pattern.length)          // if we reached the end of the pattern
            return i - pattern.length + 1; // finding the pattern's location in s
    }
    return -1;              // unsuccessful search
}

void CharArr::Reverse() {
    char temp12;
    for (int i = 0; i < length / 2; i++) {
        temp12 = a[i];
        a[i] = a[length - i - 1];
        a[length - i - 1] = temp12;
    }
}

void CharArr::Convert_To_Lower() {
    for (int i = 0; i < length; ++i) {
        if ((a[i] >= 65) && (a[i] <= 90))
            a[i] += 32;
    }
}

void CharArr::Convert_To_Upper() {
    for (int i = 0; i < length; ++i) {
        if ((a[i] >= 97) && (a[i] <= 122))
            a[i] -= 32;
    }
}

int CharArr::Search_first_chr(const char s) {
    for (int i = 0; i < length; ++i) {
        if (a[i] == s)return i;
    }
    return -1;
};

int CharArr::Search_last_chr(const char s) {
    int temp22 = -1;
    for (int i = 0; i < length; ++i) {
        if (a[i] == s)temp22 = i;
    }
    return temp22;
}

char CharArr::operator[](int nr) {
    if (nr < length) {
        return a[nr];
    } else throw "Error: the elemenet does not exist. ";
}