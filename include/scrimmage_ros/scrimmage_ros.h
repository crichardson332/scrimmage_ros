#ifndef SCRIMMAGE_ROS_SCRIMMAGE_ROS_H_
#define SCRIMMAGE_ROS_SCRIMMAGE_ROS_H_

#include <scrimmage/entity/External.h>

#include "ros/ros.h"

#include <iostream>

namespace scrimmage_ros {
class scrimmage_ros {
public:
    scrimmage_ros(ros::NodeHandle &nh, ros::NodeHandle &private_nh,
                  const std::string &node_name);
    bool init(std::ostream &out = std::cout);
    const double & loop_rate_hz();
    bool step(const double &t, std::ostream &out = std::cout);
    static std::string exec_command(const char* cmd);
protected:
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    std::string node_name_;

    scrimmage::External external_;
    std::string ros_log_dir_ = "";
    int entity_id_ = 1;
    double loop_rate_hz_ = 1.0;
private:
};
} // namespace scrimmage_ros
#endif // SCRIMMAGE_ROS_SCRIMMAGE_ROS_H_
