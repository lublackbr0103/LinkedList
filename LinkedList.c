#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#define ESC 0x1B

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insert_beginning(Node** list, int value){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {exit(1);}

    new_node->data = value;
    new_node->next = *list;
    *list = new_node;
}

void insert_end(Node** list, int value){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {exit(2);}

    new_node->data = value;
    new_node->next = NULL;

    if (*list == NULL)
    {
        *list = new_node;
        return;
    }

    Node* current_node = *list;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void deallocate(Node** list){
    Node* current_node = *list;
    while (current_node != NULL)
    {
        Node* aux = current_node;
        current_node = current_node->next;
        free(aux);
    }
    *list = NULL;    
}

void display(){
    printf("------LINKED LIST------\n\n");
    printf("----------------------------------------------------------------------------------\n\n\n\n");
    printf("----------------------------------------------------------------------------------\n");
    sleep(1);
    system("cls");
}

void main(){

    Node* list = NULL;
    int num_input, option;
    char answer[10];
    int command_key;
    bool key = true;

    do
    {
        fflush(stdin);
        system("cls");
        printf("------LINKED LIST------\n\n");
        printf("ADD TO BEGINNING\tPress [1]\nADD TO THE END\t\tPress [2]\nFINISH\t\t\tPress [0]\n\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        system("cls");

        if (option == 0)
        {
            system("cls");
            break;
        }

        else if (option == 1)
        {
            do
            {
                fflush(stdin);
                system("cls");
                printf("------LINKED LIST------\n\n");
                printf("To exit\tPress [ESC]\n");
                printf("\nENTER THE ELEMENT: ");

                command_key = getch();

                // #define ESC 0x1B
                if (command_key == ESC)
                {
                    key = false;
                    break;
                }

                else
                {
                    putchar(command_key);
                    answer[0] = command_key;
                    fgets(answer + 1, sizeof(answer - 1), stdin);
                    sscanf(answer, "%d", &num_input);

                    if (!(sscanf(answer, "%d", &num_input)))
                    {
                        printf("Invalid input!\nPlease enter only numbers...\n");
                        sleep(1);
                        key = true;
                        continue;
                    }

                    if (sscanf(answer, "%d", &num_input))
                    {
                        insert_beginning(&list, num_input);
                        printf("VALUE INSERTED!\n");
                        sleep(1);
                    }
                    else
                    {
                        printf("Something went wrong!\nCouldn't store the value, please try again...");
                        sleep(2);
                    }
                }
                key = true;
            } while (key);
        }

        else if (option == 2)
        {
            do
            {
                fflush(stdin);
                system("cls");
                printf("------LINKED LIST------\n\n");
                printf("\nTo exit\tPress [ESC]\n");
                printf("ENTER THE ELEMENT: ");

                command_key = getch();

                // #define ESC 0x1B
                if (command_key == ESC)
                {
                    key = false;
                    break;
                }
                
                else
                {
                    putchar(command_key);
                    answer[0] = command_key;
                    fgets(answer + 1, sizeof(answer - 1), stdin);
                    sscanf(answer, "%d", &num_input);

                    if (!(sscanf(answer, "%d", &num_input)))
                    {
                        printf("Invalid input!\nPlease enter only numbers...\n");
                        sleep(1);
                        key = true;
                        continue;
                    }
                    
                    if (sscanf(answer, "%d", &num_input))
                    {
                        insert_end(&list, num_input);
                        printf("VALUE INSERTED!\n");
                        sleep(1);
                    }
                    else
                    {
                        printf("Something went wrong!\nCouldn't store the value, please try again...");
                        sleep(2);
                    }
                }
                key = true;
            } while (key);
        }
        
        else
        {
            system("cls");
            printf("------LINKED LIST------\n\n");
            printf("Invalid input... Try again!\n");
            sleep(2);
            system("cls");
        }
    } while (true);
    
    Node* current_node = list;

    printf("Processing...");
    sleep(2);

    system("cls");
    display();
    printf("------LINKED LIST------\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Your linked list:\n\n");
    while (current_node != NULL)
    {
        printf("[%d] ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n----------------------------------------------------------------------------------");
    sleep(2);
    printf("\nThanks for using Linked List app!\n");
    sleep(1);

    deallocate(&list);
    _CrtDumpMemoryLeaks();

    return;
}