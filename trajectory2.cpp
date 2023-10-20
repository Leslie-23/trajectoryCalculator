#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#define M_PI		3.14159265358979323846

// Function to calculate the vertical distance traveled by the projectile
double calculateVerticalDistance(double initialVelocity, double launchAngle, double gravity, double time) {
    double angleInRadians = launchAngle * M_PI / 180.0;  // Convert launch angle to radians
    return (initialVelocity * std::sin(angleInRadians) * time) - (0.5 * gravity * std::pow(time, 2));
}

// Function to display the projectile motion with asterisks
void displayProjectileMotion(double initialVelocity, double launchAngle, double gravity, double timeInterval) {
    const int maxHeight = 10;  // Maximum height for display
    const int timeIntervals = 60;  // Number of time intervals

    for (int i = 0; i <= timeIntervals; ++i) {
        double time = static_cast<double>(i) * timeInterval;
        double verticalDistance = calculateVerticalDistance(initialVelocity, launchAngle, gravity, time);
        int height = static_cast<int>(verticalDistance * (maxHeight / initialVelocity));

        // Display the trajectory with asterisks
        for (int j = 0; j < height; ++j) {
            std::cout << ' ';
        }
        std::cout << " ** "  << std::endl;

        // Sleep for a short duration to visualize the motion
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    const double initialVelocity = 100.0;  // Initial velocity in m/s
    const double launchAngle = 45.0;      // Launch angle in degrees
    const double gravity = 9.8;           // Acceleration due to gravity in m/s^2
    const double timeInterval = 0.1;      // Time interval between each step

    displayProjectileMotion(initialVelocity, launchAngle, gravity, timeInterval);

    return 0;
}

