/// \brief Printing from Input file stream
///
/// Author: Tyler Swann (tyler.swann05@gmail.com)
/// 
/// Version: v0.1.0
///
/// Date: 06-01-2023
///
/// GitHub: https://github.com/oraqlle/mdn-ascii-logo
///
/// License: MIT
///
/// Copyright: Copyright (c) 2023
/// \file mdn-logo-fromfile.main.cxx

#include <fmt/core.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <string>

namespace stdr  = std::ranges;
namespace stdv  = std::views;
namespace fs    = std::filesystem;

using namespace std::literals;

auto main() -> int
{

    auto filename = fs::current_path().string() + "/data/logo.txt"s;
    auto s = std::fstream{ filename, std::ios::in };

    if (!s.is_open())
    {
        fmt::print(stderr, "Failed to open {}!", filename);
        return 0;
    }
    else
    {
        s.unsetf(std::ios::skipws);

        std::copy(std::istream_iterator<char>(s),
                  std::istream_iterator<char>(),
                  std::ostream_iterator<char>(std::cout));
    }

    std::cout << std::endl;

    return 0;
}
