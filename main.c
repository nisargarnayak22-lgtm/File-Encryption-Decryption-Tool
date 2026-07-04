#include <stdio.h>
#include <stdlib.h>

void encryptFile();
void decryptFile();

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("     FILE ENCRYPTION & DECRYPTION TOOL\n");
        printf("=========================================\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
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
                printf("\nThank you for using the program!\n");
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
    char inputFile[100];
    char outputFile[100];
    int key;
    int ch;

    printf("\nEnter Input File Name: ");
    scanf("%99s", inputFile);

    printf("Enter Output File Name: ");
    scanf("%99s", outputFile);

    printf("Enter Encryption Key: ");
    scanf("%d", &key);

    input = fopen(inputFile, "r");

    if(input == NULL)
    {
        printf("\nError: Unable to open %s\n", inputFile);
        return;
    }

    output = fopen(outputFile, "w");

    if(output == NULL)
    {
        printf("\nError: Unable to create %s\n", outputFile);
        fclose(input);
        return;
    }

    while((ch = fgetc(input)) != EOF)
    {
        fputc(ch + key, output);
    }

    fclose(input);
    fclose(output);

    printf("\n=========================================\n");
    printf("File Encrypted Successfully!\n");
    printf("Encrypted File: %s\n", outputFile);
    printf("Encryption Key: %d\n", key);
    printf("=========================================\n");
}
void decryptFile()
{
    FILE *input, *output;
    char inputFile[100];
    char outputFile[100];
    int key;
    int ch;

    printf("\nEnter Encrypted File Name: ");
    scanf("%99s", inputFile);

    printf("Enter Output File Name: ");
    scanf("%99s", outputFile);

    printf("Enter Decryption Key: ");
    scanf("%d", &key);

    input = fopen(inputFile, "r");

    if(input == NULL)
    {
        printf("\nError: Unable to open %s\n", inputFile);
        return;
    }

    output = fopen(outputFile, "w");

    if(output == NULL)
    {
        printf("\nError: Unable to create %s\n", outputFile);
        fclose(input);
        return;
    }

    while((ch = fgetc(input)) != EOF)
    {
        fputc(ch - key, output);
    }

    fclose(input);
    fclose(output);

    printf("\n=========================================\n");
    printf("File Decrypted Successfully!\n");
    printf("Decrypted File: %s\n", outputFile);
    printf("Decryption Key: %d\n", key);
    printf("=========================================\n");
}