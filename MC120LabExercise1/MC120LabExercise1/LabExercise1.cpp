//Created by Jerome Kris Semos
//CopyRight MCS department (2022) 
/*This Body Mass Index (BMI) calculator in C that reads or prompts for an individual’s weight in kilograms and height in meters. 
This program also calculates correctly and display the individual’s category of BMI and BMI value. .*/

#include <stdio.h>

//function prototypes created by user
void welcomeMsg();
void exitMsg();
float bmiCal(float w, float h);
void bmiCategory(float b);

//declared global variables
float weight, height, BMIValue;

//function main begins program execution
int main(void)
{
	welcomeMsg();	

	bmiCal(weight, height);

	bmiCategory(BMIValue);

	exitMsg();

	//system("pause");
} //end function main

//welcome message function
void welcomeMsg() {
	//welcome message output
	printf("%s\n%s\n%s\n\n", "*****************************************************",
		"**** Welcome to Jerome's BMI calculator program! ****", "*****************************************************");
}

//exit message function
void exitMsg() {
	//exit message output
	printf("\n%s\n%s\n%s\n\n", "*****************************************************", 
		"*Thank you for using Jerome's BMI calculator program*", "*****************************************************");
}

//user prompt and calculate BMI function
float bmiCal(float w, float h) {
	//input the individual's weight in kilograms
	printf("Enter your weight in kilograms: ");
	scanf_s("%f", &weight);

	//input the individual's height in meters
	printf("Enter your height in meters: ");
	scanf_s("%f", &height);

	//calculation of BMI
	BMIValue = weight / (height * height);

	return BMIValue;
}

//function to determine BMI category 
void bmiCategory(float b) {

	//output of the three numbers sum and product to the console
	printf("\n%s%.1f", "Your BMI is ", BMIValue);

	//identify the BMI's category and output to console
	if (BMIValue < 18.5) {
		printf("%s\n", " which is Underweight");
	}
	else if (BMIValue >= 18.5 && BMIValue <= 24.9) {
		printf("%s\n", " which is Normal");
	}
	else if (BMIValue >= 25 && BMIValue <= 29.9) {
		printf("%s\n", " which is Overweight");
	}
	else {
		printf("%s\n", " which is Obese");
	}
}