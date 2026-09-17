#include <stdio.h>
#include <string.h>

char lines[100][200];
int lineCount = 0;

void insertLine()
{
    int lineNumber;
    char text[200];

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return ;
    }

    if (lineCount >= 100)
    {
        printf("Document is full.\n");
        return;
    }

    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter line text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    strcpy(lines[lineNumber - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine()
{
    int lineNumber;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

int main()
{
    int choice;

    printf("===== SIMPLE LINE EDITOR =====\n");

    while (1)
    {
        printf("\n1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}