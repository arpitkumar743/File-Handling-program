#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *fileName) {
    FILE *f = fopen(fileName, "w");
    if (f == NULL) {
        printf("Could not create file.\n");
        return;
    }

    char text[200];
    printf("Type something to write into the file: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, f);
    fclose(f);
    printf("Text written successfully.\n");
}

void addMoreData(const char *fileName) {
    FILE *f = fopen(fileName, "a");
    if (f == NULL) {
        printf("File not found to append.\n");
        return;
    }

    char moreText[200];
    printf("Enter more text to add: ");
    fgets(moreText, sizeof(moreText), stdin);

    fputs(moreText, f);
    fclose(f);
    printf("Appended to file successfully.\n");
}

void readFileContent(const char *fileName) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        printf("Unable to open the file for reading.\n");
        return;
    }

    char line[200];
    printf("\n--- File Output ---\n");
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
    printf("\n-------------------\n");
}

int main() {
    char fileName[] = "intern_file.txt";
    int option;

    while (1) {
        printf("\n== File Menu ==\n");
        printf("1. Create and Write\n");
        printf("2. Append Data\n");
        printf("3. Read File\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar();  // clear input buffer

        if (option == 1) {
            writeToFile(fileName);
        } else if (option == 2) {
            addMoreData(fileName);
        } else if (option == 3) {
            readFileContent(fileName);
        } else if (option == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}
