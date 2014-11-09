/*
 *  Name:   tokenz
 *  Desc:   Fast tokenizer library
 *  Vers:   1.0
 *  Author: sim0nk@yandex.ru
 *  See LICENSE for license info (Apache License 2.0)
 *
 */

#include <stddef.h>

struct token {
    // the pointer to the first character of the token
    char *begin; 
    // the pointer to one past the last character of the token
    char *end;
};

/* Name: tokenz
 * Desc: Returns a token split by the 'delims' delimiter characters
 * Params: const char *string
 *           - the string to search tokens from
 *         char delim
 *           - the tokens delimiter characters
 *           - same as in strtok
 */ 
struct token 
tokenz(const char *string, const char *delims);


/* Name: tokenzc
 * Desc: Returns a token split by the 'delim' delimiter character
 * Params: const char *string
 *           - the string to search tokens from
 *         char delim
 *           - the tokens delimiter character
 */ 
struct token 
tokenzc(const char *string, char delim);


/* Name: tokenzs
 * Desc: Returns a token split by the 'delim' delimiter string
 * Params: const char *string
 *           - the string to search tokens from
 *         char delim
 *           - the tokens delimiter string
 */ 
struct token 
tokenzs(const char *string, const char *delim);


/* Name: tokstr
 * Desc: Copies the token 'token' to destination string 'dest'.
 *       The destination string will be Null terminated.
 *       The destination string must be large enough to receive the token.
 * Params: char *dest
 *           - the destination string
 *         const struct token *token 
 *           - the source token
 * Return: Pointer to the destination string 'dest' or NULL if either 'dest' or 'token' are NULL.
 */ 
char *
tokstr(char *dest, const struct token *token);


/* Name: toknstr
 * Desc: Copies the token 'token' to destination string 'dest'.
 *       At most 'size' characters will be copied.
 *       The destination string will be Null terminated.
 *       The destination string will be truncated if the token length is larger than 'size'.
 * Params: char *dest
 *           - the destination string
 *         const struct token *token 
 *           - the source token
 *         size_t size
 *           - the size of the destination string
 * Return: The total number of characters copied into the destination string.
 */ 
size_t 
toknstr(char *dest, const struct token *token, size_t size);


/* Name: tokcat
 * Desc: Appends (conCATenates) the token 'token' to destination string 'dest', 
 *       overwriting the terminating Null byte at the end of 'dest'.
 *       The destination string will be Null terminated.
 *       The destination string must be large enough to receive the token.
 * Params: char *dest
 *           - the destination string
 *         const struct token *token 
 *           - the source token
 * Return: Pointer to the destination string 'dest' or NULL if either 'dest' or 'token' are NULL.
 */ 
char *tokcat(char *dest, const struct token *token);


/* Name: tokncat
 * Desc: Appends (conCATenates) the token 'token' to destination string 'dest', 
 *       overwriting the terminating Null byte at the end of 'dest'.
 *       At most 'size' characters will be appended from the token.
 *       The destination string will be Null terminated.
 *       The destination string will be truncated if the token length is larger than 'size'.
 * Params: char *dest
 *           - the destination string
 *         const struct token *token 
 *           - the source token
 *         size_t size
 *           - the size of the destination string
 * Return: The total number of characters in the destination string after concatenation.
 */ 
size_t tokncat(char *dest, const struct token *token, size_t size);


/* Name: toklen
 * Desc: Returns the length of the token in O(1) time.
 */ 
size_t 
toklen(const struct token *token);


/* Name: tokprint
 * Desc: Prints the token to stdout.
 */ 
void 
tokprint(const struct token *token);


/* Name: tokprintln
 * Desc: Prints the token to stdout with a newline at the end.
 */ 
void 
tokprintln(const struct token *token);
