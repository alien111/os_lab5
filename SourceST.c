#include "list32.h"
#include <string.h>
#include <stdio.h>

/*
extern void listItemInit(listItem * li, int32_t data);

extern void listInit(List * l);
extern void push(List * l, int32_t data);
extern void print(List * l);
extern void destroy(List * l);

extern void erase(List * l, listItem * it);
extern void placeAfter(List * l, listItem * it, int32_t data);

*/

void menu() {
	printf("______________________________________________________\n");
	printf("1 : push\n");
	printf("2 : print\n");
	printf("3 : destroy\n");
	printf("4 : erase with iterator\n");
	printf("5 : place with iterator\n");
	printf("6 : quit\n");
	printf("> ");
}

int main() {

	List list;
	listInit(&list);
	int cmd;

	while (true) {
		menu();
		scanf("%d", &cmd);

		if (cmd == 1) {
			int32_t tmp;

			printf("Enter int32_t value > ");

			scanf("%d", &tmp);
			
			push(&list, tmp);


		} else if (cmd == 2) {

			print(&list);

		} else if (cmd == 3) {

			destroy(&list);

		} else if (cmd == 4) {

			int position;

			printf("Enter position > ");
			scanf("%d", &position);

			if (position >= 0 && position < list.size) {
				listItem * it = list.head;

				for (int i = 0; i < position; i++) 
					it = it -> next;

				erase(&list, it);
			} else {
				printf("ERROR : wrong position\n");
			}

		} else if (cmd == 5) {

			int position;

			printf("Enter position > ");
			scanf("%d", &position);

			if (position >= 0 && position < list.size) {
				int32_t tmp;
				printf("Enter int32_t value > ");
				scanf("%d", &tmp);

				listItem * it = list.head;

				for (int i = 0; i < position; i++) 
					it = it -> next;

				placeAfter(&list, it, tmp);
			} else {
				printf("ERROR : wrong position\n");
			}

		} else if (cmd == 6) {

			return 0;

		} else {

			printf("ERROR : wrong command\n");

		}

	}

}