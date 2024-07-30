#include "taichi/ir/shim.h"

namespace taichi::lang {
    std::unique_ptr<IRBuilder> ir_builder_new() {
        return std::make_unique<IRBuilder>();
    }
    AllocaStmt* ir_builder_create_local_var(IRBuilder* builder, PrimTy ty) {
        DataType d;
        switch(ty) {
            #define PER_TYPE(x) case PrimTy::x:\
                d = PrimitiveType::x;\
                break;
            #include "taichi/inc/data_type.inc.h"
            #undef PER_TYPE
        }
        return builder->create_local_var(d);
    }
}
