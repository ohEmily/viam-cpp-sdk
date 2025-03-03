#define BOOST_TEST_MODULE test module test_camera

#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <vector>

#include <boost/test/included/unit_test.hpp>

#include <viam/api/common/v1/common.pb.h>
#include <viam/api/component/camera/v1/camera.grpc.pb.h>
#include <viam/api/component/camera/v1/camera.pb.h>

#include <viam/sdk/common/proto_type.hpp>
#include <viam/sdk/components/camera/camera.hpp>
#include <viam/sdk/components/camera/client.hpp>
#include <viam/sdk/components/camera/server.hpp>
#include <viam/sdk/spatialmath/geometry.hpp>
#include <viam/sdk/tests/mocks/camera_mocks.hpp>
#include <viam/sdk/tests/test_utils.hpp>

namespace viam {
namespace sdktests {

using namespace camera;

using namespace viam::sdk;

BOOST_AUTO_TEST_SUITE(test_camera)

std::shared_ptr<MockCamera> camera = MockCamera::get_mock_camera();

BOOST_AUTO_TEST_CASE(test_get_image) {
    Camera::raw_image expected_image = fake_raw_image();
    Camera::raw_image image = camera->get_image("JPEG", {});

    BOOST_CHECK(expected_image == image);
}

BOOST_AUTO_TEST_CASE(test_get_images) {
    Camera::image_collection expected_images = fake_raw_images();
    Camera::image_collection images = camera->get_images();

    BOOST_CHECK(expected_images == images);
}

BOOST_AUTO_TEST_CASE(test_get_point_cloud) {
    Camera::point_cloud expected_pc = fake_point_cloud();
    Camera::point_cloud pc = camera->get_point_cloud("pointcloud/pcd", {});

    BOOST_CHECK(expected_pc == pc);
}

BOOST_AUTO_TEST_CASE(test_get_properties) {
    Camera::properties expected_props = fake_properties();
    Camera::properties properties = camera->get_properties();

    BOOST_CHECK(expected_props == properties);
}

BOOST_AUTO_TEST_CASE(test_do) {
    AttributeMap expected = fake_map();

    AttributeMap command;
    AttributeMap result_map = camera->do_command(command);

    ProtoType expected_pt = *(expected->at(std::string("test")));
    ProtoType result_pt = *(result_map->at(std::string("test")));

    BOOST_CHECK(result_pt == expected_pt);
}

BOOST_AUTO_TEST_CASE(test_get_geometries) {
    std::vector<GeometryConfig> expected_geometries = fake_geometries();
    std::vector<GeometryConfig> result_geometries = camera->get_geometries({});

    BOOST_CHECK(result_geometries == expected_geometries);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_camera_service)
std::shared_ptr<CameraServer> get_camera_server() {
    auto server = std::make_shared<CameraServer>();
    server->resource_manager()->add(std::string("mock_camera"), MockCamera::get_mock_camera());
    return server;
}

BOOST_AUTO_TEST_CASE(test_get_image_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::component::camera::v1::GetImageRequest req;
    viam::component::camera::v1::GetImageResponse resp;

    *req.mutable_name() = "mock_camera";
    *req.mutable_mime_type() = "JPEG";

    grpc::Status status = server->GetImage(&ctx, &req, &resp);
    BOOST_CHECK(status.error_code() == 0);

    Camera::raw_image image = fake_raw_image();

    std::vector<unsigned char> bytes = string_to_bytes(resp.image());

    BOOST_CHECK(image.bytes == bytes);
}

BOOST_AUTO_TEST_CASE(test_get_images_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::component::camera::v1::GetImagesRequest req;
    viam::component::camera::v1::GetImagesResponse resp;

    *req.mutable_name() = "mock_camera";

    grpc::Status status = server->GetImages(&ctx, &req, &resp);
    BOOST_CHECK(status.error_code() == 0);

    Camera::image_collection images = fake_raw_images();

    BOOST_CHECK(resp.images().size() == images.images.size());
    BOOST_CHECK(resp.images()[0].source_name() == images.images[0].source_name);
    BOOST_CHECK(resp.images()[1].source_name() == images.images[1].source_name);

    auto converted_proto_timestamp = time_pt_to_timestamp(images.metadata.captured_at);
    BOOST_CHECK(resp.response_metadata().captured_at().seconds() ==
                converted_proto_timestamp.seconds());
    BOOST_CHECK(resp.response_metadata().captured_at().nanos() ==
                converted_proto_timestamp.nanos());

    auto tp_from_proto = timestamp_to_time_pt(resp.response_metadata().captured_at());
    BOOST_CHECK(tp_from_proto == images.metadata.captured_at);

    std::vector<unsigned char> bytes0 = string_to_bytes(resp.images()[0].image());
    BOOST_CHECK(bytes0 == images.images[0].bytes);
    std::vector<unsigned char> bytes1 = string_to_bytes(resp.images()[1].image());
    BOOST_CHECK(bytes1 == images.images[1].bytes);
}

BOOST_AUTO_TEST_CASE(test_get_point_cloud_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::component::camera::v1::GetPointCloudRequest req;
    viam::component::camera::v1::GetPointCloudResponse resp;

    *req.mutable_name() = "mock_camera";
    *req.mutable_mime_type() = "pointcloud/pcd";

    grpc::Status status = server->GetPointCloud(&ctx, &req, &resp);
    BOOST_CHECK(status.error_code() == 0);

    Camera::point_cloud expected_pc = fake_point_cloud();

    std::vector<unsigned char> bytes = string_to_bytes(resp.point_cloud());

    BOOST_CHECK(expected_pc.pc == bytes);
}

BOOST_AUTO_TEST_CASE(test_render_frame_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::component::camera::v1::RenderFrameRequest req;
    ::google::api::HttpBody resp;

    Camera::raw_image image = fake_raw_image();

    *req.mutable_name() = "mock_camera";
    *req.mutable_mime_type() = "JPEG";
    grpc::Status status = server->RenderFrame(&ctx, &req, &resp);

    BOOST_CHECK(status.error_code() == 0);

    std::vector<unsigned char> bytes = string_to_bytes(resp.data());

    BOOST_CHECK(resp.content_type() == image.mime_type);
    BOOST_CHECK(image.bytes == bytes);
}

BOOST_AUTO_TEST_CASE(test_get_properties_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::component::camera::v1::GetPropertiesRequest req;
    viam::component::camera::v1::GetPropertiesResponse resp;
    *req.mutable_name() = "mock_camera";
    grpc::Status status = server->GetProperties(&ctx, &req, &resp);

    BOOST_CHECK(status.error_code() == 0);

    Camera::properties expected = fake_properties();

    BOOST_CHECK(expected.supports_pcd == resp.supports_pcd());
    BOOST_CHECK(expected.intrinsic_parameters == Camera::from_proto(resp.intrinsic_parameters()));
    BOOST_CHECK(expected.distortion_parameters == Camera::from_proto(resp.distortion_parameters()));
}

BOOST_AUTO_TEST_CASE(test_get_geometries_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::common::v1::GetGeometriesRequest req;
    viam::common::v1::GetGeometriesResponse resp;
    *req.mutable_name() = "mock_camera";
    grpc::Status status = server->GetGeometries(&ctx, &req, &resp);

    BOOST_CHECK(status.error_code() == 0);

    std::vector<GeometryConfig> expected_geometries = fake_geometries();
    std::vector<GeometryConfig> response_geometries = GeometryConfig::from_proto(resp);

    BOOST_CHECK(response_geometries == expected_geometries);
}

BOOST_AUTO_TEST_CASE(test_do_service) {
    auto server = get_camera_server();
    grpc::ServerContext ctx;
    viam::common::v1::DoCommandRequest req;
    viam::common::v1::DoCommandResponse resp;

    *req.mutable_name() = "mock_camera";
    grpc::Status status = server->DoCommand(&ctx, &req, &resp);

    AttributeMap result_map = struct_to_map(resp.result());
    AttributeMap expected_map = fake_map();

    std::shared_ptr<ProtoType> expected_pt = expected_map->at(std::string("test"));
    std::shared_ptr<ProtoType> result_pt = result_map->at(std::string("test"));

    BOOST_CHECK(*expected_pt == *result_pt);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_camera_client)

MockCameraClient client("mock_camera");

BOOST_AUTO_TEST_CASE(test_image_client) {
    Camera::raw_image image = client.get_image("JPEG");
    Camera::raw_image expected_image = fake_raw_image();

    BOOST_CHECK(expected_image == image);
}

BOOST_AUTO_TEST_CASE(test_get_point_cloud_client) {
    Camera::point_cloud pc = client.get_point_cloud("pointcloud/pcd");
    Camera::point_cloud expected = fake_point_cloud();

    BOOST_CHECK(expected == pc);
}

BOOST_AUTO_TEST_CASE(test_get_properties_client) {
    Camera::properties props = client.get_properties();
    Camera::properties expected = fake_properties();

    BOOST_CHECK(expected == props);
}

BOOST_AUTO_TEST_CASE(test_get_geometries_client) {
    std::vector<GeometryConfig> result_geometries = client.get_geometries();
    std::vector<GeometryConfig> expected_geometries = fake_geometries();

    BOOST_CHECK(result_geometries == expected_geometries);
}

BOOST_AUTO_TEST_CASE(test_do_client) {
    AttributeMap command = fake_map();
    AttributeMap expected_map = fake_map();
    AttributeMap result_map = client.do_command(command);

    ProtoType expected_pt = *(expected_map->at(std::string("test")));
    ProtoType result_pt = *(result_map->at(std::string("test")));

    BOOST_CHECK(expected_pt == result_pt);
}
BOOST_AUTO_TEST_SUITE_END()

}  // namespace sdktests
}  // namespace viam
