#pragma once

/*
* Module(s)
*/
typedef struct Module {
    char *name;
    void (*loopFunction)(struct Module* module);
} Module;
