#include <iostream>
#include <stdio.h>
#include <string.h>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "Irobot.cpp"

int main(int argc, char **argv)
{
	// Start Node
	ROS_INFO("Starting irobot_node");

	ros::init(argc, argv, "irobot");
	ros::NodeHandle node;
	geometry_msgs::Twist cmd_vel;
	int counter = 1;

	Irobot robot = Irobot(node);

	ROS_INFO("Press Ctrl-C to kill node.");

	// Spin
	ros::Rate loopRate(10); // 10 hz

	while(ros::ok())
	{
		if(counter == 1)
		{
			robot.setLinearX(1.0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(1.0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(1.0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(1.0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			robot.setLinearX(0);
			robot.setAngularZ(1.0);
			robot.sendCommand();
			usleep(1000000);
			counter++;
		}
		ros::spinOnce();
		loopRate.sleep();
	}

	ros::shutdown();

	return 0;
}
