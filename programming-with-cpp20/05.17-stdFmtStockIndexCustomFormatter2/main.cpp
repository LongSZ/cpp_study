// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

// use with LC_ALL=de_DE.UTF-8 ./a.out

#if __has_include(                                             \
  <format>) and not defined(__clang__) && not defined(_MSC_VER)
#  include <format>
#  include <iomanip>
#  include <iostream>
#  include <locale>
#  include <string>
#  include <vector>

using namespace std::literals;

class StockIndex {
  std::string mName{};
  double      mLastPoints{};
  double      mPoints{};

public:
  StockIndex(std::string name)
  : mName{name}
  {}

  const std::string& name() const { return mName; }

  void setPoints(double points)
  {
    mLastPoints = mPoints;
    mPoints     = points;
  }

  double points() const { return mPoints; }

  double pointsDiff() const { return mPoints - mLastPoints; }

  double pointsPercent() const
  {
    if(0.0 == mLastPoints) { return 0.0; }
    return (mPoints - mLastPoints) / mLastPoints * 100.0;
  }
};

std::vector<StockIndex> GetIndices()
{
  StockIndex dax{"DAX"};
  dax.setPoints(13'052.95);
  dax.setPoints(13'108.50);

  StockIndex dow{"Dow"};
  dow.setPoints(29'080.17);
  dow.setPoints(29'290.00);

  StockIndex sp{"S&P 500"};
  sp.setPoints(3'537.01);
  sp.setPoints(3'561.50);

  return {dax, dow, sp};
}

template<>
struct std::formatter<StockIndex> {
  enum class IndexFormat { Normal, Short, WithPlus };
  IndexFormat indexFormat{IndexFormat::Normal};
  // #A New member to track whether the formatting is  localized
  bool localized = false;

  constexpr auto parse(format_parse_context& ctx)
  {
    auto it = ctx.begin();

    // #B Helper to search for a character
    auto isChar = [&](char c) {
      if((it != ctx.end()) && (*it == c)) {
        ++it;
        return true;
      }

      return false;
    };

    // #C Localized formatting
    if(isChar('L')) { localized = true; }

    if(isChar('s')) {
      indexFormat = IndexFormat::Short;
    } else if(isChar('p')) {
      indexFormat = IndexFormat::WithPlus;
    }

    if(it != ctx.end() && *it != '}') {
      throw format_error("invalid format");
    }

    return it;
  }

  auto format(const StockIndex& index, format_context& ctx)
  {
    // #D Add localized
    const auto locFloat{localized ? "L"s : ""s};
    const auto plus{
      (IndexFormat::WithPlus == indexFormat) ? "+"s : ""s};

    if(IndexFormat::Short == indexFormat) {
      const auto fmt =
        std::format("{{:10}} {{:>8.2{}f}}", locFloat);
      return std::format_to(
        ctx.out(), fmt, index.name(), index.points());

    } else {
      const auto fmt{
        std::format("{{:10}} {{:>8.2{0}f}}  {{:>{1}7.2{0}f}}  "
                    "{{:{1}.2{0}f}}%",
                    locFloat,
                    plus)};

      return std::format_to(ctx.out(),
                            fmt,
                            index.name(),
                            index.points(),
                            index.pointsDiff(),
                            index.pointsPercent());
    }
  }
};

void Use()
{
  for(const auto& index : GetIndices()) {
    std::cout << std::format("{:Ls}\n", index);
  }

  for(const auto& index : GetIndices()) {
    std::cout << std::format("{:Lp}\n", index);
  }
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