/*
 * ControlBoard.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_CONTROLBOARD_H_
#define SRC_CONTROLBOARD_H_

#include "WPILib.h"
#include "ButtonReader.h"
#include "TriggerReader.h"
#include "RemoteControl.h"

class ControlBoard: public RemoteControl {
public:
	ControlBoard();
	~ControlBoard() {
	};

	virtual void ReadControls();

	//Drive joystick accessors
	double GetJoystickValue(Joysticks j, Axes a);

	bool GetReverseDriveDesired();
	bool GetArcadeDriveDesired();
	bool GetShooterRunDesired();
	bool GetClimberDesired();
	bool GetFeederRunDesired();
	bool GetFeederReverseDesired();
	bool GetClimberReverseDesired();
	bool GetResetEncodersDesired();
	bool GetSlowDriveTier1Desired();
	bool GetSlowDriveTier2Desired();
	bool GetDriveBackDesired();

private:

	//booleans for desired states of robot
	bool climberReverseDesired, feederReverseDesired, feederRunDesired,
			reverseDriveDesired, arcadeDriveDesired, shooterRunDesired,
			climberDesired, resetEncodersDesired, slowDriveTier1Desired, slowDriveTier2Desired, driveBackDesired;

	double driverLeftJoyX, driverLeftJoyY, driverRightJoyX, driverRightJoyY;
	double operatorLeftJoyX, operatorLeftJoyY, operatorRightJoyX,
			operatorRightJoyY;

	Joystick *driverJoy, *operatorJoy;

	ButtonReader *climberReverseButton, *driveDirectionButton,
			*feederReverseButton, *climberRunButton, *shooterRunButton, *resetEncodersButton, *driveBackButton;

	TriggerReader *slowDriveTier1Button, *slowDriveTier2Button, *feederRunButton;

	void ReadAllButtons();
};

#endif /* SRC_CONTROLBOARD_H_ */
