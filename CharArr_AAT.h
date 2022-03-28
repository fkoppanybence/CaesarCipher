/*
 * Fülöp Koppány-Bence
 */

#ifndef PROJECT_CHARARRAY_AAT_H
#define PROJECT_CHARARRAY_AAT_H

#define MAX 500

class CharArr {
public:
    char a[MAX];
    int prefix[MAX];
    int hossz;

    CharArr(const char *);

    CharArr();

    ~CharArr();

    bool IsEmpty();

    bool IsEqual(CharArr &);

    void Read();

    int Length_Chr();

    void CopyChr(const char *s);

    void CopyChr(CharArr &);

    void Concat(CharArr &);

    void Reverse();

    void Prefix();

    int Search_KMP(CharArr &);

    void Convert_To_Lower();

    void Convert_To_Upper();

    int Search_first_chr(const char s);

    int Search_last_chr(const char s);

    char operator[](int);

    void WriteOut() const;
};

#endif //PROJEKT_CharArr_AAT_H
