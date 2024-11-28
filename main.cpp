#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 200
#define MAX_LENGTH 100

void extractStudentId(const char* email, char* studentId) {
    int i = 0;
    while (email[i] != '@' && email[i] != '\0') {
        studentId[i] = email[i];
        i++;
    }
    studentId[i] = '\0';
}

int compareEmails(const void* a, const void* b) {
    char studentIdA[MAX_LENGTH], studentIdB[MAX_LENGTH];
    extractStudentId(*(const char**)a, studentIdA);
    extractStudentId(*(const char**)b, studentIdB);
    return strcmp(studentIdA, studentIdB);
}

int main() {
    char* emails[MAX_EMAILS];
    int emailCount = 0;
    FILE* inputFile;
    if (fopen_s(&inputFile, "PG3_2024_03_02.txt", "r") != 0) {
        fprintf(stderr, "ファイルを開けませんでした。\n");
        return 1;
    }

    char buffer[MAX_LENGTH * MAX_EMAILS];
    if (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        char* token;
        char* context;
        token = strtok_s(buffer, ",", &context);
        while (token != NULL && emailCount < MAX_EMAILS) {
            emails[emailCount] = _strdup(token);
            emailCount++;
            token = strtok_s(NULL, ",", &context);
        }
    }
    fclose(inputFile);

    qsort(emails, emailCount, sizeof(char*), compareEmails);

    printf("学籍番号順に並べたメールアドレス一覧：\n");
    for (int i = 0; i < emailCount; i++) {
        printf("%s\n", emails[i]);
        free(emails[i]);
    }

    return 0;
}
