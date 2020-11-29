//
// Created by Paolo on 28/11/2020.
//

#ifndef PROGETTOLSO_DIRLIST_H
#define PROGETTOLSO_DIRLIST_H

#include <stdio.h>

typedef struct Node {
    char *dirValue;
    struct Node *next;
} DirNode;

typedef struct {
    DirNode *head;
} DirList;

void initList(DirList *);

void addElement(DirList *, char *);

size_t getLength(DirList);

char *getItem(DirList, int);

void destroyList(DirList *);

//Da aggiungere altri metodi !!

#endif //PROGETTOLSO_DIRLIST_H
