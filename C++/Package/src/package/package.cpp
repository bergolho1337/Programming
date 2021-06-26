#include "package.h"

Package::Package ()
{
    this->next_process = 0;
    this->content = new LinkedList();
}

Package::~Package ()
{
    if (this->content)
        delete this->content;
}

void Package::fill ()
{
    uint32_t cur_in_package = this->content->num_nodes;
    uint32_t num_processes_left = this->status.size()-this->status.count();
    uint32_t package_size = (num_processes_left < PACKAGE_SIZE) ? num_processes_left : PACKAGE_SIZE;
    while (cur_in_package < package_size)
    {
        uint32_t cur_process_id = this->next_process;
        if (!this->status[cur_process_id])
        {
            Element *element = new Element(cur_process_id,0);
            this->content->insert_node( element );
            cur_in_package++;
        }
        
        this->next_process = (this->next_process+1) % this->status.size();
    }
}

void Package::process ()
{
    Node *tmp = content->list_nodes;
    std::vector<uint32_t> remove_ids;
    while (tmp != NULL)
    {
        Element *cur_element = tmp->value;

        // Check if the element can be removed from the Package
        double r = (double)rand() / (double)RAND_MAX;
        if ( r < REMOVE_PROBABILITY )
        {
            remove_ids.push_back(tmp->id);
            this->status[cur_element->id] = true;
            printf("SUCESS! Node %u has been inserted! [r = %g]\n",cur_element->id,r);
        }
        else
        {
            cur_element->penalty_counter++;
        }
        // Check if the element surpass the penalty counter limit
        if (cur_element->penalty_counter == PENALTY_LIMIT)
        {
            remove_ids.push_back(tmp->id);
            this->status[cur_element->id] = false;
        }

        tmp = tmp->next;
    }

    for (uint32_t i = 0; i < remove_ids.size(); i++)
    {
        uint32_t cur_id = remove_ids[i];
        printf("Removing id = %u\n",cur_id);
        this->content->delete_node(cur_id);
    }
    printf("In package = %u\n",this->content->num_nodes);
    this->content->order_list();
}

bool Package::is_inside (const uint32_t pid)
{
    return (this->content->search_node(pid)) ? true : false;
}

void Package::print ()
{
    uint32_t cur_in_package = this->content->num_nodes;
    uint32_t num_processes_left = this->status.size()-this->status.count();
    printf("===============================================================\n");
    this->content->print();
    printf("===============================================================\n");
    printf("Current processes in package = %u\n",cur_in_package);
    printf("Number of processes left = %u\n",num_processes_left);
    printf("===============================================================\n");
}