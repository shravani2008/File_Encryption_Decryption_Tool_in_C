#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

void encryptFile(const char *inputFile, const char *outputFile, const char *key);
void decryptFile(const char *inputFile, const char *outputFile, const char *key);
void logActivity(const char *operation, const char *inputFile, const char *outputFile);

int main() {
    int choice;
    char inputFile[100], outputFile[100], key[50];

    printf("=============================================\n");
    printf("      FILE ENCRYPTION & DECRYPTION TOOL     \n");
    printf("=============================================\n\n");

    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("---------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter input file name (e.g., input.txt): ");
            scanf("%s", inputFile);
            printf("Enter output file name (e.g., encrypted.txt): ");
            scanf("%s", outputFile);
            printf("Enter secret key: ");
            scanf("%s", key);
            encryptFile(inputFile, outputFile, key);
            logActivity("ENCRYPTION", inputFile, outputFile);
            break;

        case 2:
            printf("\nEnter input file name (e.g., encrypted.txt): ");
            scanf("%s", inputFile);
            printf("Enter output file name (e.g., decrypted.txt): ");
            scanf("%s", outputFile);
            printf("Enter secret key: ");
            scanf("%s", key);
            decryptFile(inputFile, outputFile, key);
            logActivity("DECRYPTION", inputFile, outputFile);
            break;

        case 3:
            printf("\nExiting program... Goodbye!\n");
            exit(0);
            break;

        default:
            printf("\n Invalid choice! Please try again.\n");
    }

    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *fin = fopen(inputFile, "rb");
    FILE *fout = fopen(outputFile, "wb");

    if (!fin || !fout) {
        printf("\nError opening files!\n");
        exit(1);
    }

    size_t keyLen = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i;

    printf("\nEncrypting file...\n");

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
        for (i = 0; i < bytesRead; i++)
            buffer[i] ^= key[i % keyLen]; 
        fwrite(buffer, 1, bytesRead, fout);
    }

    printf("Encryption completed! Output saved as '%s'\n", outputFile);

    fclose(fin);
    fclose(fout);
}

void decryptFile(const char *inputFile, const char *outputFile, const char *key) {

    encryptFile(inputFile, outputFile, key);
    printf("Decryption completed! Output saved as '%s'\n", outputFile);
}

void logActivity(const char *operation, const char *inputFile, const char *outputFile) {
    FILE *logFile = fopen("activity_log.txt", "a");
    if (logFile == NULL) return;

    time_t now = time(NULL);
    fprintf(logFile, "%s | %s | Input: %s | Output: %s\n",
            ctime(&now), operation, inputFile, outputFile);
    fclose(logFile);
}
