#include <algorithm>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <modern/lib.hpp>
#include <tuple>
#include <vector>

namespace ba = boost::accumulators;

std::tuple<double, double> accumulate_vector(const std::vector<double> &values) {
  ba::accumulator_set<double, ba::stats<ba::tag::mean, ba::tag::moment<2>>> acc;

  std::for_each(std::begin(values), std::end(values), std::ref(acc));

  return {ba::mean(acc), ba::moment<2>(acc)};
}
