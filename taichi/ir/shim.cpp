#include "taichi/ir/shim.h"

namespace taichi::lang {
    std::unique_ptr<Kernel> new_kernel(Program &program,
         std::unique_ptr<IRNode> &&ir,
         const std::string &name = "",
         AutodiffMode autodiff_mode = AutodiffMode::kNone)
    {
        return std::make_unique<Kernel>(program, std::move(ir), name, autodiff_mode);
    }
}
