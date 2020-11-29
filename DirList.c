//
// Created by Paolo on 28/11/2020.
//

#include <stdlib.h>
#include "DirList.h"

void initList(DirList *dirList) {
    dirList->head = 0;
}

void addElement(DirList *dirList, char *dir) {
    DirNode *current;
    DirNode *newItem = malloc(sizeof(DirNode));
    newItem->dirValue = dir;
    newItem->next = 0;

    if (!dirList->head) {
        dirList->head = newItem;
    } else {
        current = dirList->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newItem;
    }
}

size_t getLength(DirList dirList) {
    DirNode *current;
    int length = 1;

    if (!dirList.head) {
        return 0;
    } else {
        current = dirList.head;
        while (current->next) {
            current = current->next;
            length++;
        }
        return length;
    }
}

char *getItem(DirList dirList, int index) {
    DirNode *current;
    int count = 0;

    if (!dirList.head) {
        return 0;
    } else {
        current = dirList.head;
        while (current) {
            if (index == count)
                return current->dirValue;
            else {
                current = current->next;
                count++;
            }
        }
    }
    return 0;
}

void destroyList(DirList *dirList) {
    DirNode *current, *next;
    current = dirList->head;

    while (current) {
        next = current;
        current = current->next;
        free(next);
    }

    dirList->head = NULL;
}