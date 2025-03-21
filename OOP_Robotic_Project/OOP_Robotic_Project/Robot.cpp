#include "Robot.h"

/**
 * @brief Default constructor for the Robot class.
 *
 * This constructor initializes the Robot object by setting the controller
 * to NULL and creating instances of BumperSensor, ForceSensor, and SonarSensor.
 */

Robot::Robot()
{
	robotAPI = new FestoRobotAPI;
	robotControler = NULL;
	robot = new FestoRobotInterface(robotAPI);
	irSensor = new IRSensor(robotAPI);
	lidarSensor = new LidarSensor(robotAPI);
	
}