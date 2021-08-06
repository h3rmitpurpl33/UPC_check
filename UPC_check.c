#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int read_text(char string[], int size,int flag)
{
    int len;
    if(fgets(string,size,stdin)==NULL)
    {
        printf("error : fgets() failed\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(string);
    if(len>0)
    {
        if(flag && (string[len-1] == '\n'))
        {
            string[len-1] = '\0';
            len-- ;
        }
    }else
    {
       printf("error : no input\n");
       exit(EXIT_FAILURE);
    }
    return len;
}

int main() {
char upc[13];
int i,len,flag,chk_dig,sum;

while(1)
{
    printf("enter UPC (12 digits) : ");
    len = read_text(upc,sizeof(upc),1);
    if(len!=12)
    {
        printf("error : wrong length\n");
        continue;
    }
    flag = 1;
    for(i=0;i<12;i++)
    {
        if(upc[i]<'0'||upc[i]>'9')
        {
            printf("error : only digits allowed\n");
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        break;
    }
}
    sum = 0;
    for(i=1;i<11;i+=2)
    {
        sum += upc[i] - '0';
    }
    sum *= 3;
    for(i=0;i<11;i+=2)
    {
        sum += upc[i] - '0';
    }
    chk_dig = 10-(sum%10);
    if(chk_dig == 10)
    {
        chk_dig = 0;
    }
    if(chk_dig == (upc[11]-'0')){
        printf("valid barcode\n");
    }else{
     printf("wrong check digit. The correct is %d\n" , chk_dig);
    }
return 0;
}
