#include <field_engine.h>

FieldEngine *engine;

void loop() {

}

int main() {
    engine = create_engine(900, 500, loop);
    enter_engine_loop(engine);
    delete_engine(engine);
}
