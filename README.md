# Block Stacker (VEX V5)

VEX V5 robot program for my Redmond High School Principles of Engineering class.
Stacks blocks
Implements driving, turning, claw, and arm control using both controller input and autonomous sequences.

## Features

- **Drive system**

  - Four-motor tank drive (front/back, left/right).
  - Distance sensor support for automatic stopping.

- **Arm control**

  - Dual motors for lifting.
  - Button mappings for raise/lower with hold braking.

- **Claw control**

  - Dual motors for opening/closing.
  - Button mappings for grab/release with hold braking.

- **Autonomous routine**

  - Lifts arm, turns, drives forward/backward, and grabs a block.
  - Uses distance sensor to approach target.
  - Places the block after navigating.

- **Manual control**
  - Tank drive mapped to joysticks:
    - Axis2 → left side
    - Axis3 → right side
  - Arm mapped to **R1 (up)** and **R2 (down)**
  - Claw mapped to **L1 (close)** and **L2 (open)**

## Code Structure

- `driveForwardUntilDistance(targetDistance)`
  Drives forward until the distance sensor detects an object closer than the target distance.

- `drive(seconds, forwards)`
  Drives forward or backward for a specified duration.

- `turn(angle)`
  Rotates robot by spinning left and right motors in opposite directions.

- `remoteControll()`
  Handles manual driving and arm/claw control via controller.

- `automatic()`
  Predefined sequence for picking up and stacking a block.

- `main()`
  Initializes system, runs the autonomous routine, then starts manual control loop.

## Hardware Mapping

- **Drive Motors**

  - Left Front: Port 1
  - Left Back: Port 2
  - Right Front: Port 11 (reversed)
  - Right Back: Port 12 (reversed)

- **Arm Motors**

  - Left Arm: Port 14
  - Right Arm: Port 15 (reversed)

- **Claw Motors**

  - Left Claw: Port 10
  - Right Claw: Port 9

- **Sensors**

  - Distance Sensor: Port 8

- **Controller**
  - Primary remote control

## Usage

1. Deploy to VEX V5 Brain via VEXcode or compatible toolchain
2. On startup, the robot:
   - Runs the **autonomous** sequence once
   - Switches to **manual control** for driver operation

## Images

These are some images of the robot our group wrote this program for.

<img src="assets/IMG_01.png" alt="Robot Front View" style="width:100%; margin-bottom: 16px;">

<div style="display: flex; flex-wrap: wrap; gap: 2%;">
    <img src="assets/IMG_02.png" alt="Robot Side View" style="width:49%;">
    <img src="assets/IMG_03.png" alt="Robot Angle View" style="width:49%;">
</div>
<div style="display: flex; flex-wrap: wrap; gap: 2%; margin-top: 8px;">
    <img src="assets/IMG_04.png" alt="Robot Detail 1" style="width:49%;">
    <img src="assets/IMG_05.png" alt="Robot Detail 2" style="width:49%;">
</div>
<div style="display: flex; flex-wrap: wrap; gap: 2%; margin-top: 8px;">
    <img src="assets/IMG_06.png" alt="Robot Detail 3" style="width:49%;">
    <img src="assets/IMG_07.png" alt="Robot Detail 4" style="width:49%;">
</div>
<div style="display: flex; flex-wrap: wrap; gap: 2%; margin-top: 8px;">
    <img src="assets/IMG_08.png" alt="Robot Detail 5" style="width:49%;">
    <img src="assets/IMG_09.png" alt="Robot Detail 6" style="width:49%;">
</div>
<div style="display: flex; flex-wrap: wrap; gap: 2%; margin-top: 8px;">
    <img src="assets/IMG_10.png" alt="Robot Detail 7" style="width:49%;">
    <img src="assets/IMG_11.png" alt="Robot Detail 8" style="width:49%;">
</div>
