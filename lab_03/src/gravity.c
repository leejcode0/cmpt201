#define G 66.73E-12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "planets.h"

// Function to calculate gravitational acceleration
double calculate_gravity(double mass, double radius, double height) {
    return (G * mass) / ((radius + height) * (radius + height));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./gravity <planet> <distance>\n");
        return 1;
    }

    char *planet = argv[1];
    int distance = atoi(argv[2]);
    double gravity;

    // Check the planet name and calculate gravity accordingly
    if (strcmp(planet, "mercury") == 0) {
        gravity = calculate_gravity(MERCURY_MASS, MERCURY_RADIUS, distance);
    } else if (strcmp(planet, "venus") == 0) {
        gravity = calculate_gravity(VENUS_MASS, VENUS_RADIUS, distance);
    } else if (strcmp(planet, "earth") == 0) {
        gravity = calculate_gravity(EARTH_MASS, EARTH_RADIUS, distance);
    } else if (strcmp(planet, "mars") == 0) {
        gravity = calculate_gravity(MARS_MASS, MARS_RADIUS, distance);
    } else if (strcmp(planet, "jupiter") == 0) {
        gravity = calculate_gravity(JUPITER_MASS, JUPITER_RADIUS, distance);
    } else if (strcmp(planet, "saturn") == 0) {
        gravity = calculate_gravity(SATURN_MASS, SATURN_RADIUS, distance);
    } else if (strcmp(planet, "uranus") == 0) {
        gravity = calculate_gravity(URANUS_MASS, URANUS_RADIUS, distance);
    } else if (strcmp(planet, "neptune") == 0) {
        gravity = calculate_gravity(NEPTUNE_MASS, NEPTUNE_RADIUS, distance);
    } else {
        printf("Invalid planet name.\n");
        return 1;
    }

    // Correcting the print format to include planet and distance
    printf("%s-body @ %de3 [m] is %.2lf [m/s^2]\n", planet, distance, gravity);
    return 0;
}
