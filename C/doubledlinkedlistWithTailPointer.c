// DOUBLED SIMPLY LINKED LISTS WITH TAIL POINTER!

// directivas de preprocesamiento
#include<stdio.h>
#include<stdlib.h>

// estructura nodo, el typedef para utilizar solamente Node en el codigo y no Struct node.
typedef struct Node {
	int data;
	struct Node * next_node;
	struct Node * prev_node;
}Node;

// agregando nodo con Big-O(K) runtime ya que tenemos tail pointer, agregar a lo ultimo sera tan simple como una constante de operaciones.
void append_node(Node * lastnode,Node * to_append) {
	to_append->prev_node = lastnode;
	lastnode->next_node = to_append;
	lastnode -> =  to_append;
}

// ver info de un nodo
void see_node(Node * node) {
	printf("\n | Node address: %p | Node data: %d | Node next: %p | Node prev: %p \n",node, node->data, node->next_node, node->prev_node);
}

void modify_node_data(Node * node) {
	printf("\n Nueva data del nodo: ");
	scanf("%d", &node->data);
}

int main (void) {
	// creando instancias de la estructura nodo
	Node node1;
	Node node2;
	Node node3;
	Node node4;
	
    //inicializar nodos
	node1.data = 0;
	node1.next_node = NULL;
	node1.prev_node = NULL;
	node2.data = 0;
	node2.next_node = NULL;
	node2.prev_node = NULL;
	node3.data = 0;
	node3.next_node = NULL;
	node3.prev_node = NULL;
	node4.data = 0;
	node4.next_node = NULL;
	node4.prev_node = NULL;
	// el primer nodo llamado head
	Node * head = &node1;
	Node * last = &node1;
	
	printf("\n - Informacion de los nodos sin conectar  - ");
	see_node(head);
	see_node(&node2);
	see_node(&node3);
	see_node(&node4);
	printf("\n ------------------ \n - Agregando nodo 2,3, 4 a la lista ");
	append_node(last, &node2);
	append_node(last, &node3);
	append_node(last, &node4);
	printf("\n - Ver la info del ultimo nodo (ahora deberia ser el nodo 4 el ultimo) - ");
	printf("\n Direccion ultimo nodo: %p", last);
	printf("\n - Info de los tres nodos - ");
	see_node(head);
	see_node(&node2);
	see_node(&node3);
	see_node(&node4);
	return 0;
}

