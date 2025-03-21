#include "Mapper.h"
#include <cmath>
#include <iostream>
#include <fstream>





Mapper::Mapper(RobotControler* robotControler, LidarSensor* lidarSensor, int sizeX, int sizeY, double gridSize)
    : robotControler(robotControler), lidarSensor(lidarSensor), map(sizeX,sizeY,gridSize) {

}


void Mapper::updateMap() {
    ///*if (!map || !robotControler || !lidarSensor) {
    //    std::cerr << "Error: Mapper components are not initialized!" << std::endl;
    //    return;
    //}*/

    //std::cout << "Updating Map with Lidar Data..." << std::endl;

    //Pose robotPose = robotControler->getPose();
    //int mapCenterX = map.getNumberX() / 2;
    //int mapCenterY = map.getNumberY() / 2;

    //int robotGridX = mapCenterX + static_cast<int>(robotPose.getX() / map.getGridSize());
    //int robotGridY = mapCenterY + static_cast<int>(robotPose.getY() / map.getGridSize());

    //lidarSensor->update();

    //for (int i = 0; i < lidarSensor->getRangeNumber(); ++i) {
    //    double distance = lidarSensor->getRange(i);
    //    double angle = lidarSensor->getAngle(i);

    //    if (distance <= 0.0 || std::isinf(distance)) {
    //        continue;
    //    }

    //    int gridX = robotGridX + static_cast<int>((distance * std::cos(degreesToRadians(angle))) / map.getGridSize());
    //    int gridY = robotGridY + static_cast<int>((distance * std::sin(degreesToRadians(angle))) / map.getGridSize());

    //    if (gridX >= 0 && gridX < map.getNumberX() && gridY >= 0 && gridY < map.getNumberY()) {
    //        map.setGrid(gridX, gridY, 1);
    //    }
    //}

    lidarSensor->updateSensor();

    Pose robotPose = robotControler->getPose();
    double robotX = robotPose.getX();
    double robotY = robotPose.getY();
    double robotTheta = robotPose.getTh();

    double rangeNumber = lidarSensor->getRangeNumber();

    for (int i = 0; i < rangeNumber; ++i) {
        double range = lidarSensor->getRange(i);
        if (range > 0 && !std::isinf(range)) {
            double angle = lidarSensor->getAngle(i) + robotTheta;
            double x = robotX + range * std::cos(angle);
            double y = robotY + range * std::sin(angle);

            Point point(x, y);
            // inf veya -inf deðerleri atla
            if (std::isinf(x) || std::isinf(y)) {
				continue;
			}
            map.insertPoint(point);
            //map->setGrid(point.getX(), point.getY(), 1);
            cout << "Point inserted: " << point.getX() << " " << point.getY() << endl;
            //map.insertPoint(point);
        }
    }
}


bool Mapper::recordMap() {
    ///*if (!map) {
    //    std::cerr << "Error: Map is not initialized!" << std::endl;
    //    return false;
    //}*/

    //std::ofstream outFile("map.txt");
    //if (!outFile.is_open()) {
    //    std::cerr << "Error: Could not open map.txt" << std::endl;
    //    return false;
    //}

    //for (int y = 0; y < map.getNumberY(); ++y) {
    //    for (int x = 0; x < map.getNumberX(); ++x) {
    //        outFile << (map.getGrid(x, y) ? 'x' : '.') << ' ';
    //    }
    //    outFile << '\n';
    //}

    //outFile.close();
    //std::cout << "Map saved to map.txt" << std::endl;
    this->updateMap();
    Record record;
    record.setFileName("map.txt");
    if (!record.openFile()) {
        std::cerr << "Error: Could not open map.txt" << std::endl;
        return false;
    }

    
    record.writeLine("Map Points:");
    for (int i = 0; i < map.getNumberX(); i++) {
        for (int j = 0; j < map.getNumberY(); j++) {
            record.writeLine("Point: " + std::to_string(i) + " " + std::to_string(j) + " Value: " + std::to_string(map.getGrid(i, j)));
        }
    }
    record.closeFile();
    return true;
}


void Mapper::showMap() {
    this->updateMap();
    map.showMap();


    // it was for debugging
    /*cout << "Map Points:" << endl;
    for (int i = 0; i < map.getNumberX(); i++) {
        for (int j = 0; j < map.getNumberY(); j++) {
            cout << "Point: " << i << " " << j << " Value: " << map.getGrid(i, j) << endl;
        }
    }*/
}
