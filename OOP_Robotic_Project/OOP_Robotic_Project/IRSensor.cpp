
#include "IRSensor.h"
#include <sstream>
#include <iostream>






IRSensor::IRSensor(FestoRobotAPI* _robotAPI) : FestoRobotSensorInterface("IR Sensor", _robotAPI) {
    if (!_robotAPI) {
        throw std::invalid_argument("robotAPI is null.");
    }
    for (int i = 0; i < 9; ++i) {
	    ranges[i] = 0.0; /*!< Initialize all range values to 0.0 */
	}
}


void IRSensor::updateSensor() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = robotAPI->getIRRange(i); /*!< Retrieve range value for sensor i */
    }
    int x = 5;
}

double IRSensor::getRange(int index) const {
    if (index < 0 || index >= 9) {
		throw std::out_of_range("Index out of bounds.");
	}
	return ranges[index];
}


double IRSensor::operator[](int i) const {
    return getRange(i);
}



double IRSensor::getSensorValue(int index)  {
    /*std::ostringstream values;
    for (int i = 0; i < 9; ++i) {
        values << ranges[i] << " ";
    }
    return values.str();*/
    return 1.0;
}

void IRSensor::printSensor()  {
	std::cout << "IR Sensor: " << std::endl;
	for (int i = 0; i < 9; ++i) {
		std::cout << "Range[" << i << "] = " << ranges[i] << " meters" << std::endl;
	}
}

string IRSensor::getSensorType()  {
    return this->sensorType;
}

void IRSensor::initializeIRSensor() {
    // get ranges here
    delete [] ranges;
    double* ranges = new double[9];

    for (int i = 0; i < 9; ++i) {
		ranges[i] = robotAPI->getIRRange(i);
	}
}

