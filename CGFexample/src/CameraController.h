#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#define FREE_CAMERA 0
#define AUTO_CAMERA 1
#define CAMERA_MOVEMENT_TIME 10000

#include "CGFcamera.h"
#include "PositionPoint.h"

#define PLAYER1_ANGLE 0.0
#define PLAYER2_ANGLE 180.0
#define PLAYER1_SECOND_ANGLE 360.0

#define PLAYER1 0
#define PLAYER2 1

class CameraController {
	float focusingTo;
	CGFcamera* freeCamera;
	int enabledCamera;
	PositionPoint currentAutoCameraPos;
	float initialTime;
    float currentAngle;
    float startingAngle;
public:
    CGFcamera* autoCamera;
	bool isChangingFocus;
	bool focusChangeInitialized;
	CameraController();
	CGFcamera* getEnabledCamera();
	CGFcamera* getAutoCamera();
	CGFcamera* getFreeCamera();
	void changeCamera();
	void moveCameraToPoint(/*PositionPoint point*/);
	void changePlayerFocus(int player);
	void initializeFocusChange(unsigned long t);
	void updateFocus(unsigned long t);
    int enabled;
};

#endif
