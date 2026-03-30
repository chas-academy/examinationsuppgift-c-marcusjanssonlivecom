//Write your code in this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student {
    char name[10];
    int scoreSum;
    float average;
};

struct Student calculateStudentInfo();

int main() {

    //Scan input 5 times and store values
    struct Student student1 = calculateStudentInfo();
    struct Student student2 = calculateStudentInfo();
    struct Student student3 = calculateStudentInfo();
    struct Student student4 = calculateStudentInfo();
    struct Student student5 = calculateStudentInfo();

    //Calculate total average score for all students
    float totalAverage = (student1.average + student2.average + student3.average + student4.average + student5.average) / 5.0;

    //Print out the name of the student with the highest average score, by comparing each student's average score to each other
    struct Student topStudent = student1; // Initialize topStudent to the first student to begin comparison
    if (student2.average > topStudent.average) {
        topStudent = student2;
    }
    if (student3.average > topStudent.average) {
        topStudent = student3;
    }
    if (student4.average > topStudent.average) {
        topStudent = student4;
    }
    if (student5.average > topStudent.average) {
        topStudent = student5;
    }

    printf("%s\n", topStudent.name);

    //Print out each student's name that whose average is below the total average
    if (student1.average < totalAverage) {
        printf("%s\n", student1.name);
    }
    if (student2.average < totalAverage) {
        printf("%s\n", student2.name);
    }
    if (student3.average < totalAverage) {
        printf("%s\n", student3.name);
    }
    if (student4.average < totalAverage) {
        printf("%s\n", student4.name);
    }
    if (student5.average < totalAverage) {
        printf("%s\n", student5.name);
    }
    
    return 0;
}

struct Student calculateStudentInfo() {
    //Designate array to store line of input using fgets.
    char studArray[100];
    fgets(studArray, sizeof(studArray), stdin);

    //Create a Student struct to store the info in. Initialize score sum to 0.
    struct Student studentInfo;
    studentInfo.scoreSum = 0;

    bool isName = true;
    for (int i = 0; i < 100; i++) { // Loops through the input until it reaches the null terminator
        
        if (isName) {
            
            //When it reaches a space, it sets isName to false, indicating that the following inputs are only numbers
            if (studArray[i] == ' ') {
                isName = false;

                if (i >= 11) { //If the name is longer than 10 character (first space is index 11 or later), it is invalid. Terminate program
                    printf("Invalid name input.\n");
                    exit(1); // Terminate the program
                }
                //Name identified. Store it in a separate array for later use
                for (int j = 0; j < i; j++) {
                    studentInfo.name[j] = studArray[j];
                }
                studentInfo.name[i] = '\0'; // Add null terminator to the end of the name string
                
                continue; // Skip the space character and move to the next iteration
            }

            //Check if input is a letter by comparing ASCII values. If not, terminate program
            if (!((studArray[i] >= 'a' && studArray[i] <= 'z') || (studArray[i] >= 'A' && studArray[i] <= 'Z') || studArray[i] == ' ')) {
                printf("Invalid letter input.\n");
                exit(1); // Terminate the program
            }

            //Turn the first letter of the name to uppercase if it is lowercase
            if (i == 0 && studArray[i] >= 'a' && studArray[i] <= 'z') {
                // Subtracts the difference between upper and lowercase on the ascii table
                studArray[i] = studArray[i] - ('a' - 'A');
            }
        }

        if (!isName) {

            if (studArray[i] == ' ') {
                continue; // Skip spaces between numbers
            }
            
            //Check if input is a non-number by comparing ASCII values. If it is, terminate program
            if (studArray[i] > '9' || studArray[i] < '0') {
                printf("Invalid number input at position %d\n", i);
                exit(1); // Terminate the program
            }
            else {
                //This is a number. Add it to the total score.
                if (studArray[i] == '1' && studArray[i + 1] == '0') { //Check if this is a 10
                    studentInfo.scoreSum += 10;
                    i++; // Skip the next character since it's part of the same number
                }
                else { // if it's not a 10, it's single digit. Add it normally
                    studentInfo.scoreSum += studArray[i] - '0'; // Convert character to integer and add to sum
                }
            }

            //Stop when it reaches the null terminator, which indicates the end of the input
            if (studArray[i+1] == '\0' || studArray[i+1] == '\n') {
                break;
            }
        }

    }

    //calculate average by dividing total score by 13, since there are 13 scores for each student
    studentInfo.average = studentInfo.scoreSum / 13.00;
    //printf("Average score for %s: %.2f\n", studentInfo.name, studentInfo.average); // Print the average score for the student

    return studentInfo;
}
