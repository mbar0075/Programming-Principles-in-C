#include <stdio.h>
#define SIZE 70

typedef  short int num;

typedef union {
   num a;
} u_ipv4;

void Conversion(short int n);

int main(void)
{
    u_ipv4 ip[4];
    printf("Enter Ipv4 address\n");
    scanf("%hd.%hd.%hd.%hd", &ip[0],&ip[1],&ip[2],&ip[3]);
    printf("\nPrinting in octet form\n");
    printf("%hd.%hd.%hd.%hd", ip[0], ip[1], ip[2], ip[3]);
    printf("\nPrinting in hex form\n");
    Conversion(ip[0].a);
    printf(".");
    Conversion(ip[1].a);
    printf(".");
    Conversion(ip[2].a);
    printf(".");
    Conversion(ip[3].a);
    return 0;
}

void Conversion(short int n)   // hex conversion
{
    char output;
    if ( n>0) {
        switch(n%16){   //Switch statement to transform numbers into hexadecimal characters
            case 10:output='A';
                break;
            case 11:output='B';
                break;
            case 12:output='C';
                break;
            case 13:output='D';
                break;
            case 14:output='E';
                break;
            case 15:output='F';
                break;
            default:output=n%16+'0'; // Added 0 to convert an int to a character
        }
        Conversion(n/16);
        printf("%c",output);
    }
}
