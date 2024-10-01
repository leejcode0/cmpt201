#define G 66.73E-12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate gravitational acceleration
double calculate_gravity(double mass, double radius, double height) {
    return (G * mass) / ((radius + height) * (radius + height));
}

// Function to load planet data from a file
int load_planet_data(const char *filename, char *planet, double *mass, double *radius) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Split the line into parts
        char name[20];
        sscanf(line, "%[^,], %lf, %lf", name, mass, radius);
        if (strcmp(name, planet) == 0) {
            fclose(file);
            return 1; // Found the planet
        }
    }

    fclose(file);
    return 0; // Planet not found
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./gravity <planet> <distance>\n");
        return 1;
    }

    char *planet = argv[1];
    int distance = atoi(argv[2]);
    double mass, radius, gravity;

    // Load planet data from the text file
    if (!load_planet_data("PlanetInfo.txt", planet, &mass, &radius)) {
        printf("Invalid planet name or data not found.\n");
        return 1;
    }

    gravity = calculate_gravity(mass, radius, distance);
    printf("%s-body @ %de3 [m] is %.2lf [m/s^2]\n", planet, distance, gravity);
    return 0;
}
