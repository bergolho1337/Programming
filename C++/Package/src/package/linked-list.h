//
// Created by bergolho on 11/02/19.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>

class Element
{
public:
    uint32_t id;
    uint32_t penalty_counter;
public:
    Element (const uint32_t id, const uint32_t penalty_counter);
};

class Node
{
public:
    uint32_t id;
    Element *value;           
    Node *next;
public:
    Node (const uint32_t id, Element *key);
    ~Node ();
};

class LinkedList
{
public:
    uint32_t num_nodes;
    Node *list_nodes;
public:
    LinkedList ();
    ~LinkedList ();
    void insert_node (Element *key);
    void delete_node (const uint32_t key);
    Node* search_node (const uint32_t pid);
    bool is_empty ();
    void order_list ();
    void print ();

};

#endif