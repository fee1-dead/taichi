#pragma once
#include "taichi/program/kernel.h"
#include "taichi/ir/ir_builder.h"

namespace taichi::lang {
    std::unique_ptr<Kernel> new_kernel(Program &program,
         std::unique_ptr<IRNode> ir,
         const std::string &name = "",
         AutodiffMode autodiff_mode = AutodiffMode::kNone);
    namespace chirp {
        std::unique_ptr<IRBuilder::LoopGuard> get_loop_guard(IRBuilder &builder, Stmt *loop);
        GlobalPtrStmt *create_global_ptr(SNode *snode, const std::vector<Stmt *> &indices);
    }
}
