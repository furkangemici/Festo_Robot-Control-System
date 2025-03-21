#include "RobotInterface.h"
#include <iostream>




// Pose d�nd�ren fonksiyon
Pose* RobotInterface::getPose() {
    return position; // Mevcut konumu d�nd�r�r
}


void RobotInterface::updateSensors() {
	for (auto sensor : *sensorList) {
		sensor->updateSensor();
	}
}

void RobotInterface::addSensor(SensorInterface* sensor) {
	this->sensorList->push_back(sensor);
}

std::vector<SensorInterface*> RobotInterface::getSensors() const {
	return *sensorList;
}

