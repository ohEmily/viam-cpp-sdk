#pragma once

#include <viam/api/common/v1/common.pb.h>
#include <viam/api/component/base/v1/base.grpc.pb.h>
#include <viam/api/component/base/v1/base.pb.h>

#include <viam/sdk/common/linear_algebra.hpp>
#include <viam/sdk/common/proto_type.hpp>
#include <viam/sdk/components/base/base.hpp>
#include <viam/sdk/components/base/client.hpp>
#include <viam/sdk/components/base/server.hpp>
#include <viam/sdk/spatialmath/geometry.hpp>

namespace viam {
namespace sdktests {
namespace base {

sdk::Base::properties fake_properties();
class MockBase : public sdk::Base {
   public:
    void move_straight(int64_t distance_mm,
                       double mm_per_sec,
                       const sdk::AttributeMap& extra) override;
    void spin(double angle_deg, double degs_per_sec, const sdk::AttributeMap& extra) override;
    properties get_properties(const sdk::AttributeMap& extra) override;
    std::vector<sdk::GeometryConfig> get_geometries(const sdk::AttributeMap& extra) override;
    void set_power(const sdk::Vector3& linear,
                   const sdk::Vector3& angular,
                   const sdk::AttributeMap& extra) override;
    void set_velocity(const sdk::Vector3& linear,
                      const sdk::Vector3& angular,
                      const sdk::AttributeMap& extra) override;
    grpc::StatusCode stop(const sdk::AttributeMap& extra) override;
    bool is_moving() override;
    sdk::AttributeMap do_command(const sdk::AttributeMap& command) override;
    static std::shared_ptr<MockBase> get_mock_base();

    // These variables allow the testing infra to `peek` into the mock
    // and ensure that the correct values were passed
    int64_t peek_move_straight_distance_mm;
    double peek_move_straight_mm_per_sec;
    double peek_spin_angle_deg, peek_spin_degs_per_sec;
    sdk::Vector3 peek_set_power_linear, peek_set_power_angular;
    sdk::Vector3 peek_set_velocity_linear, peek_set_velocity_angular;
    bool peek_stop_called;
    sdk::AttributeMap peek_do_command_command;

    MockBase(std::string name) : Base(std::move(name)){};
};

}  // namespace base
}  // namespace sdktests
}  // namespace viam
