#pragma once

/*
* Module(s)
*/
typedef struct Module {
    void (*loopFunction)(struct Module* module);
} Module;
