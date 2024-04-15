/******************************************************************************
This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.
*******************************************************************************/

#pragma once

#include <network_backend/cxl-sim/backbone/include/cxl-sim/common/Type.h>
#include <network_backend/cxl-sim/backbone/include/cxl-sim/analytical/Topology.h>
#include <vector>
#include "common/CommonNetworkApi.hh"

using namespace AstraSim;
using namespace AstraSimCXL;
using namespace NetworkCXL;
using namespace NetworkCXLCongestionUnaware;

namespace AstraSimCXLCongestionUnaware {

/**
 * CongestionUnawareNetworkApi is a AstraNetworkAPI
 * implemented for congestion_unaware analytical network backend.
 */
class CongestionUnawareNetworkApi final : public CommonNetworkApi {
 public:
  /**
   * Set the topology to be used.
   *
   * @param topology_ptr pointer to the to
   */
  static void set_topology(std::shared_ptr<Topology> topology_ptr) noexcept;

  /**
   * Constructor.
   *
   * @param rank id of the API
   */
  explicit CongestionUnawareNetworkApi(int rank) noexcept;

  /**
   * Implement sim_send of AstraNetworkAPI.
   */
  int sim_send(
      void* buffer,
      uint64_t count,
      int type,
      int dst,
      int tag,
      sim_request* request,
      void (*msg_handler)(void* fun_arg),
      void* fun_arg) override;

 private:
  /// topology
  static std::shared_ptr<Topology> topology;
};

} // namespace AstraSimCXLCongestionUnaware
