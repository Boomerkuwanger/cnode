
struct node {
	struct node* next;
	struct node* prev;
	void* data;
};

struct node* _init_node (struct node* next, struct node* prev, void* data) {
	struct node* nodePtr = (struct node*)malloc(sizeof(struct node));
	nodePtr->next = next;
	nodePtr->prev = prev;
	nodePtr->data = data;
	return nodePtr;
}

void _destroy_node (struct node* nodePtr) {
	free(nodePtr->data);
	free(nodePtr);
}

/*
 * dll: double linked list
 * Functions:
 * AddNode(struct *node);
 */
struct dll {
	struct node* head;
	struct node* tail;
	int numNodes;
	int nodeSize;
};

// AddNode: Add a node to a dll
void AddNode (struct dll* dllPtr, struct node* nodePtr) {
	if(0 < dllPtr->numNodes){
		dllPtr->tail->next = nodePtr;
		nodePtr->prev = dllPtr->tail;
		dllPtr->tail = nodePtr;
		nodePtr->next = NULL;
	} else {
		dllPtr->head = dllPtr->tail = nodePtr;
		nodePtr->next = nodePtr->prev = NULL;
	}
	dllPtr->numNodes++;
}

void DeleteNode (struct dll* dllPtr, struct node* nodePtr){
	return;
}

struct dll* _init_dll () {
	struct dll* dllPtr = (struct dll*)malloc(sizeof(struct dll));
	return dllPtr;
}

void _destroy_dll (struct dll* dllPtr) {
	if(0 < dllPtr->numNodes && dllPtr->head) {
		struct node* tempPtr = dllPtr->head;

		while(tempPtr->next){
			dllPtr->head = tempPtr->next;
			_destroy_node(tempPtr);
			tempPtr = dllPtr->head;
		}
		_destroy_node(dllPtr->head);
	}
	free(dllPtr);
}

