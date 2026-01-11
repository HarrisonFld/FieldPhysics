#include "m_physics.h"
#include "module.h"
#include <stdlib.h>

static void internalLoop() {

}

Module* m_physics() {
    Module *phyiscsModule = malloc(sizeof(Module));
    phyiscsModule->name = "FE_PHYSICS"; //all internal modules should start with FE_
    phyiscsModule->loopFunction = internalLoop;
    return phyiscsModule;
}