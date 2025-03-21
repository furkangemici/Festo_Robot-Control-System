//#include "MapManager.h"
//#include "MAP.h"
//
//MapManager::MapManager(Robot* robot) {
//	map = new MAP(50, 50, 1);
//	//lidarSensor = new LidarSensor(robot->robotAPI);
//	mapper = new Mapper(robot->robotControler, lidarSensor);
//	//irSensor = new IRSensor(robot->robotAPI);
//	robotAPI = robot->robotAPI;
//}
//
//MapManager::~MapManager() {
//	delete map;
//	delete mapper;
//	delete lidarSensor;
//	delete irSensor;
//}
//
//void MapManager::updateMap() {
//	mapper->updateMap();
//}
//
//void MapManager::recordMap(const std::string& filename) {
//	if (mapper->recordMap()) {
//		mapper->recordMap();
//	}
//}
//
//void MapManager::showMap() {
//	mapper->showMap();
//}