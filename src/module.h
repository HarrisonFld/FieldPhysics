#pragma once

/*
* Module(s)
*/
typedef struct Module {
    char *name; //all internal modules should start with FE_
    void (*loopFunction)(struct Module* module);
} Module;
