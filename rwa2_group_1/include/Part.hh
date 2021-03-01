
#ifndef PART_HH
#define PART_HH

#include <iostream>
#include <geometry_msgs/PoseStamped.h>

namespace rwa2 {

    class Part {
    public:
        explicit Part(std::string type,std::string color, int sensor,
         geometry_msgs::PoseStamped pose_world): type_{type}, color_{color}, sensor_{sensor}, 
         pose_world_{pose_world}{}

        void Print_Info();

        std::string const get_type_() { return type_;}

    private:

        std::string type_;
        std::string color_;
        int sensor_;
        geometry_msgs::PoseStamped pose_world_;
       
    };
}
#endif //RWA2_PART_INFO_HH