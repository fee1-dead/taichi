#include "taichi/ir/shim.h"

namespace taichi::lang {
    std::unique_ptr<IRBuilder> ir_builder_new() {
        return std::make_unique<IRBuilder>();
    }
}
