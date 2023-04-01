#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD  63  // 64 - 1
#define BUFFSIZE 64

int fgetw(char* str, int nitems, FILE* stream);

int main(int argc, char* argv[])
{
    if (argc != 5) {
        fprintf(stderr, "usage: q2 [destination] [source] [find] [replace]\n");
        exit(EXIT_FAILURE);
    }

    FILE* fp_dst = fopen(argv[1], "w");
    FILE* fp_src = fopen(argv[2], "r");

    if (fp_dst == NULL) {
        fprintf(stderr, "q2: file error\n");
        exit(EXIT_FAILURE);
    }

    if (fp_src == NULL) {
        fprintf(stderr, "q2: file error\n");
        exit(EXIT_FAILURE);
    }

    char* find    = argv[3];
    char* replace = argv[4];

    char text[BUFFSIZE];
    char wordcur[MAXWORD + 1];

    int eof;

    do {
        eof = fgetw(text, BUFFSIZE, fp_src);

        for (long i = 0, j = 0; i < strlen(text); i++) {
            if (!isspace(text[i])) {
                if (j < MAXWORD) {
                    wordcur[j++] = text[i];
                }
            } else {
                wordcur[j] = '\0';

                if (j > 0) {  // we have a word
                    if (!strncmp(find, wordcur, MAXWORD + 1)) {
                        fputs(replace, fp_dst);
                    } else {
                        fputs(wordcur, fp_dst);
                    }

                    j = 0;
                }

                fputc(text[i], fp_dst);
            }
        }
    } while (eof == 0);

    fclose(fp_src);
    fclose(fp_dst);

    return 0;
}

int fgetw(char* str, int nitems, FILE* stream)
{
    size_t nread = fread(str, sizeof(char), nitems - 1, stream);
    str[nread]   = '\0';

    int eof = feof(stream);

    if (!isspace(str[nread - 1]) && eof == 0) {
        long back = 1;

        // FIXME(juan): you're assuming that there will be white space
        while (back < nread && !isspace(str[nread - (1 + back)])) {
            back++;
        }

        fseek(stream, -back, SEEK_CUR);
        str[nread - back] = '\0';
    }

    return eof;
}