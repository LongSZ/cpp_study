// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#if not defined(_MSC_VER)
#  include <iostream>
#  include <string>
#  include <type_traits>
#  include <utility>

using namespace std::literals::string_literals;

template<typename First, typename... Rest>
void print(First&& first, Rest&&... args)
{
  std::cout << "[" << first << "]";

  auto coutSpaceAndArg = [](const auto& arg) {
    std::cout << ' ' << arg;
  };

  (..., coutSpaceAndArg(args));

  std::cout << '\n';
}

template<typename... Origins>
auto getNamedLogger(Origins&&... origins)
{
  return [... _origins = std::forward<Origins>(
            origins)]<typename... Ts>(Ts && ... args)
    // #A Trailing requires with disjunction and is_pointer  to
    // limit  Origins to no pointers
    requires(
      not std::disjunction_v<std::is_pointer<Origins>...>)
  {
    print(_origins..., std::forward<Ts>(args)...);
  };
}

int main()
{
  auto steeringLogger = getNamedLogger("Steering"s);
  auto brakeLogger =
    getNamedLogger("Brake"s, "Left"s, "Front"s);

  steeringLogger("angle"s, 90);
}
#else
#  pragma message("not supported")
int main() {}
#endif