#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

if (argc == 2)
{
string l;

int a=atoi(argv[1]);

l=get_string("plaintext: ");

printf("cyphertext: ");
for(int i=0; i<strlen(l); i++)

if(isalpha(l[i]))
{
    if(islower(l[i]))
        {
            printf("%c",(((l[i]- 97)+ a)%26)+ 97);
        }
    if(isupper(l[i]))
        {
            printf("%c",(((l[i]- 65)+ a)%26)+ 65);
        }
}
else
        {
            printf("%c",l[i]);
        }
    printf("\n");
    }
}
