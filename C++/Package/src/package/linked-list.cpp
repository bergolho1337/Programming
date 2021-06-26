#include "linked-list.h"

LinkedList::LinkedList ()
{
    this->num_nodes = 0;
    this->list_nodes = NULL;
}

LinkedList::~LinkedList ()
{
    while (!is_empty())
    {
        Node *tmp = this->list_nodes;
        delete_node(tmp->id);
    }
}

void LinkedList::insert_node (Element *key)
{
    // List is empty
    if (!this->list_nodes)
    {
        Node *node = new Node(this->num_nodes,key);
        this->list_nodes = node;
    }
    // List has some values
    else
    {
        // Pass through all the list
        Node *tmp = this->list_nodes;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        Node *node = new Node(this->num_nodes,key);
        tmp->next = node;
    }
    this->num_nodes++;
}

void LinkedList::delete_node (const uint32_t key)
{
    Node *aux1, *aux2;
    aux1 = this->list_nodes;
    aux2 = NULL;

    if (this->num_nodes == 0)
    {
        fprintf(stderr,"[-] ERROR! The list is empty!\n");
        exit(EXIT_FAILURE);
    }

    // Search for the Element by their index
    while (aux1 != NULL && aux1->id != key)
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    // Case 1: First element
    if (aux1 == this->list_nodes)
    {
        //printf("Removing %lf --> Case 1\n",key);
        this->list_nodes = aux1->next;
        aux1->next = NULL;
    }
    // Case 2: Last element
    else if (aux1->next == NULL)
    {
        //printf("Removing %lf --> Case 2\n",key);
        aux2->next = NULL;
    }
    // Case 3: Middle element
    else
    {
        //printf("Removing %lf --> Case 3\n",key);
        aux2->next = aux1->next;
        aux1->next = NULL;
    }
    delete aux1;
    this->num_nodes--;
}

Node* LinkedList::search_node (const uint32_t pid)
{
    Node *tmp = this->list_nodes;
    while (tmp != NULL)
    {
        // Search for the Element by their index 
        if (tmp->value->id == pid)
        {
            //printf("[+] Found the node || %u %lf ||\n",tmp->id,tmp->value);
            return tmp;
        }
            
        tmp = tmp->next;
    }
    //fprintf(stderr,"[-] Key %lf not found!\n",pid);
    return NULL;
}

bool LinkedList::is_empty ()
{
    return (this->list_nodes == NULL) ? true : false;
}

void LinkedList::print ()
{
    if (this->num_nodes == 0)
    {
        printf("[!] The list is empty!\n");
        return;
    }

    Node *tmp = this->list_nodes;
    printf("Number of nodes in list = %u\n",this->num_nodes);
    while (tmp != NULL)
    {
        printf("Node %d -- Value = [%u,%u]\n",tmp->id,tmp->value->id,tmp->value->penalty_counter);
        tmp = tmp->next;
    }
}

void LinkedList::order_list ()
{
    uint32_t cont = 0;
    Node *tmp = this->list_nodes;
    while (tmp != NULL)
    {
        tmp->id = cont;

        cont++;
        tmp = tmp->next;
    }
}

Node::Node (const uint32_t id, Element *key)
{
    this->id = id;
    this->value = key;
    this->next = NULL;
}

Node::~Node ()
{
    delete this->value;
    this->next = NULL;
}

Element::Element (const uint32_t id, const uint32_t penalty_counter)
{
    this->id = id;
    this->penalty_counter = penalty_counter;
}
