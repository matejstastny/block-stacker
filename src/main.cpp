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

int main() {

    armLeft.setVelocity(50, percent);
    armLeft.setVelocity(50, percent);

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
        } else {
            armLeft.stop(vex::brakeType::hold);
            armRight.stop(vex::brakeType::hold);
        }

        // Small delay to prevent excessive CPU usage
        vex::task::sleep(20);
    }
}
