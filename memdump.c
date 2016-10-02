#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_WIDTH 16
void memdump(char * p , int len) {
    char ans[LINE_WIDTH + 1];

    for(int i = 0; i < len; i++) {
            if(i % LINE_WIDTH == 0) {
                    printf("0x%016lX: ", (unsigned long)p+i);
            }
            //get the value at p and truncate to one byte
            int c = p[i] & 0xFF;

            //print first byte as hex
            printf("%02X ", c);
            
            //if the char is between 32 and 127 then it is valid ascii other wise it is a .
            ans[i % LINE_WIDTH] = ((c >= 32 && c <= 127) ? (char)c : '.');

            if((i + 1) % LINE_WIDTH == 0) {
                    ans[i % LINE_WIDTH + 1] = '\0';
                    printf(" %s\n", ans);
            }
    }
    
    if(i % LINE_WIDTH != 0) {
            ans[i % LINE_WIDTH] = '\0';
            //add correct padding and then print the leftover string
            for(i = i % LINE_WIDTH; i < LINE_WIDTH; i++) {
                    printf("   ");
            }
            printf(" %s\n", ans);
    }

}
struct X{
        char a;
        int i;
        char b;
        int *p;
};
struct List {
        char * str;
        struct List * next;
};
int main() {
        char str[20];
        int a = 5;
        int b = -5;
        double y = 12;
        struct X x;
        struct List * head;
        x.a = 'A';
        x.i = 9;
        x.b = '0';
        x.p = &x.i;
        strcpy(str, "Hello world\n");
        printf("&str=0x%lX=%s\n", (unsigned long)&str, str);
        printf("&a=0x%lX=%d\n", (unsigned long)&a, a);
        printf("&b=0x%lX=%d\n", (unsigned long)&b, b);
        printf("&x=0x%x\n", &x.a);
        printf("&y=0x%x\n", &y);
        memdump((char *) &x.a, 64);
        head = (struct List *) malloc(sizeof(struct List));
        head->str=strdup("Welcome ");
        head->next = (struct List *) malloc(sizeof(struct List));
        head->next->str = strdup("to ");
        head->next->next = (struct List *) malloc(sizeof(struct List));
        head->next->next->str = strdup("cs250");
        head->next->next->next = NULL;
        printf("head=0x%x\n", head);
        memdump((char*) head, 128);
}
