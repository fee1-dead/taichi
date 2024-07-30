#include "taichi/ir/ir_builder.h"

namespace taichi::lang {
    std::unique_ptr<IRBuilder> ir_builder_new();
    enum class PrimTy: uint16_t {
        #define PER_TYPE(x) x,
        #include "taichi/inc/data_type.inc.h"
        #undef PER_TYPE
    };
    AllocaStmt* ir_builder_create_local_var(IRBuilder* builder, PrimTy ty);
}

