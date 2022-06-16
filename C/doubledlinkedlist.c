// DOUBLED SIMPLY LINKED LISTS (without tail pointer or last node pointer)

// directivas de preprocesamiento
#include<stdio.h>
#include<stdlib.h>

// estructura nodo, el typedef para utilizar solamente Node en el codigo y no Struct node.
typedef struct Node {
	int data;
	struct Node * next_node;
	struct Node * prev_node;
}Node;

// Algoritmo para ver el ultimo nodo (recorremos cada sector next_node de cada nodo hasta que el next_node sea = NULL y paramos)
struct Node * see_last_node(Node * Firstnode) {
	Node * next = Firstnode->next_node;
	Node * actual_node = Firstnode;
	while (next != NULL) {
		actual_node = next;
		next = next->next_node;
	} 
	return actual_node;
}

// agregando nodo con Big-O(n) runtime ya que por cada nodo nuevo hay que recorrer los N elementos previos (esto si no usamos tail pointer)
void append_node(Node * firstnode,Node * to_append) {
	
	Node * last_node;
	last_node = see_last_node(firstnode);
	last_node->next_node = to_append;
	to_append->prev_node = last_node;
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
	
	printf("\n - Informacion de los nodos sin conectar  - ");
	see_node(head);
	see_node(&node2);
	see_node(&node3);
	see_node(&node4);
	printf("\n ------------------ \n - Agregando nodo 2,3, 4 a la lista ");
	append_node(head, &node2);
	append_node(head, &node3);
	append_node(head, &node4);
	printf("\n - Ver la info del ultimo nodo (ahora deberia ser el nodo 4 el ultimo) - ");
	printf("\n Direccion ultimo nodo: %p", see_last_node(head));
	printf("\n - Info de los tres nodos - ");
	see_node(head);
	see_node(&node2);
	see_node(&node3);
	see_node(&node4);
	return 0;
}

