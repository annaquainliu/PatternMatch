#include <iostream>
#include "compiler.h"

using namespace std;

int main() {
    Compiler *c = new Compiler();
    c->run();
    return 0;
}