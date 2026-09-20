#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stddef.h>

extern void eprintf (const char* fmt, ...);
extern void weprintf (const char* fmt, ...);
extern char* estrdup (const char* s);
extern FILE* efopen (const char* fn, const char *mode);
extern void efclose (FILE* fp);
extern void setprogname (const char* str);
extern char* progname (void);
extern void* emalloc (size_t n);

#endif /* ERROR_H */
