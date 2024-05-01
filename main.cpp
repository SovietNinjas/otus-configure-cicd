#include <iostream>

#include "async.h"
#include "cmd_mgr.h"
#include "writer_thread.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    unsigned int bulk = 5;

    async::handle_t h1 = async::connect(bulk);
    async::handle_t h2 = async::connect(bulk);

    async::receive(h1, "1", 1);
    async::receive(h2, "1\n", 2);
    async::receive(h1, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    async::receive(h1, "b\nc\nd\n}\n89\n", 11);

    async::disconnect(h1);
    async::disconnect(h2);

    return 0;
}
