#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

struct node;
struct edge;

struct edge
{
    uint32_t id;
    double size;
};

struct node
{
    uint32_t id;
    double x, y, z;

    uint32_t num_edges;
    struct edge *list_edges;
};

struct graph
{
    struct node *list_nodes;

    uint32_t total_nodes;
    uint32_t total_edges;

};

struct graph* new_graph ();
void free_graph (struct graph *g);
struct node new_node (uint32_t id, const double pos[]);
struct edge new_edge (uint32_t id, const double size);

void insert_node_graph (struct graph *g, const double pos[]);
void insert_edge_graph (struct graph *g, const uint32_t id_1, const uint32_t id_2);
struct node* search_node (struct graph *g, const uint32_t id);

void print_graph (struct graph *g);
void free_graph (struct graph *g);
void free_list_nodes (struct graph *g);
void free_list_edges (struct node *n);

double calc_norm (const double x1, const double y1, const double z1,\
                  const double x2, const double y2, const double z2);

#endif
