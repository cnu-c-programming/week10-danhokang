#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int score;
    struct Student *next;
};

int main() {
    struct Student *head = NULL;
    char command[20];

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[100];
            int score;

            scanf("%s %d", name, &score);

            struct Student *new_node = (struct Student *)malloc(sizeof(struct Student));
            strcpy(new_node->name, name);
            new_node->score = score;
            new_node->next = NULL;

            if (head == NULL) {
                head = new_node;
            } else {
                struct Student *cur = head;

                while (cur->next != NULL) {
                    cur = cur->next;
                }

                cur->next = new_node;
            }
        }

        else if (strcmp(command, "delete") == 0) {
            char name[100];
            scanf("%s", name);

            struct Student *cur = head;
            struct Student *prev = NULL;

            while (cur != NULL) {
                if (strcmp(cur->name, name) == 0) {
                    if (prev == NULL) {
                        head = cur->next;
                    } else {
                        prev->next = cur->next;
                    }

                    free(cur);
                    break;
                }

                prev = cur;
                cur = cur->next;
            }
        }

        else if (strcmp(command, "print") == 0) {
            struct Student *cur = head;

            while (cur != NULL) {
                printf("%s %d\n", cur->name, cur->score);
                cur = cur->next;
            }
        }

        else if (strcmp(command, "quit") == 0) {
            struct Student *cur = head;

            while (cur != NULL) {
                struct Student *temp = cur;
                cur = cur->next;
                free(temp);
            }

            break;
        }
    }

    return 0;
}
