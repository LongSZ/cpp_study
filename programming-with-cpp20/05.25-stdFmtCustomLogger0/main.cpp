// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#if __has_include(<format>) and not defined(__clang__)
#  include <array>
#  include <format>
#  include <iostream>
#  include <string_view>

enum LogLevel { Info, Warning, Error };

template<>
struct std::formatter<LogLevel> : std::formatter<const char*> {
  inline static const char* LEVEL_NAMES[] = {"Info",
                                             "Warning",
                                             "Error"};

  auto format(LogLevel c, format_context& ctx)
  {
    return std::formatter<const char*>::format(LEVEL_NAMES[c],
                                               ctx);
  }
};

void log(LogLevel         level,
         std::string_view fmt,
         const auto&... args)
{
  std::clog << std::format("{}: ", level)
            << std::format(fmt, args...) << '\n';
}

void Use()
{
  int         x{4};
  std::string share{"Amazon"};
  double      d{3'117.02};

  log(LogLevel::Info, "Share price {} very high: {}", share, d);

  errno = 4;
  log(LogLevel::Error, "Unknown stock, errno {}", errno);
}

int main()
{
  Use();
}

#else
int main()
{
#  pragma message("not supported")
}
#endif