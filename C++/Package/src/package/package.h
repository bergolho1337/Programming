//
// Created by bergolho on 11/02/19.
//

#ifndef PACKAGE_H
#define PACKAGE_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstdint>
#include <vector>
#include <bitset>

#include "linked-list.h"

#define REMOVE_PROBABILITY 0.25
#define PROCESSES_SIZE 10
#define PACKAGE_SIZE 5
#define PENALTY_LIMIT 5

class Package
{
public:
    uint32_t next_process;
    std::bitset<PROCESSES_SIZE> status;
    LinkedList *content;
public:
    Package ();
    ~Package ();
    void fill ();
    void process ();
    void print ();
    bool is_inside (const uint32_t pid);
};


#endif