

#include "SafeNavigation.h"
#include <iostream>
#define SAFE_DISTANCE 0.4
#include <sstream>
#include "Helper.h"








SafeNavigation::SafeNavigation(IRSensor* sensor, RobotControler* ctrl)
    : IR(sensor), controler(ctrl), state(STOP)
{
    IR = sensor;
    controler = ctrl;
    
    if (!sensor || !ctrl) {
        throw std::invalid_argument("sensor and controler must not be nullptr");
    }
}


void SafeNavigation::moveForwardSafe()
{
    
    IR->updateSensor();
    double a = 0.0;
    bool isOK;
    a = IR->getRange(0);
    if (a > SAFE_DISTANCE) {
        isOK = true;
    }
    else {
        isOK = false;
        cout << "Obstacle detected at " << a << " meters" << endl;
    }

    while (isOK == true) {
        IR->updateSensor();
        a = IR->getRange(0);
        if (a > SAFE_DISTANCE) {
            isOK = true;
            state = MOVING;
            controler->moveForwardSafe();
        }
        else {
            isOK = false;
            controler->stop();
            cout << "Obstacle detected at " << a << " meters" << endl;
        }
    }

}


void SafeNavigation::moveBackwardSafe()
{
    
    // will be implemented
    IR->updateSensor();
    double a = 0.0, b = 0.0;
    bool isOK;
    a = IR->getRange(4);
    b = IR->getRange(5);
    if (a > SAFE_DISTANCE && b > SAFE_DISTANCE) {
		isOK = true;
	}
	else {
		isOK = false;
		cout << "Obstacle detected at " << a << " meters" << endl;
	}
    while(isOK == true) {
		IR->updateSensor();
		a = IR->getRange(4);
        b = IR->getRange(5);

        if (a > SAFE_DISTANCE && b > SAFE_DISTANCE) {
            isOK = true;
            state = MOVING;
            this->controler->moveBackwardSafe();
        }
        else {
            isOK = false;
            controler->stop();
            cout << "Obstacle detected at " << a << " meters" << endl;
        }
	}

}


