/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       matejstastny                                              */
/*    Created:      3/10/2025, 9:57:41 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

vex::brain Brain;
vex::controller Controller;

vex::motor leftFrontMotor(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor leftBackMotor(vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor rightFrontMotor(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor rightBackMotor(vex::PORT12, vex::gearSetting::ratio18_1, true);

vex::motor armLeft(vex::PORT14, vex::gearSetting::ratio18_1, false);
vex::motor armRight(vex::PORT15, vex::gearSetting::ratio18_1, true);

vex::motor clawLeft(vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor clawRight(vex::PORT9, vex::gearSetting::ratio18_1, false);

vex::distance distanceSensor(vex::PORT8);

void driveForwardUntilDistance(double targetDistance) {
    while (distanceSensor.objectDistance(vex::distanceUnits::cm) > targetDistance) {
        leftFrontMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        leftBackMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        rightFrontMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        rightBackMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        vex::task::sleep(30);
    }
    leftFrontMotor.stop(vex::brakeType::brake);
    leftBackMotor.stop(vex::brakeType::brake);
    rightFrontMotor.stop(vex::brakeType::brake);
    rightBackMotor.stop(vex::brakeType::brake);
}

void drive(double seconds, bool forwards) {
    if (!forwards) {
        leftFrontMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
        leftBackMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
        rightFrontMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
        rightBackMotor.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
    } else {
        leftFrontMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        leftBackMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        rightFrontMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
        rightBackMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
    }
    vex::task::sleep(seconds * 1000);
    leftFrontMotor.stop(vex::brakeType::brake);
    leftBackMotor.stop(vex::brakeType::brake);
    rightFrontMotor.stop(vex::brakeType::brake);
    rightBackMotor.stop(vex::brakeType::brake);
}

void turn(int angle) {
    leftFrontMotor.spinFor(vex::directionType::fwd, angle, vex::rotationUnits::deg, 30, vex::velocityUnits::pct, false);
    leftBackMotor.spinFor(vex::directionType::fwd, angle, vex::rotationUnits::deg, 30, vex::velocityUnits::pct, false);
    rightFrontMotor.spinFor(vex::directionType::rev, angle, vex::rotationUnits::deg, 30, vex::velocityUnits::pct, false);
    rightBackMotor.spinFor(vex::directionType::rev, angle, vex::rotationUnits::deg, 30, vex::velocityUnits::pct);
}

void remoteControll() {
    while (true) {
        int leftSpeed = -Controller.Axis2.position();
        int rightSpeed = -Controller.Axis3.position();

        leftFrontMotor.spin(vex::directionType::fwd, leftSpeed, vex::velocityUnits::pct);
        leftBackMotor.spin(vex::directionType::fwd, leftSpeed, vex::velocityUnits::pct);
        rightFrontMotor.spin(vex::directionType::fwd, rightSpeed, vex::velocityUnits::pct);
        rightBackMotor.spin(vex::directionType::fwd, rightSpeed, vex::velocityUnits::pct);

        if (Controller.ButtonR1.pressing()) {
            if (!armLeft.isSpinning() || !armRight.isSpinning()) {
                armLeft.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
                armRight.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
            }
        } else if (Controller.ButtonR2.pressing()) {
            if (!armLeft.isSpinning() || !armRight.isSpinning()) {
                armLeft.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
                armRight.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            }
        } else  if (Controller.ButtonL1.pressing()) {
            if (!clawLeft.isSpinning() || !clawRight.isSpinning()) {
                clawRight.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
                clawLeft.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            }
        } else if (Controller.ButtonL2.pressing()) {
            if (!clawLeft.isSpinning() || !clawRight.isSpinning()) {
                clawLeft.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
                clawRight.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
            }
        } else {
            armLeft.stop(vex::brakeType::hold);
            armRight.stop(vex::brakeType::hold);
            clawLeft.stop(vex::brakeType::hold);
            clawRight.stop(vex::brakeType::hold);
        }
        vex::task::sleep(20);
    }
}

void automatic() {
    // Move the arm up
    armLeft.spin(vex::directionType::rev, -50, vex::velocityUnits::pct);
    armRight.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    vex::task::sleep(440);
    armLeft.stop(vex::brakeType::hold);
    armRight.stop(vex::brakeType::hold);

    turn(200);
    drive(3, true);
    turn(-430);
    driveForwardUntilDistance(10);

    // Close claw
    clawLeft.spin(vex::directionType::rev, -50, vex::velocityUnits::pct);
    clawRight.spin(vex::directionType::fwd, -50, vex::velocityUnits::pct);
    vex::task::sleep(500);
    clawLeft.stop(vex::brakeType::hold);
    clawRight.stop(vex::brakeType::hold);

    // Move the arm up
    armLeft.spin(vex::directionType::rev, -50, vex::velocityUnits::pct);
    armRight.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
    vex::task::sleep(500);
    armLeft.stop(vex::brakeType::hold);
    armRight.stop(vex::brakeType::hold);

    drive(3, false);
    turn(-580);
    drive(2.8, true);

    // Move the arm up
    armLeft.spin(vex::directionType::fwd, -50, vex::velocityUnits::pct);
    armRight.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    vex::task::sleep(700);
    armLeft.stop(vex::brakeType::hold);
    armRight.stop(vex::brakeType::hold);

    clawLeft.spin(vex::directionType::fwd, -30, vex::velocityUnits::pct);
    clawRight.spin(vex::directionType::rev, -30, vex::velocityUnits::pct);
    vex::task::sleep(500);
    clawLeft.stop(vex::brakeType::hold);
    clawRight.stop(vex::brakeType::hold);


}

int main() {
    armLeft.setVelocity(50, percent);
    armLeft.setVelocity(50, percent);

    // remoteControll();
    automatic();
}
