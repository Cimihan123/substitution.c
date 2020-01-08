#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[])
{
    //checking if the input has 2 command line argument
    if (argc ==2)
    {
        //checking if the input has 26 digits
        if (strlen(argv[1]) == 26)
        {
            string key = argv[1];
            int i = 0, j = 0;
            while (key[i] !='\0')
            {
                //checking if the input is non alphabet character
                if (key[i] < 65 || key[i] > 90)
                {
                    if (key[i] < 97|| key[i] > 122)
                    {
                        printf("Key must only contain alphabetic characters\n");
                        return 1;
                    }
                }
                //checking if the input is repeated
                while(key[j] != '\0')
                {
                    if (key[i] == key[j+1])
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                    j++;
                }
                //converting all the given input alphabet into capital letter
                if (key[i]>90)
                {
                    key[i] = key[i]- ('a'-'A');
                }
                i++;
            }
            int z=0;
            //prompting user for input using cs50 library header file cs50.h
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            //converting plaintext into ciphertext
            while (plaintext[z] != '\0')
            {
                if(plaintext[z]>='A' && plaintext[z]<='Z')
                {
                    printf("%c", key[plaintext[z] % 'A']);
                }
                else if (plaintext[z]>='a' && plaintext[z]<='z')
                {
                    printf("%c", key[plaintext[z] % 'a']+ ('a'-'A'));
                }
                else
                {
                  printf("%c", plaintext[z]);
                }
                z++;
            }
        }
        //if the input is less than 26 character
        else
        {
            printf("Key must contain 26 character.\n");
            return 1;
        }
    //if the command line argument is more or less than 2
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    printf("\n");
    return 0;
}
