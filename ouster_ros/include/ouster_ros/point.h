/**
 * @file
 * @brief PCL point datatype for use with ouster sensors
 */

#pragma once

#define PCL_NO_PRECOMPILE

#include <pcl/point_types.h>
#include <pcl/impl/point_types.hpp>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/impl/voxel_grid.hpp>
#include <pcl/filters/impl/extract_indices.hpp>
#include <pcl/filters/impl/conditional_removal.hpp>
#include <pcl/pcl_base.h>
#include <pcl/impl/pcl_base.hpp>
#include <pcl/PointIndices.h>
#include <pcl/cloud_iterator.h>
#include <pcl/impl/cloud_iterator.hpp>


#include <pcl/sample_consensus/ransac.h>

#include <pcl/sample_consensus/sac_model_plane.h>

#include <pcl/sample_consensus/impl/sac_model_plane.hpp>
#include <pcl/sample_consensus/impl/ransac.hpp>

#include <Eigen/Dense>
#include <chrono>
#include <functional>

#include "ouster/lidar_scan.h"

namespace ouster_ros {

struct EIGEN_ALIGN16 Point {
    PCL_ADD_POINT4D;
    float intensity;
    uint32_t t;
    uint16_t reflectivity;
    uint8_t ring;
    uint16_t ambient;
    uint32_t range;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
}  // namespace ouster_ros

// clang-format off
POINT_CLOUD_REGISTER_POINT_STRUCT(ouster_ros::Point,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, intensity, intensity)
    // use std::uint32_t to avoid conflicting with pcl::uint32_t
    (std::uint32_t, t, t)
    (std::uint16_t, reflectivity, reflectivity)
    (std::uint8_t, ring, ring)
    (std::uint16_t, ambient, ambient)
    (std::uint32_t, range, range)
)
// clang-format on
