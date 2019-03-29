//
//  main.c
//  Lab_12
//
//  Created by Александр on 3/22/19.
//  Copyright © 2019 Александр. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Table Table;

struct Table {
    int  key;
    int  val;
    Table *next;
};

Table* TableSearch(Table *p, int key) {
    for (; p != NULL; p = p->next) {
        if (p->key == key) {
            printf("key: %d\t val: %d\n", p->key, p->val);
            return p;
        }
    }
    return NULL;
}

void PrintTable(Table *p) {
    if (!p) printf("Empty!\n");
    while (p) {
        printf("key: %d\t val: %d\n", p->key, p->val);
        p = p->next;
    }
}

void AddTable(Table **l, int key, int val) {
    Table *newElem = (Table*)malloc(sizeof(Table));
    newElem->next = *l;
    newElem->key = key;
    newElem->val = val;
    *l = newElem;
}


int main()
{
    Table *table = NULL;
    int keyr, minkey = 100, valr, num;
    printf("Enter number : ");
    scanf("%d", &num);
    printf("\n");
    int i;
    srand(time(NULL));
    for (i = 0; i < num; ++i) {
        keyr = rand() % 10;
        valr = rand() % 100;
        AddTable(&table, keyr, valr);
        if (keyr < minkey) minkey = keyr;
    }
    PrintTable(table);
    printf("\nMin key: \n");
    TableSearch(table, minkey);
}
