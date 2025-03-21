#include "MotionMenu.h"
#include "SafeNavigation.h"
#include <thread>   // Sleep için
#include <chrono>   // Sleep için
#include "Menus.h"
#include <sstream>
#include<iostream>
#include "Robot.h"
#define SAFE_DISTANCE 0.4
#include <map>
const double MIN_DISTANCE = 0.3;
const int MOVE_DURATION = 300;  // Hareket adýmý süresi (ms)
const double WARNING_DISTANCE = 0.4; // Yavaþlama mesafesi




void MotionMenu::printChoice()
{
	cout << choice << endl;
}



/**
 * @brief Runs the motion menu and performs corresponding robot motions.
 *
 * This function displays the motion menu and allows the user to choose various
 * robot motion options such as moving forward, backward, turning left or right,
 * printing the controller status, and returning to the main menu or exiting the program.
 *
 * @return Returns true to continue executing the main menu, false to exit the program.
 */
bool MotionMenu::run() {
	cout << "Motion Menu" << endl;
	bool motion = true;

	while (motion)
	{
		printChoice();

		int pick2;
		cin >> pick2;

		switch (pick2)
		{
			case 0:
				motion = false;
				cout << "Exit..." << endl;
				return false;
				break;
			case 1:
				if (robot->robotControler)
				{
					robot->robotControler->moveForward();
					cout << "Robot moving forward." << endl;
					Sleep(1000);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			
			case 2:
				if (robot->robotControler)
				{
					robot->robotControler->moveBackward();
					cout << "Robot moving backward..." << endl;
					Sleep(1000);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;

			case 3:
				if (robot->robotControler)
				{
					robot->robotControler->turnLeft();
					cout << "Robot turning left." << endl;
					Sleep(500);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 4:
				if (robot->robotControler)
				{
					robot->robotControler->turnRight();
					cout << "Robot turning right." << endl;
					Sleep(500);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			
			case 5:
				if (robot->robotControler)
				{
					cout << "Safe Move Robot" << endl;
					this->robot->safeNavigation = new SafeNavigation(robot->irSensor, robot->robotControler);
					this->robot->safeNavigation->moveForwardSafe();
					cout << "Robot moving forward..." << endl;
					//Sleep(10);
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 6:
				if (robot->robotControler)
				{
					cout << "Safe Move Robot" << endl;
					this->robot->safeNavigation = new SafeNavigation(robot->irSensor, robot->robotControler);
					this->robot->safeNavigation->moveBackwardSafe();
					cout << "Robot moving backward..." << endl;
					//Sleep(100);
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;

			case 7:
			    cout << "It is under development" << endl;
				break;
			case 8:
				if (robot->robotControler)
				{
					robot->robotControler->print();
				}
				else
				{
					cout << connectionErr;
				}
				break;
			case 9:
				motion = false;
				cout << "Back to main menu..." << endl << endl;
				break;
			
			default:
				cout << "Please enter a valid number!" << endl << endl;
				break;
		}
		return true;
	}
}

