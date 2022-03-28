/*
 * Fülöp Koppány-Bence
 */

#include <iostream>
#include "CharArr_AAT.h"
#include <fstream>

std::ofstream out("output.txt");

void Shift(int A_length, CharArr &A, int k, int *ascii) {
    int temp12, temp22;
    for (int i = 0; i < A_length; i++) {
        temp12 = A.a[i];
        temp22 = A.a[(i + k) % A_length];
        ascii[temp12] = temp22;
    }
}

void New_Word_Gen(CharArr &newWord, int *ascii, CharArr &W) {
    for (int i = 0; i < W.Length_Chr(); i++) {
        newWord.a[i] = (char) ascii[W.a[i]];
    }
    newWord.a[W.Length_Chr()] = '\0';
}

void Unique_solution(CharArr &T, CharArr &newWord, int k, int &num, int *sol) {
    int position = T.Search_KMP(newWord);
    if (position >= 0) {
        char temp = T.a[position];
        T.a[position] = '.';
        if (T.Search_KMP(newWord) < 0) {
            sol[num] = k;
            num++;
        }
        T.a[position] = temp;
    }
}

void WriteOut_Solution(int n, int *sol) {
    if (n == 0) {
        out << "no solution \n";
    } else if (n == 1) {
        out << "unique solution: ";
        out << sol[0] << std::endl;
    } else {
        out << "the solution is not unique: ";
        for (int i = 0; i < n; i++) {
            out << sol[i] << " ";
        }
        out << std::endl;
    }
}

void CaesarCode(CharArr &A, CharArr &W, CharArr &T) {

    int solas = 0;
    int A_length = A.Length_Chr();
    CharArr newWord;
    newWord.CopyChr(W);
    int *ascii;
    ascii = new int[128];
    int num = 0, *sol;
    sol = new int[65];

    for (int k = 0; k < A_length; k++) {
        Shift(A_length, A, k, ascii);
        New_Word_Gen(newWord, ascii, W);
        Unique_solution(T, newWord, k, num, sol);
    }

    WriteOut_Solution(num, sol);
}

void Read(CharArr &A, CharArr &W, CharArr &T) {
    A.Read();
    W.Read();
    T.Read();
}

int main() {

    //Read in the abc, the decoded word and the coded text
    CharArr A;
    CharArr W;
    CharArr T;
    Read(A, W, T);
    CaesarCode(A, W, T);

    return 0;
}