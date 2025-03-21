#include "RobotInterface.h"
#include <iostream>




// Pose döndüren fonksiyon
Pose* RobotInterface::getPose() {
    return position; // Mevcut konumu döndürür
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

