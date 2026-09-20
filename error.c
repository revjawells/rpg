#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#include <SDL2/SDL.h>

#include "error.h"

static char *name = NULL;

void eprintf (const char* fmt, ...) {
	va_list args;

	fflush (stdout);
	if (progname () != NULL)
		fprintf (stderr, "%s: ", progname ());

	va_start (args, fmt);
	vfprintf (stderr, fmt, args);
	va_end (args);

	if (fmt[0] != '\0' && fmt[strlen (fmt) - 1] == ':')
		fprintf (stderr, " %s", strerror (errno));
	fprintf (stderr, "\n");
	exit (2);
}

void weprintf (const char* fmt, ...) {
	va_list args;

	fflush (stdout);
	if (progname () != NULL)
		fprintf (stderr, "%s: ", progname ());

	va_start (args, fmt);
	vfprintf (stderr, fmt, args);
	va_end (args);

	if (fmt[0] != '\0' && fmt[strlen (fmt) - 1] == ':')
		fprintf (stderr, " %s", strerror (errno));
	fprintf (stderr, "\n");
}

char* estrdup (const char* s) {
	char* t;
	t = (char*) malloc (strlen (s) + 1);
	if (t == NULL)
		eprintf ("estrdup(\"%.20s\") failed:", s);
	strcpy (t, s);
	return t;
}

void* emalloc (size_t n) {
	void* p;
	
	p = (void*) malloc (n);
	if (p == NULL)
		eprintf ("malloc of %u bytes failed\n", n);

	return p;
}

FILE* efopen (const char* fn, const char* mode) {
	FILE *fp;

	fp = fopen (fn, mode);
	if (fp == NULL)
		eprintf ("cannot open file %s:", fn);

	return fp;
}

void efclose (FILE* fp) {
	if (fclose (fp) == EOF) 
		eprintf ("cannot close file:");
}

void setprogname (const char* s) {
	name = estrdup (s);
}

char* progname (void) {
	return name;
}
