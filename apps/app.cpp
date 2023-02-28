#include <fmt/format.h>

#include <iostream>
#include <modern/lib.hpp>
#include <tuple>
#include <vector>

int main() {
  std::vector<double> input = {1.2, 2.3, 3.4, 4.5};

  auto [mean, moment] = accumulate_vector(input);

  fmt::print("Mean: {}, Moment: {}\n", mean, moment);

  return 0;
}
