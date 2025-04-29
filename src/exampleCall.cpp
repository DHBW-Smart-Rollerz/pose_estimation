#include "peInterface/PoseEstimator.h"
#include <iostream>

// Falls nicht vorhanden, kopieren aus: /Applications/MATLAB_R2024b.app/extern/include/tmwtypes.h

int main() {
    // Define the parameters
    double parameters[6] = {-20.0, -60.0, 0.175, 0.085, 0.0283384, 2.985}; // c_f, c_r, l_f, l_r, J, m
    double dt = 0.005;
    double processNoise[9] = {1e-3, 0, 0, 0, 1e-6, 0, 0, 0, 1e-3}; // v_x, v_y, psi_dot
    double measurementNoise[4] = {1.0, 0, 0, 1.0}; // psidot, v_x
    double u[2] = {1.0, 2.0};
    double z[2] = {3.0, 4.0};
    double outputArg1[3];
    double outputArg2[3];

    PoseEstimator poseEstimator;
    poseEstimator.init(parameters, dt, processNoise, measurementNoise);
    poseEstimator.predict(u);
    poseEstimator.correct(z);
    poseEstimator.getState(outputArg1);
    poseEstimator.getPose(outputArg2);

    // Print the results
    std::cout << "Output Arg 1: [" << outputArg1[0] << ", " << outputArg1[1] << ", " << outputArg1[2] << "]" << std::endl;
    std::cout << "Output Arg 2: [" << outputArg2[0] << ", " << outputArg2[1] << ", " << outputArg2[2] << "]" << std::endl;

    return 0;
}