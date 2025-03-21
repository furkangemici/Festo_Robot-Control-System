

#include <iostream>
#include <string>
using namespace std;
#include "Pose.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "RobotControler.h"




//RobotControler::RobotControler(FestoRobotInterface* _robot)
//    : robotOperator(name, surname, accessCode), record("output.txt") {
//    this->robot = _robot;
//    robot->connectRobot();
//    Sleep(100);
//
//}



RobotControler::RobotControler(FestoRobotInterface* _robot) 
    : robotOperator(name, surname, accessCode), record() 
{
    this->robot = _robot;
	robot->connectRobot();
    

    
	Sleep(100);
    //changestatus
}

RobotControler::~RobotControler() {
    delete this->robot;
    cout << "RobotControler destroyed and resources cleaned up." << endl;
}

/**
 * @brief This function turns the robot to the left if it is connected.
 */
void RobotControler::turnLeft() {
    this->robot->turnLeft();
}

/**
 * @brief This function turns the robot to the right if it is connected.
 */
void RobotControler::turnRight() {
    this->robot->turnRight();

}

/**
 * @brief This function moves the robot forward if it is connected.
 */
void RobotControler::moveForward() {
    this->robot->moveForward();
}

/**
 * @brief This function moves the robot backward if it is connected.
 */
void RobotControler::moveBackward() {
    this->robot->moveBackward();
}

/**
 * @brief This function moves the robot to the left if it is connected.
 */
void RobotControler::moveLeft() {
    this->robot->moveLeft();
}

/**
 * @brief This function moves the robot to the right if it is connected.
 */
void RobotControler::moveRight() {
    this->robot->moveRight();
}

/**
 * @brief This function stops the robot if it is connected.
 */
void RobotControler::stop() {
    this->robot->stop();
}

/**
 * @brief This function returns the current position and orientation of the robot.
 * @return The current position of the robot as a Pose object.
 */
Pose RobotControler::getPose() {
    return *this->robot->getPose();
}

/**
 * @brief This function prints the current status of the robot.
 */
void RobotControler::print() {
    this->robot->print();
}

/**
 * @brief This function connects the robot to the API if it is not already connected.
 * @return true if the connection is successful, false otherwise.
 */
bool RobotControler::connectRobot() {
    return this->robot->connectRobot();
}

/**
 * @brief This function disconnects the robot from the API if it is connected.
 * @return true if the disconnection is successful, false otherwise.
 */
bool RobotControler::disconnectRobot() {
    return this->robot->disconnectRobot();
}

void RobotControler::addSensor(SensorInterface* _sensor) {
    this->robot->addSensor(_sensor);
}

void RobotControler::updateSensors() {
	for (int i = 0; i < this->robot->getSensors().size(); i++) {
        this->robot->getSensors()[i]->updateSensor();
	}
}

SensorInterface* RobotControler::getSensor(string sensorType) {
    for (int i = 0; i < this->robot->getSensors().size(); i++) {
		if (this->robot->getSensors()[i]->getSensorType() == sensorType) {
			return this->robot->getSensors()[i];
		}
	}
	return nullptr;
}

bool RobotControler::openAccess(int accessCode) {
    if(accessCode == this->accessCode) {
		return true;
	}
    return false;
}

bool RobotControler::closeAccess(int accessCode)  {
    if(accessCode == this->accessCode) {
		return true;
	}
	return false;
}

//vector<SensorInterface*> RobotControler::getSensors() const {
//	return this->sensorList;
//}

void RobotControler::print(const std::string& sensorName) {
    for (int i = 0; i < this->robot->getSensors().size(); i++)
    {
        if (this->robot->getSensors()[i]->getSensorType() == sensorName)
        {
            this->robot->getSensors()[i]->printSensor();
        }
    }
}

void RobotControler::moveForwardSafe() {
    this->robot->moveForwardSafe();
    Sleep(50);
    this->robot->stop();
}

void RobotControler::moveBackwardSafe() {
	this->robot->moveBackwardSafe();
	Sleep(50);
	this->robot->stop();
}

