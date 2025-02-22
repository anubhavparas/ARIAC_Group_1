# ARIAC 2020 Group 1
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

Agile Robotics for Industrial Automation (ARIAC) is a simulation based competition organized by the National Institute of Standards and Tech-nology (NIST) in Collaboration with IEEE CASE, every year since 2017.  The purpose of ARIAC isto advance robot agility by utilizing the latest advances in artificial intelligence and robot planning.Specifically, ARIAC focuses on challenging robotic agility in the manufacturing environments and makethem autonomous, efficient and require lesser human input.  The ARIAC competition uses ROS andGazebo simulator.

## Team Members

- Sandeep Kota Sai Pavan - [LinkedIn Link](https://www.linkedin.com/in/skotasai/)
- Rodrigo Perez-Vicente - [LinkedIn Link](https://www.linkedin.com/in/rodrigodelazcano/)
- Anubhav Paras - [LinkedIn Link](https://www.linkedin.com/in/anubhavparas/)
- Vasista Ayyagari - [LinkedIn Link](https://www.linkedin.com/in/vasista-ayyagari-b559b8144/)

## Goal of ARIAC 2020 Challenge
The goal of ARIAC 2020 is to build kits based on the received orders by picking up parts from theenvironment.  We are given a shop floor setup with a gantry robot fixed with two UR10 arms withvacuum grippers.  The parts are placed in shelves and bins.  The robot picks up the parts and placesthem on an AGV. Once a kit is completed, the AGV is shipped.  Some agility challenges include highpriority order, faulty parts, faulty gripper, flipped parts, sensor blackout and moving obstacles.  Someof the technologies used for this competition include C++, ROS, Gazebo, MoveIt and ROS TF.

## Ariac Environment

The environment consists of a gantry robot, 2 AGV’s on either side of the shop floor, multiple shelvesand bins, a conveyor belt and moving obstacles.  The parts are located within the bins and shelves.However, some parts also come from the conveyor belt but they are in continuous motion and disappearwhen they reach the end of the belt.  The shelves are arranged in a way to create four aisles.  Thereare two moving obstacles that can be found from any of the aisles.

 ![alt text](./rwa5_group_1/docs/readme_images/IntroARIAC.png?raw=true "ARIAC Environment")

## Knowledge Representation
There are different kinds of knowledge representations based on the information we have ranging fromordinary glossariestogeneral logic.  Following is the knowledge model of the objects and behaviorsimplemented in our project.  For each object in the project, appropriate attributes and behaviors areidentified.

 ![alt text](./rwa5_group_1/docs/readme_images/knowledge_representation.PNG?raw=true "Knowledge Representation")

## Agility Challenges

ARIAC 2020 has the following agility challenges
1)  <b> Faulty Products :</b> Certain parts in the shop floor are faulty but can only be identified one on the AGV.
2) <b> Flipped products :</b> Certain parts need to be flipped before placing them on the AGV.
3) <b> Dropped Products :</b>  The gripper becomes faulty at various instances. This leads to either incorrect pose on the AGV or  may not be placed on the AGV at all.
4) <b> In-process order interruption :</b> In the middle of an order, another other is placed which need to  be delivered prior the the initial order. (The new order have a higher priority).
5) <b> Sensor Blackout :</b> At a certain time, communications from the sensors will be lost, but the system needs to continue to process the orders.
6) <b> Moving Obstacles :</b> Moving Obstacles (humans) are present in the shop floor and the robot should plan to avoid collision.


## Build Instructions
Follow the build instructions to build on your local system. 
- Download the ARIAC 2020 package from the ARIAC github repo in the source folder of your workspace.
```
mkdir -p ~/ariac_ws/src
cd ~/ariac_ws/src/
git clone https://github.com/usnistgov/ARIAC.git
cd ~/ariac_ws/src/ARIAC/
git checkout ariac2020
cd ~/ariac_ws/src/
git clone https://github.com/osrf/ariac-gazebo_ros_pkgs -b ariac-network-melodic
```

- Download this repo in the source directory
Run the following commands in a terminal

```
cd ~/ariac_ws/src/

git clone https://github.com/sandeep-kota/ARIAC_Group_1.git

catkin build
```

---
## Run Instructions
 - The launch directory of the package `/rwa5_group_1` has a launch file `rwa5.launch`. All the necessary nodes will be launched within this node.

 ```
source ~/ariac_ws/devel/setup.bash

roslaunch rwa5_group_1 rwa5.launch load_moveit:=true
 ```

 - Run the rwa5 node 
 ```
source ~/ariac_ws/devel/setup.bash

rosrun rwa5_group_1 rwa5_node
 ``` 


---
 ## Output Video

An sample output video for the config file : [final_ariac_2021.yaml](./rwa5_group_1/config/final_ariac_2021.yaml) is shown below.

 [![alt text](./rwa5_group_1/docs/output_score/video_thumbnail.PNG?raw=true "Final Output Video")](https://www.youtube.com/watch?v=VHgZroqvAyw&ab_channel=RodrigoPerez)

An sample output video for the config file : [rwa5-sample.yaml](./rwa5_group_1/config/rwa5-sample.yaml) is shown below.

 [![alt text](./rwa5_group_1/docs/output_score/video_thumbnail.PNG?raw=true "Final Output Video")](https://www.youtube.com/watch?v=ij6FFzRd-K4&ab_channel=RodrigoPerez)

## Final Score
Final score for the [final_ariac_2021.yaml](./rwa5_group_1/config/final_ariac_2021.yaml) config file is shown below.

 ![alt text](./rwa5_group_1/docs/output_score/final_score1.png?raw=true "Final Score")

  ![alt text](./rwa5_group_1/docs/output_score/final_score2.png?raw=true "Final Score")

   ![alt text](./rwa5_group_1/docs/output_score/final_score3.png?raw=true "Final Score")




