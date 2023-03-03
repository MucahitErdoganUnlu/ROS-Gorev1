#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int32.h>
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(10);


    std_msgs::Int32 msg;
    int value, value2;
    std::cout << "Enter the first angle: ";
    std::cin >> value;
    std::cout << "Enter the second angle: ";
    std::cin >> value2;

    msg.data = 180 - value - value2;


  while (ros::ok())
  {
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

