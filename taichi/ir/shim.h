#pragma once
#include "taichi/program/kernel.h"

namespace taichi::lang {
    std::unique_ptr<Kernel> new_kernel(Program &program,
         std::unique_ptr<IRNode> ir,
         const std::string &name = "",
         AutodiffMode autodiff_mode = AutodiffMode::kNone);
}
