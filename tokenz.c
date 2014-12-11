/*
 *  Name:   tokenz
 *  Desc:   Fast tokenizer library
 *  Vers:   1.0
 *  Author: sim0nk@yandex.ru
 *  See LICENSE for license info (Apache License 2.0)
 *
 */

#include <stdio.h>

#include "tokenz.h"

struct token tokenzc(const char *string, char delim)
{
    struct token t = { .begin = NULL, .end = NULL };

    if (string == NULL) return t;

    const char *s = string;

    while (*s == delim) s++;
    if (*s) {
        t.begin = (char *) s;
        while (*s && *s != delim) s++;
        t.end = (char*) s;
    }

    return t;
}

struct token tokenzs(const char *string, const char *delim)
{
    struct token t = { .begin = NULL, .end = NULL };

    if (string == NULL) return t;

    const char *s = string;

    if (delim == NULL) {
        t.begin = (char *) string;
        while (*(++s));
        t.end = (char *) s;

        return t;
    }

    const char *d = delim;

    const char *save = s;
    while (*s == *d) {
        if (*(++s) == '\0') {
            if (*(d+1) == '\0') return t;
            break;
        }
        if (*(++d) == '\0') {
            save = s;
            d = delim;
        }
    }

    if (*d != '\0') s = save;

    d = delim;
    
    t.begin = (char *) (*s ? s : string);

    while (*s) {
        if (*s == *d) {
            save = s;
            do {
                if (*(++d) == '\0') {
                    t.end = (char *) save;
                    return t;
                }
                if (*(++s) == '\0') {
                    t.end = (char *) s;
                    return t;
                }
            } while (*s == *d);
            d = delim;
        }

        if (*(++s) == '\0') {
            t.end = (char *) s;
            return t;
        }
    }

    return t;
}

struct token tokenz(const char *string, const char *delims)
{
    struct token t = { .begin = NULL, .end = NULL };

    if (string == NULL) return t;

    const char *s = string;

    if (delims == NULL) {
        t.begin = (char *) string;
        while (*(++s));
        t.end = (char *) s;

        return t;
    }

    const char *d = delims;
    
    while (*s) {
        for (d = delims; *d; d++)
            if (*s == *d) break;
        if (*d == '\0') break;
        s++;
    }

    t.begin = (char *) (*s ? s : string);

    while (*s) {
        for (d = delims; *d; d++)
            if (*s == *d) break;

        if (*d != '\0' || *(++s) == '\0') {
            t.end = (char *) s;
            break;
        }
    }

    return t;
}


char *tokstr(char *dest, const struct token *token)
{
    if (dest == NULL || token == NULL) return NULL;

    const char *s;
    for (s = token->begin; s != token->end; s++)
        *dest++ = *s;
    *dest = '\0';

    return dest;
}

size_t toknstr(char *dest, const struct token *token, size_t size)
{
    if (dest == NULL || token == NULL || size == 0) return 0;

    const char *s;
    register size_t n = 1;
    for (s = token->begin; s != token->end; s++) {
        if (n++ == size)
            break;
        *dest++ = *s; 
    }
    *dest = '\0';

    return n-1;
}

char *tokcat(char *dest, const struct token *token)
{
    if (dest == NULL || dest == NULL) return NULL;

    while (*dest != '\0') dest++;

    const char *s;
    for (s = token->begin; s != token->end; s++)
        *dest++ = *s;
    *dest = '\0';

    return dest;
}

size_t tokncat(char *dest, const struct token *token, size_t size)
{
    if (dest == NULL || token == NULL || size == 0) return 0;

    register size_t n = 1;

    char *temp = dest;
    while (*temp) {
        if (++n == size) {
            n = 0;
            temp = dest;
            break;
        }
        temp++;
    }

    const char *s;
    for (s = token->begin; s != token->end; s++) {
        if (n++ == size)
            break;
        *temp++ = *s; 
    }
    *temp = '\0';

    return n-1;
}

size_t toklen(const struct token *token)
{
    return (token->end - token->begin);
}

void tokprint(const struct token *token)
{
    const char *s;
    for (s = token->begin; s != token->end; s++)
        putchar(*s);
}

void tokprintln(const struct token *token)
{
    const char *s;
    for (s = token->begin; s != token->end; s++)
        putchar(*s);
    putchar('\n');
}
