#include <stdio.h>
#include <stdlib.h>

#define KEY 3

void encryptFile();
void decryptFile();

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" FILE ENCRYPTION & DECRYPTION TOOL\n");
        printf("=====================================\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                encryptFile();
                break;

            case 2:
                decryptFile();
                break;

            case 3:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 3);

    return 0;
}

void encryptFile()
{
    FILE *input, *output;
    char ch;

    input = fopen("input.txt", "r");

    if(input == NULL)
    {
        printf("\ninput.txt not found!\n");
        return;
    }

    output = fopen("encrypted.txt", "w");

    while((ch = fgetc(input)) != EOF)
    {
        fputc(ch + KEY, output);
    }

    fclose(input);
    fclose(output);

    printf("\nFile Encrypted Successfully!\n");
}

void decryptFile()
{
    FILE *input, *output;
    char ch;

    input = fopen("encrypted.txt", "r");

    if(input == NULL)
    {
        printf("\nencrypted.txt not found!\n");
        return;
    }

    output = fopen("decrypted.txt", "w");

    while((ch = fgetc(input)) != EOF)
    {
        fputc(ch - KEY, output);
    }

    fclose(input);
    fclose(output);

    printf("\nFile Decrypted Successfully!\n");
}