#include "list32.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

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

	void (*listItemInit)(listItem * li, int32_t data);

	void (*listInit)(List * l);
	void (*push)(List * l, int32_t data);
	void (*print)(List * l);
	void (*destroy)(List * l);

	void (*erase)(List * l, listItem * it);
	void (*placeAfter)(List * l, listItem * it, int32_t data);

	void* libHandle;
    libHandle = dlopen("./liblist32dyn.so", RTLD_LAZY);
    if (!libHandle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(-1);
    }


    listInit = dlsym(libHandle, "listInit");
    listItemInit = dlsym(libHandle, "listItemInit");
    push = dlsym(libHandle, "push");
    print = dlsym(libHandle, "print");
    destroy = dlsym(libHandle, "destroy");
    erase = dlsym(libHandle, "erase");
    placeAfter = dlsym(libHandle, "placeAfter");


    List list;
	(*listInit)(&list);
	int cmd;

	while (true) {
		menu();
		scanf("%d", &cmd);

		if (cmd == 1) {
			int32_t tmp;

			printf("Enter int32_t value > ");

			scanf("%d", &tmp);
			
			(*push)(&list, tmp);


		} else if (cmd == 2) {

			(*print)(&list);

		} else if (cmd == 3) {

			(*destroy)(&list);

		} else if (cmd == 4) {

			int position;

			printf("Enter position > ");
			scanf("%d", &position);

			if (position >= 0 && position < list.size) {
				listItem * it = list.head;

				for (int i = 0; i < position; i++) 
					it = it -> next;

				(*erase)(&list, it);
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

				(*placeAfter)(&list, it, tmp);
			} else {
				printf("ERROR : wrong position\n");
			}

		} else if (cmd == 6) {
			dlclose(libHandle);
			return 0;

		} else {

			printf("ERROR : wrong command\n");

		}

	}


}