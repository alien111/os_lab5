#include "list32.h"

void listItemInit(listItem * li, int32_t data) {

	li -> value = data;
	li -> next = NULL;

}

void listInit(List * l) {

	l -> size = 0;
	l -> head = NULL;
	l -> tail = NULL;

}

void push(List * l, int32_t data) {

	l -> size++;

	listItem * tmp = malloc(sizeof(listItem));
	listItemInit(tmp, data);

	if (l -> head == NULL) {
		
		l -> head = tmp;
		l -> tail = tmp;
	
	} else {

		l -> tail -> next = tmp;
		l -> tail = tmp;

	}

}

void print(List * l) {

	for (listItem * it = l -> head; it != NULL; it = it -> next) {

		printf("%d", it -> value);
		printf(" ");

	}
 
	printf("\n");

}

void destroy(List * l) {

	if (l -> size == 0) {                        // * -> * -> * -> * -> * -> 0

		return;

	} else {

		listItem * tmp = l -> head;

		while (tmp != NULL) {

			listItem * buf = tmp;
			tmp = tmp -> next;
			free(buf);

		}

		l -> head = NULL;
		l -> tail = NULL;
		l -> size = 0;


	}

}

void erase(List * l, listItem * it) {

	if (it == l -> head) {
		l -> head = l -> head -> next;
		free(it);
		return;
	}

	listItem * it__ = l -> head;

	while (it__ -> next != it)
		it__ = it__ -> next;

	it__ -> next = it -> next;

	free(it);

	l -> size--;

}

void placeAfter(List * l, listItem * it, int32_t data) {

	if (l -> size == 0)
		return;

	listItem * it__ = l -> head;

	while (it__ != it) {
		it__ = it__ -> next;
	}

	listItem * tmp = malloc(sizeof(listItem));
	listItemInit(tmp, data);

	tmp -> next = it__ -> next;
	it__ -> next = tmp;

	l -> size++;

}