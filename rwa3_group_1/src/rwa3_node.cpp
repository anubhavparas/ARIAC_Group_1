// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <algorithm>
#include <vector>

#include <ros/ros.h>

#include <nist_gear/LogicalCameraImage.h>
#include <nist_gear/Order.h>
#include <nist_gear/Proximity.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Range.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <std_srvs/Trigger.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h> //--needed for tf2::Matrix3x3

#include "competition.h"
#include "utils.h"
#include "gantry_control.h"
#include "agv_control.h"
#include "sensor_control.h"

#include <tf2/LinearMath/Quaternion.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rwa3_node");
    ros::NodeHandle node;
    ros::AsyncSpinner spinner(8);
    spinner.start();

    std::vector<Product> list_of_products;
    std::vector<Shipment> list_of_shipments;
    Product current_product;

    Competition comp(node);
    comp.init();

    std::string c_state = comp.getCompetitionState();
    comp.getClock();

    GantryControl gantry(node);
    gantry.init();

    SensorControl sensors(node);
    sensors.init();

    ros::Duration(2).sleep();

    gantry.goToPresetLocation(gantry.start_);

    //--1-Read order
    while(comp.processOrder())
    // while (1)
    {
        list_of_shipments = comp.get_shipment_list();
        list_of_products = comp.get_product_list();

        for (int p = 0; p < list_of_products.size(); p++)
        {
            current_product = list_of_products.at(p);

            ROS_WARN_STREAM(current_product.type);

            //--2-Look for parts in this order
            current_product.p = sensors.findPart(current_product.type);

            if (gantry.checkFreeGripper().compare("none") == 0)
            {
                if (gantry.getGantryLocation().compare("aisle_1") == 0)
                {
                    gantry.goToPresetLocation(gantry.aisle1_);
                }
                else if (gantry.getGantryLocation().compare("aisle_2") == 0)
                {
                    gantry.goToPresetLocation(gantry.aisle2_);
                }

                gantry.goToPresetLocation(gantry.start_);

                //First place product of left arm in agv

                gantry.placePartLeftArm();

                // ros::Duration(2).sleep();

                gantry.placePartRightArm();
            }
            gantry.getProduct(current_product);
        }
    }

    spinner.stop();
    ros::shutdown();
    return 0;
}
