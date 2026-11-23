#include <stdio.h>
#include <stdlib.h>

#define BOT_TOKEN ""
#define CHAT_ID ""

int main() {
    char name[50], sap[20], status[10], msg[200];
    int choice;

    while (1) {
        printf("\n=== ATTENDX ===\n");
        printf("1. Present\n2. Absent\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 3) break;
        if (choice != 1 && choice != 2) {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Student name: ");
        scanf(" %49[^\n]", name);

        printf("SAP ID: ");
        scanf("%19s", sap);

        if (choice == 1)
            sprintf(status, "PRESENT");
        else
            sprintf(status, "ABSENT");

        sprintf(msg,
            "Attendance Update%%0AName: %s%%0ASAP: %s%%0AStatus: %s",
            name, sap, status);

        char cmd[600];
        sprintf(cmd,
            "curl -s -X POST "
            "\"https://api.telegram.org/bot%s/sendMessage\" "
            "-d \"chat_id=%s\" -d \"text=%s\"",
            BOT_TOKEN, CHAT_ID, msg);

        system(cmd);

        printf("\n%s notification sent!\n", status);
    }

    return 0;
}