#include <stdio.h>
#include "graph/graph.h"

int main ()
{
    struct graph *g = new_graph();

    double pos1[3] = {0,0,0};
    double pos2[3] = {1,1,1};
    double pos3[3] = {2,2,2};
    double pos4[3] = {3,3,3};

    insert_node_graph(g,pos1);
    insert_node_graph(g,pos2);
    insert_node_graph(g,pos3);
    insert_node_graph(g,pos4);

    insert_edge_graph(g,0,1);
    insert_edge_graph(g,1,2);
    insert_edge_graph(g,1,3);

    print_graph(g);

    free_graph(g);

    return 0;
}