tokenz
======

Fast string tokenizer library in C.

API documentation is in the tokenz.h header file.

Including in your project:
Just include the tokenz.h file in the files that want to use it and compile your project with tokenz.c .

Example of strtok replacement function 'tokenz':
```c
char *string = "Hello, there; Lol.";
char *delims = " ,.;";
for (struct token t = tokenz(string, delims); t.end != NULL; t = tokenz(t.end, delims))
    tokprintln(&t);
/* Output:
Hello
there
Lol
*/
```

Example of tokenizing by string delimiter using function 'tokenzs':
```c
char *string = "-=--=-One-=-Two-=-Three-=--=-";
char *delim = "-=-";
for (struct token t = tokenzs(string, delim); t.end != NULL; t = tokenzs(t.end, delim))
    tokprintln(&t);
/* Output:
One
Two
Three
*/
```

Example of tokenizing by a single character delimiter by using function 'tokenzc':
```c
char *string = "Thomas,Anderson,1962";
char delim = ',';
for (struct token t = tokenzc(string, delim); t.end != NULL; t = tokenzc(t.end, delim))
    tokprintln(&t);
/* Output:
Thomas
Anderson
1962
*/
```

Also contains token to string copy and concatenation functions.
