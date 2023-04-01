#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    FILE *fp=fopen("myfile.txt","r");
    fseek(fp,0,SEEK_END);
    int size=ftell(fp);
    rewind(fp);

    char line[size];
    char c;
    int index=0;
    while((c=fgetc(fp))!=EOF){
        line[index++]=c;
    }
    rewind(fp);
    printf("%s\n",line);

    int a=0;
    //fgets to start writing from that position,line+a is the length of the file pointer to read
    while(fgets(line+a,size,fp)!=NULL){
        a=strlen(line);

    }
    printf("%s\n",line);

    fclose(fp);

    FILE *fp1=fopen("myfile.txt","a+");
    rewind(fp1);
    char currentword[255];
    //swap abc 1234567
    for(int index=0,word_index=0;index<size;index++,word_index++){


        if(line[index] == ' '){
            if(strlen(currentword)>0) {
                if (strcmp(argc, currentword)) {

                } else {

                }
                currentword[0]='\0';
                word_index=0;
            }

            fprintf("Word: %s",currentword);
            continue;
        }
        currentword[word_index]=line[index];
        currentword[word_index+1]='\0';
    }

    fclose(fp1);
}

