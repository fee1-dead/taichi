#include "taichi/ir/shim.h"
#include "taichi/ir/ir_builder.h"
#include "taichi/ir/statements.h"

namespace taichi::lang {
    std::unique_ptr<Kernel> new_kernel(Program &program,
         std::unique_ptr<IRNode> &&ir,
         const std::string &name = "",
         AutodiffMode autodiff_mode = AutodiffMode::kNone)
    {
        return std::make_unique<Kernel>(program, std::move(ir), name, autodiff_mode);
    }

    namespace chirp
    {
        std::unique_ptr<IRBuilder::LoopGuard> get_loop_guard(IRBuilder &builder, Stmt *loop) {
            return std::make_unique<IRBuilder::LoopGuard>(builder, loop);
        }

        //TODO!
        GlobalPtrStmt *create_global_ptr(IRBuilder &builder, SNode *snode, const std::vector<Stmt *> &indices) {
            return builder.insert(Stmt::make_typed<GlobalPtrStmt>(snode, indices));
        }
    } // namespace chirp
    
}
