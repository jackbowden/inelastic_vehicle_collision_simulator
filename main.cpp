#include <iostream>
#include <cmath> //for squaring and square rooting
#include <stdlib.h> //for system
#include <limits>


using namespace std;

bool isRightAngle(double angle)
{
    if (angle == 0)
    {
        if (signbit(angle)) //if its -0 ...
            cout << "The vehicles are heading on the angle of 0 degrees." << endl;
        else //if its just plain 0...
            cout << "The vehicles are heading on the angle of 180 degrees." << endl;
        return true;
    }
    else if (angle == -90)
    {
        cout << "The vehicles are heading on the angle of 90 degrees." << endl;
        return true;
    }
    else if (angle == 90)
    {
        cout << "The vehicles are heading on the angle of 270 degrees." << endl;
        return true;
    }
    else
        return false;
}


double findQuadrant(double coss, double sinn) //FOR FINDING CORRECTIONS TO ANGLE ONLY
{
    if ((coss < 0) && (sinn < 0)) //QUAD 1
    {
        //cout << "It's in QUAD 1";
        return 0;
    }
    else if ((coss < 0) && (sinn > 0)) //QUAD 2
    {
        //cout << "It's in QUAD 2!";
        return 90;
    }
    else if ((coss > 0) && (sinn > 0)) //QUAD 3
    {
        //cout << "It's in QUAD 3!";
        return 180;
    }
    else if ((coss > 0) && (sinn < 0)) //QUAD 4
    {
        //cout << "It's in QUAD 4!";
        return 270;
    }
}

void calculate(double mass_1, double p_x_1, double p_y_1, double mass_2, double p_x_2, double p_y_2, double timetc)
{
    cout << "----------------------------------" << endl << "INELASTIC VEHICLE CRASH SIMULATION" << endl << "----------------------------------" << endl;
    cout << "Mass of vehicle 1: " << mass_1 << " kilograms." << endl;
    cout << "Mass of vehicle 2: " << mass_2 << " kilograms." << endl;
    cout << "Coordinates of vehicle 1: (" << p_x_1 << "," << p_y_1 << ")" << endl;
    cout << "Coordinates of vehicle 2: (" << p_x_2 << "," << p_y_2 << ")" << endl;
    cout << "Seconds before collision: " << timetc << " seconds." << endl << endl;
    double distanceCalculated = sqrt((p_x_2 - p_x_1)*(p_x_2 - p_x_1) + (p_y_2 - p_y_1)*(p_y_2 - p_y_1));
    cout << "OK, so the two vehicles appear to be " << distanceCalculated << " units apart from each other." << endl << endl;

    cout << "We'll assume they collided at the origin (0,0) of a coordinate plane." << endl;
    double distanceFromOriginVehicle1 = sqrt((0 - p_x_1)*(0 - p_x_1) + (0 - p_y_1)*(0 - p_y_1));
    cout << "Vehicle 1 is " << distanceFromOriginVehicle1 << " units from the origin." << endl;
    double distanceFromOriginVehicle2 = sqrt((0 - p_x_2)*(0 - p_x_2) + (0 - p_y_2)*(0 - p_y_2));
    cout << "Vehicle 2 is " << distanceFromOriginVehicle2 << " units from the origin." << endl << endl;

    cout << "If both vehicles are " << timetc << " second(s) away from crashing, and we know where they're located... " << endl;
    cout << "...we can find the velocity of both vehicles as they approach the origin!" << endl;
    cout << "We can do this by dividing their distance in units from the origin over the time in seconds before collision: " << endl;
    double velocityVehicle1 = distanceFromOriginVehicle1 / timetc;
    cout << "Vehicle 1 appears to be traveling at " << velocityVehicle1 << " units per second towards the origin."; cout << endl;
    double velocityVehicle2 = distanceFromOriginVehicle2 / timetc;
    cout << "Vehicle 2 appears to be traveling at " << velocityVehicle2 << " units per second towards the origin."; cout << endl << endl;

    cout << "Now we've got all the fun data to compare post-crash. Here's what happens after the vehicles crash:" << endl;
    cout << "========================================================================" << endl;
    float ptotix = (mass_1 * (p_x_1/timetc)) + (mass_2 * (p_x_2/timetc));
    float ptotiy = (mass_1 * (p_y_1/timetc)) + (mass_2 * (p_y_2/timetc));
    float vfx = (ptotix/(mass_1+mass_2));
    float vfy = (ptotiy/(mass_1+mass_2));
    float vf = sqrt((vfx * vfx) + (vfy * vfy));
    cout << "The vehicles collide in an inelastic collision and are now going " << vf << " units per second." << endl;

    double ptotix2 = (mass_1 * (p_x_1/timetc)) + (mass_2 * (p_x_2/timetc));
    double ptotiy2 = (mass_1 * (p_y_1/timetc)) + (mass_2 * (p_y_2/timetc));
    double vfx2 = (ptotix2/(mass_1+mass_2));
    double vfy2 = (ptotiy2/(mass_1+mass_2));
    double angle2 = atan(vfy2/vfx2) * (180 / M_PI); //tan is sin/cos
    double fixedAngle = abs(angle2) + findQuadrant(vfy2, vfx2);
    if (!isRightAngle(angle2))
        cout << "The vehicles are heading on the angle of " << fixedAngle << " degrees." << endl;
    cout << "========================================================================" << endl << endl;
}

int main()
{
    cout << "Concept: Inelastic collision, so total momentum of two vehicles is conserved, and kinetic energy is not conserved." << endl << endl;

    cout << "We can determine the mutual velocity and direction of two vehicles after an inelastic collision!" << endl;
    cout << "We just have to know the masses of the vehicles, how long it took before the vehicles crash, and where they were before they crashed." << endl;
    double mass_1, mass_2, p_x_1, p_y_1, p_x_2, p_y_2, timetc;
    cout << "Mass of vehicle 1 in kg: "; cin >> mass_1;
    cout << "X and Y coordinates of vehicle 1 (separated by spaces): "; cin >> p_x_1 >> p_y_1;
    cout << "Mass of vehicle 2 in kg: "; cin >> mass_2;
    cout << "X and Y coordinates of vehicle 2 (separated by spaces): "; cin >> p_x_2 >> p_y_2;
    cout << "Time before collision in seconds: "; cin >> timetc; cout << endl << endl;

    // NEED TO DO ERROR CHECKING - CHRIS?

    //IF BOTH COORDINATES ARE 0 0, DO SOMETHING HERE

    system("cls");

    calculate(mass_1, p_x_1, p_y_1, mass_2, p_x_2, p_y_2, timetc);

    //calculate(1, -2, 0, 1, 0, -2, 1); //45 degrees quad 1
    //calculate(1, 2, 0, 1, 0, -2, 1); //-45 degrees quad 2
    //calculate(1, 2, 0, 1, 0, 2, 1); //45 degrees quad 3
    //calculate(1, -2, 0, 1, 0, 2, 1); //-45 degrees quad 4

    //calculate(100, 0, -20, 200, -30, 0, 1); //TEST PROBLEM

    //calculate(100, 1, -2, 100, 1, -1, 1); //quad 2 test

    //calculate(100, -2, 0, 200, 2, 0, 1);
    //calculate(200, -2, 0, 100, 2, 0, 1);
    //calculate(100, 0, 2, 200, 0, -2, 1);
    //calculate(200, 0, 2, 100, 0, -2, 1);

    //calculate (200, 0, 2, 100, 0, 2, 1);

    //calculate(200, 0, 0, 100, 0, 2, 1);

    //hold the console open
    std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    std::cin.get();


    return 0;
}

