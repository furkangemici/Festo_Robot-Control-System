


#include "LidarSensor.h"
#include <limits>
#include <stdexcept>
#undef max
#include <iostream>
#include <sstream>





LidarSensor::LidarSensor(FestoRobotAPI* _robotAPI) : FestoRobotSensorInterface("Lidar Sensor", _robotAPI) {
    if (!_robotAPI) {
        throw std::invalid_argument("robotAPI is null.");
    }
    ranges = nullptr;
    rangeNumber = 0;
}



LidarSensor::~LidarSensor() {
    delete[] ranges;

}


void LidarSensor::updateSensor() {
    //if (!robotAPI) {
    //    throw std::runtime_error("robotAPI is not initialized.");
    //}

    //std::cout << "Updating Lidar Sensor..." << std::endl;
    //std::cout << "Range Number: " << rangeNumber << std::endl;

    //// Temp array to hold the raw float values from the API
    //float* tempRanges = new float[rangeNumber];

    //try {
    //    // Retrieve all range data into the temp array
    //    robotAPI->getLidarRange(tempRanges);

    //    for (int i = 0; i < rangeNumber; ++i) {
    //        if (i < 0 || i >= rangeNumber) {
    //            throw std::out_of_range("Index out of bounds.");
    //        }

    //        // Convert float values to double and store in ranges
    //        ranges[i] = static_cast<double>(tempRanges[i]);
    //        std::cout << "Lidar Sensor [" << i << "] = " << ranges[i] << " meters" << std::endl;
    //    }
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Error during Lidar update: " << e.what() << std::endl;
    //}

    //

    //// Clean up the allocated memory
    //delete[] tempRanges;

    //std::cout << "Lidar Sensor update completed." << std::endl;

    try {
        rangeNumber = getRangeNumber();

        // double to float cast
        float* tempranges = new float[rangeNumber];

        robotAPI->getLidarRange(tempranges);

        // float to double cast
        ranges = new double[rangeNumber];
        for (int i = 0; i < rangeNumber; ++i) {
            ranges[i] = static_cast<double>(tempranges[i]);
        }

        // deallocate memory
        delete[] tempranges;
    } catch (const std::exception& e) {
		std::cerr << "Error during Lidar update: " << e.what() << std::endl;
	}
    

}



double LidarSensor::getRange(int index) const {
    if (index >= 0 && index < rangeNumber) {
        return ranges[index];
    }
    throw std::out_of_range("Index out of bounds in getRange.");
}


double LidarSensor::getMin(int& index) const {
    double minVal = ranges[0]; // En büyük baþlangýç deðeri
    index = 0;

    for (int i = 1; i < rangeNumber; ++i) {
        if (ranges[i] < minVal) {
            minVal = ranges[i];
            index = i;
        }
    }

    return minVal;
}


double LidarSensor::getMax(int& index) const {
    double maxVal = ranges[0];
    index = 0;
    for (int i = 1; i < rangeNumber; ++i) {
        if (ranges[i] > maxVal) {
            maxVal = ranges[i];
            index = i;
        }
    }
    return maxVal;
}


double LidarSensor::operator[](int i) const {
    return getRange(i);
}


double LidarSensor::getAngle(int i) const {
    if(i>=rangeNumber || i<0) {
		throw std::out_of_range("Index out of bounds in getAngle.");
	}
    double angle = (360.0 / rangeNumber) * i;
    return angle;
}

string LidarSensor::getSensorType()  {
    return this->sensorType;
}


double LidarSensor::getSensorValue(int x) {
    /*std::ostringstream values;
    for (int i = 0; i < rangeNumber; ++i) {
        values << ranges[i] << " ";
    }
    return values.str();*/
    return 1.0;
}

double LidarSensor::getRangeNumber() const {
    double lidarrangeNum = robotAPI->getLidarRangeNumber();
    return lidarrangeNum;
}

void LidarSensor::printSensor() {
	std::cout << "Lidar Sensor: " << std::endl;
	for (int i = 0; i < rangeNumber; ++i) {
		std::cout << "Range[" << i << "] = " << ranges[i] << " meters" << std::endl;
	}
}

void LidarSensor::initializeLidarSensor() {
    rangeNumber = getRangeNumber();
    //castings
    // ranges is double type
    float* tempRanges = new float[rangeNumber];
    robotAPI->getLidarRange(tempRanges);
    // cast it to float
    ranges = new double[rangeNumber];
    for (int i = 0; i < rangeNumber; ++i) {
        ranges[i] = static_cast<double>(tempRanges[i]);
    }
    delete[] tempRanges;
    
}