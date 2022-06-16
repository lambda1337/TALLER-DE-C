// LINKED LISTS

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node * next_node;
}Node;


void append_node(Node * Lastnode, Node * to_append) {
	Lastnode->next_node = to_append;
}

void see_node(Node * node) {
	printf("\n | Node address: %p | Node data: %d | Node next: %p \n",node, node->data, node->next_node);
}

void modify_node_data(Node * node) {
	printf("\n New data node: ");
	scanf("%d", &node->data);
}

int main (void) {
	
	// creating nodes structs
	Node node1;
	Node node2;
	Node node3;
	
        //inicializar nodos
     node1.data = 0;
     node1.next_node = NULL;
     node2.data = 0;
     node2.next_node = NULL;
     node3.data = 0;
     node3.next_node = NULL;

	// see node1 info
	printf("\n- Node 1 info");
	see_node(&node1);
	// see node2 info
	printf("\n- Node 2 info");
	see_node(&node2);
	// see node3 info
	printf("\n- Node 3 info");
	see_node(&node3);

	// modify data state of node 1
	modify_node_data(&node1);
	// modify data state of node 2
	modify_node_data(&node2);
	// modify data state of node 3
	modify_node_data(&node3);
	
	printf("\n- ADD NODE2 TO NODE1");
	// append node2 pointer in to node1 next node pointer
	append_node(&node1, &node2);
	printf("\n- ADD NODE3 TO NODE2");
	// append node3 pointer in to node2 next node pointer
	append_node(&node2, &node3);

	// see updated node1
	printf("\n- Node 1 updated data");
	see_node(&node1);
	// see updated node2
	printf("\n- Node 2 updated info");
	see_node(&node2);
	// see updated node3
	printf("\n- Node 3 updated info");
	see_node(&node3);
		
	return 0;
}

