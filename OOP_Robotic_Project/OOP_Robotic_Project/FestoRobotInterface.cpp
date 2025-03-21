#pragma once
#include "FestoRobotInterface.h"
#include <iostream>
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "SensorInterface.h"
#include "Pose.h"
#include "RobotInterface.h"



FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* _robotAPI)
{
	this->robotAPI = _robotAPI;
	this->position = new Pose(0, 0, 0);

	this->addSensor(new IRSensor(this->robotAPI));
	this->addSensor(new LidarSensor(this->robotAPI));
	
}

void FestoRobotInterface::turnLeft() {
	this->robotAPI->rotate(LEFT);
}

void FestoRobotInterface::turnRight() {
	this->robotAPI->rotate(RIGHT);
}

void FestoRobotInterface::moveForward() {
	this->robotAPI->move(FORWARD);
}

void FestoRobotInterface::moveBackward() {
	this->robotAPI->move(BACKWARD);
}

void FestoRobotInterface::moveLeft() {
	this->robotAPI->move(LEFT);
}

void FestoRobotInterface::moveRight() {
	this->robotAPI->move(RIGHT);
}

void FestoRobotInterface::stop() {
	this->robotAPI->stop();
	this->updatePositions();
	this->updateSensors();
}


Pose* FestoRobotInterface::getPose() {
	double x,y,theta;
	this->robotAPI->getXYTh(x,y,theta);
	Pose* pose = new Pose(x,y,theta);
	return pose;
}

void FestoRobotInterface::print() {
	std::cout << "Robot' s position : " << std::endl;
	std::cout << "X : " << this->position->getX() << std::endl;
	std::cout << "Y : " << this->position->getY() << std::endl;
	std::cout << "Th : " << this->position->getTh() << std::endl;
}

bool FestoRobotInterface::connectRobot() {
	robotAPI->connect();
	Sleep(100);
	this->updatePositions();
	this->updateSensors();
	return true;
}

bool FestoRobotInterface::disconnectRobot() {
	robotAPI->disconnect();

	return true;
}

vector<SensorInterface*> FestoRobotInterface::getSensors()
{
	return *sensorList;
}

void FestoRobotInterface::updatePositions()
{
	double x, y, theta;
	robotAPI->getXYTh(x, y, theta);
	Pose* pose = new Pose(x, y, theta);
	this->getPose()->setPose(pose->getX(), pose->getY(), pose->getTh());
}

// Safe Navigation
void FestoRobotInterface::moveForwardSafe() {
	this->robotAPI->move(FORWARD);
	this->updatePositions();
	this->updateSensors();
}

void FestoRobotInterface::moveBackwardSafe() {
	this->robotAPI->move(BACKWARD);
	this->updatePositions();
	this->updateSensors();
}





