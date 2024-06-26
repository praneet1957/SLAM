#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "rotate_z");
	ros::NodeHandle rotate_z_node;

	ros::Publisher cmd_pub = rotate_z_node.advertise<geometry_msgs::Twist>("/cmd_vel",1000);
	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
		{

		 geometry_msgs::Twist vel;
		 	
		 vel.angular.z = 0.1;

		 cmd_pub.publish(vel);
		 ros::spinOnce();

		 loop_rate.sleep();
		 ++count;
		}

	return 0;
}