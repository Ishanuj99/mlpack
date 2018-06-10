/**
 * @file average_interpolation.hpp
 * @author Wenhao Huang
 *
 * Definition of AverageInterpolation class.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_CF_AVERAGE_INTERPOLATION_HPP
#define MLPACK_METHODS_CF_AVERAGE_INTERPOLATION_HPP

#include <mlpack/prereqs.hpp>

namespace mlpack {
namespace cf {

/**
 * This class performs average interpolation to generate interpolation weights
 * for neighborhood-based collaborative filtering.
 */
class AverageInterpolation
{
 public:
  // Empty constructor.
  AverageInterpolation() { }

  /**
   * This constructor is needed for interface consistency.
   */
  AverageInterpolation(const arma::sp_mat& /* cleanedData */) { }

  /**
   * Interoplation weights are identical and sum up to one.
   *
   * @param weights Resulting interpolation weights.
   * @param w Matrix W from decomposition.
   * @param h Matrix H from decomposition.
   * @param queryUser Queried user.
   * @param neighbors Neighbors of queried user.
   * @param similarities Similarites between query user and neighbors.
   * @param cleanedData Sparse rating matrix.
   */
  void GetWeights(arma::vec& weights,
                  const arma::mat& /* w */,
                  const arma::mat& /* h */,
                  const size_t /* queryUser */,
                  const arma::Col<size_t>& neighbors,
                  const arma::vec& /* similarities */,
                  const arma::sp_mat& /* cleanedData */)
  {
    if (neighbors.n_elem == 0)
    {
      Log::Fatal << "Require: neighbors.n_elem > 0. There should be at "
          << "least one neighbor!" << std::endl;
    }

    weights.set_size(neighbors.n_elem);
    weights.fill(1.0 / neighbors.n_elem);
  }
};

} // namespace cf
} // namespace mlpack

#endif
