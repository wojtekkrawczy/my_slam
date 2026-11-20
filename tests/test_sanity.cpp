#include <gtest/gtest.h>
#include <Eigen/Core>
#include <sophus/se3.hpp>

TEST(SanityCheck, EigenAndSophusLinkCorrectly) {
    const Eigen::Vector3d t(1.0, 2.0, 3.0);
    const Sophus::SE3d pose(Sophus::SO3d(), t);
    EXPECT_DOUBLE_EQ(pose.translation().x(), 1.0);
    EXPECT_DOUBLE_EQ(pose.translation().y(), 2.0);
    EXPECT_DOUBLE_EQ(pose.translation().z(), 3.0);
}