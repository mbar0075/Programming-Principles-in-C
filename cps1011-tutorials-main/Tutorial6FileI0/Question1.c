#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 31
#define AVGWORD 5

long fsize(FILE* fp);

int main(int argc, char* argv[])
{
	if (argc != 4) {
		fprintf(stderr, "usage: q1 [file] [find] [replace]\n");
		exit(EXIT_FAILURE);
	}

    FILE* fp = fopen(argv[1], "r+");

	char* find = argv[2];
	char* replace = argv[3];

    if (fp == NULL) {
        fprintf(stderr, "q1: file error\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char file[size];

    fread(file, size, 1, fp);
	file[size - 1] = '\0';
	rewind(fp);

	char wordcur[MAXWORD + 1];

	for (long i = 0, j = 0; i < size; i++) {
		if (!isspace(file[i])) {
			if (j < MAXWORD) {
				wordcur[j++] = file[i];
			}
		} else {
			wordcur[j] = '\0';

			if (j > 0) { // we have a word
				if (!strncmp(find, wordcur, MAXWORD + 1)) {
					fputs(replace, fp);
				} else {
					fputs(wordcur, fp);
				}

				j = 0;
			}

			fputc(file[i], fp);
		}
	}

    return 0;
}