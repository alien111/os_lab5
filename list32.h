#ifndef D_LIST_H
#define D_LIST_H 1

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef struct _listItem {

	int32_t value;

	//listItem() = default;
	//listItem(int32_t);

	struct _listItem * next;

} listItem;

typedef struct _List {

	listItem * head;
	listItem * tail;

	int size;


	//List();
	

} List;

extern void listItemInit(listItem * li, int32_t data);

extern void listInit(List * l);
extern void push(List * l, int32_t data);
extern void print(List * l);
extern void destroy(List * l);

extern void erase(List * l, listItem * it);
extern void placeAfter(List * l, listItem * it, int32_t data);

#endif