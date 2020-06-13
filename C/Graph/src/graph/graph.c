#include "graph.h"

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

struct graph* new_graph ()
{
    struct graph *result = (struct graph*)malloc(sizeof(struct graph));

    result->list_nodes = NULL;
    result->total_edges = 0;
    result->total_nodes = 0;

    return result;
}

void free_graph (struct graph *g)
{
    for (uint32_t i = 0; i < g->total_nodes; i++)
        arrfree(g->list_nodes[i].list_edges);
    arrfree(g->list_nodes);
    
    free(g);
}

struct node new_node (uint32_t id, const double pos[])
{
    struct node result;
    result.id = id;
    result.x = pos[0];
    result.y = pos[1];
    result.z = pos[2];
    result.num_edges = 0;
    result.list_edges = NULL;

    return result; 
}

struct edge new_edge (uint32_t id, const double size)
{
    struct edge result;
    result.id = id;
    result.size = size;

    return result;
}

void insert_node_graph (struct graph *g, const double pos[])
{
    struct node value = new_node(g->total_nodes,pos);

    arrput(g->list_nodes,value);

    g->total_nodes++;
}

void insert_edge_graph (struct graph *g, const uint32_t id_1, const uint32_t id_2)
{
    double size = calc_norm(g->list_nodes[id_1].x,g->list_nodes[id_1].y,g->list_nodes[id_1].z,\
                            g->list_nodes[id_2].x,g->list_nodes[id_2].y,g->list_nodes[id_2].z);
    struct edge value = new_edge(id_2,size);

    arrput(g->list_nodes[id_1].list_edges,value);

    g->list_nodes[id_1].num_edges++;

    g->total_edges++;
}

void print_graph (struct graph *g)
{
    for (uint32_t i = 0; i < g->total_nodes; i++)
    {
        printf("|  %u  // (%g,%g,%g) | --> ",i,g->list_nodes[i].x,g->list_nodes[i].y,g->list_nodes[i].z);
        for (uint32_t j = 0; j < g->list_nodes[i].num_edges; j++)
        {
            printf("| %u | --> ",g->list_nodes[i].list_edges[j].id);
        }
        printf("\n");
    }
}

double calc_norm (const double x1, const double y1, const double z1,\
                  const double x2, const double y2, const double z2)
{
    return sqrt( pow(x1-x2,2) + pow(y1-y2,2) + pow(z1-z2,2) );
}