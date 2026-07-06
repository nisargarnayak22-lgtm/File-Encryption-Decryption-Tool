#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void login();
void encryptFile();
void decryptFile();
void viewLog();
void about();
void writeLog(char action[]);

int loggedIn = 0;

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("   SECURE FILE ENCRYPTION TOOL V2.0\n");
        printf("=========================================\n");
        printf("1. Login\n");
        printf("2. Encrypt File\n");
        printf("3. Decrypt File\n");
        printf("4. View Activity Log\n");
        printf("5. About\n");
        printf("6. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                login();
                break;

            case 2:
                if(loggedIn)
                    encryptFile();
                else
                    printf("\nPlease Login First!\n");
                break;

            case 3:
                if(loggedIn)
                    decryptFile();
                else
                    printf("\nPlease Login First!\n");
                break;

            case 4:
                if(loggedIn)
                    viewLog();
                else
                    printf("\nPlease Login First!\n");
                break;

            case 5:
                about();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice!=6);

    return 0;
}
void login()
{
    char username[30];
    char password[30];

    printf("\nUsername : ");
    scanf("%s",username);

    printf("Password : ");
    scanf("%s",password);

    if(strcmp(username,"admin")==0 &&
       strcmp(password,"admin123")==0)
    {
        loggedIn=1;
        printf("\nLogin Successful!\n");
        writeLog("Login Successful");
    }
    else
    {
        printf("\nInvalid Username or Password!\n");
        writeLog("Failed Login");
    }
}

void about()
{
    printf("\n=================================\n");
    printf("Secure File Encryption Tool\n");
    printf("Version : 2.0\n");
    printf("Language : C\n");
    printf("Author : Nisarga Nayak\n");
    printf("B.Tech Networks\n");
    printf("=================================\n");
}

void writeLog(char action[])
{
    FILE *fp;
    time_t t;

    fp=fopen("log.txt","a");

    if(fp==NULL)
        return;

    t=time(NULL);

    fprintf(fp,"%s : %s",ctime(&t),action);
    fprintf(fp,"\n");

    fclose(fp);
}
void encryptFile()
{
    FILE *input, *output;
    char inputFile[100];
    char outputFile[100];
    int key;
    int ch;

    printf("\nEnter Input File Name: ");
    scanf("%s", inputFile);

    printf("Enter Output File Name: ");
    scanf("%s", outputFile);

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

    printf("\n=====================================\n");
    printf("File Encrypted Successfully!\n");
    printf("Input File      : %s\n", inputFile);
    printf("Encrypted File  : %s\n", outputFile);
    printf("Encryption Key  : %d\n", key);
    printf("=====================================\n");

    char logMessage[200];
    sprintf(logMessage, "Encrypted %s -> %s (Key=%d)", inputFile, outputFile, key);
    writeLog(logMessage);
}
void decryptFile()
{
    FILE *input, *output;
    char inputFile[100];
    char outputFile[100];
    int key;
    int ch;

    printf("\nEnter Encrypted File Name: ");
    scanf("%s", inputFile);

    printf("Enter Output File Name: ");
    scanf("%s", outputFile);

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

    printf("\n=====================================\n");
    printf("File Decrypted Successfully!\n");
    printf("Encrypted File : %s\n", inputFile);
    printf("Output File    : %s\n", outputFile);
    printf("Decryption Key : %d\n", key);
    printf("=====================================\n");

    char logMessage[200];
    sprintf(logMessage, "Decrypted %s -> %s (Key=%d)", inputFile, outputFile, key);
    writeLog(logMessage);
}

void viewLog()
{
    FILE *fp;
    char ch;

    fp = fopen("log.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Activity Log Found!\n");
        return;
    }

    printf("\n=====================================\n");
    printf("          ACTIVITY LOG\n");
    printf("=====================================\n\n");

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);

    printf("\n=====================================\n");
}