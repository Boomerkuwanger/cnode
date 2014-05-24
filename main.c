#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(){
	struct dll* list = _init_dll();
	int arr[10];
	int i = 0;
	int *y = &arr[0];
	for(i = 0; i < 10; i++) {
		arr[i] = i+1;
		AddNode(list, _init_node(NULL, NULL, y));
		y++;
	} 

	struct node* nomad = list->head;
	while(nomad->next){
		printf ("%d", *((int*)nomad->data));
		nomad = nomad->next;
	}
	getchar();
	return 0;
}
 