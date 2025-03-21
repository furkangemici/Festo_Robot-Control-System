/**
 * @file FestoRobotSensorInterface.h
 * @author Furkan Gemici
 * @date December, 2024
 * @brief Declaration of the FestoRobotSensorInterface.h class.
 *
 * This class is responsible for managing the Festo robot sensor interface, including handling sensor data.
 *
 */
#pragma once

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "SensorInterface.h"

#include <string>

class FestoRobotSensorInterface : public SensorInterface
{
protected:
	std::string sensorType;
	FestoRobotAPI* robotAPI;
public:
	FestoRobotSensorInterface(string _type, FestoRobotAPI* _robotAPI) : sensorType(_type), SensorInterface(_type), robotAPI(_robotAPI) {}
};