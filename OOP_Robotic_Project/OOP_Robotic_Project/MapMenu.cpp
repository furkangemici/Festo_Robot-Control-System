#include "MapMenu.h"
#include "MapManager.h"

void MapMenu::printChoice() {
	cout << choice << endl;
}

bool MapMenu::run() {
	cout << "Map Menu" << endl;
	bool map = true;

	while (map) {
		printChoice();

		int pick3;
		cin >> pick3;

		switch (pick3) {
		case 1: {
			if (robot->robotControler) {
				cout << "Updating map..." << endl;
				//MapManager* mapManager = new MapManager(robot);
				this->robot->mapper = new Mapper(this->robot->robotControler,
				this->robot->lidarSensor,10, 10,1);
				this->robot->mapper->updateMap();
				//mapManager->updateMap();
			}
			break;
		}

		case 2: {
			if (robot->robotControler) {
				cout << "Recording map..." << endl;
				//MapManager* mapManager = new MapManager(robot);
				//mapManager->recordMap("map.txt");
				this->robot->mapper = new Mapper(this->robot->robotControler,
					this->robot->lidarSensor, 10, 10, 1);
				if(this->robot->mapper->recordMap()){
					cout << "Map recorded successfully." << endl;
				}
				else{
					cout << "Map recording failed." << endl;
				}
				delete this->robot->mapper;
			}
			break;
		}
		case 3: {
			if (robot->robotControler) {
				cout << "Showing map..." << endl;
				//MapManager* mapManager = new MapManager(robot);
				//mapManager->showMap();
				this->robot->mapper = new Mapper(this->robot->robotControler,
					this->robot->lidarSensor, 10, 10, 1);
				this->robot->mapper->showMap();

				delete this->robot->mapper;
			}
			break;
		}
		case 4: {
			map = false;
			cout << "Returning to main menu..." << endl;
			break;
		}
		case 5: {
			map = false;
			cout << "Exiting..." << endl;
			return false;
			break;
		}
		
		
		

		}
		return true;
	}
}