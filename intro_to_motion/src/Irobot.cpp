#include "Irobot.h"

/**
	Constructor for Irobot class

	@param	rosNode	ros::NodeHandle
	@return			void
*/
Irobot::Irobot(ros::NodeHandle rosNode)
{
	this->node = rosNode;
	this->velocityPublisher = this->node.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);

}

void Irobot::setLinearX(float x)
{
	command.linear.x = x;
}

void Irobot::setAngularZ(float z)
{
	command.angular.z = z;
}

/**
	Function for publishing velocity

	@return		void
*/
void Irobot::sendCommand()
{	
	velocityCommand.linear.x = command.linear.x;
	velocityCommand.angular.z = command.angular.z;
	
	velocityPublisher.publish(velocityCommand);

}
