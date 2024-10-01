#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    //define variables for each data type 
    short int v_sint = 1;
    int v_int = 1;
    long int v_lint = 1;
    char v_char = 'a';
    float v_float = 1.0f;
    double v_double = 1.0;
    long double v_ldouble = 1.0;

    //Open the file for writing 
    FILE *file = fopen("CdataTypes.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file. \n");
        return EXIT_FAILURE;
    }
    
    //Write the header for the table
    fprintf(file, "DataType     Bytes           Min Value          Max Value \n");
    fprintf(file, " ------------ -------------  ----------------   --------- \n");

    //Write data type information to the file 
    fprintf(file, "short int    | %5lu |  |%19i       |%19i       |\n", sizeof(v_sint), SHRT_MIN, SHRT_MAX);
    fprintf(file, "int          | %5lu |  |%19i       |%19i       |\n", sizeof(v_int), INT_MIN, INT_MAX);
    fprintf(file, "long int     | %5lu |  |%19ld      |%19ld      |\n", sizeof(v_lint), LONG_MIN, LONG_MAX);
    fprintf(file, "char         | %5lu |  |%19i       |%19i       |\n", sizeof(v_char), CHAR_MIN, CHAR_MAX);
    fprintf(file, "float        | %5lu |  |%19E       |%19E       |\n", sizeof(v_float), FLT_MIN, FLT_MAX);
    fprintf(file, "double       | %5lu |  |%19E       |%19E       |\n", sizeof(v_double), DBL_MIN, DBL_MAX);
    fprintf(file, "long double  | %5lu |  |%20Le      |%20Le      |\n", sizeof(v_ldouble), LDBL_MIN, LDBL_MAX);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;

}  