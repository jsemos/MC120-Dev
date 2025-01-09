//Created by Jerome Kris Semos
//CopyRight MCS department (2022) 
/*Students are to create a payroll program in C that reads a text file (payrollData.txt) containing data such as
employee first name, last name, the total number of work hours (per week) and rate of pay per hour. This program
upon calculation must store the results (employee wages information) as output into another text file
(payrollInfo.txt). .*/

#define _CRT_SECURE_NO_WARNINGS
#define regularHours 40
#define overTimeRate 1.5
#define stringMAX 30
#define fullnameMAX 10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function prototypes created by user
int highestPayedEmp(int i, int w, float hp);
void mainLoop();
void summaryMsg(int w, float gtw, char str_fullname[], float hp);
void txtOutput();

//global variables declared here 
char str_fullname[fullnameMAX][stringMAX], str_lastName[stringMAX] = ""; //string variables for the program
int rate = 0, count = 0, workers = 0, index=0; //integer variable for the program 
float wage = 0.0, grandTotalWage=0.0, highestPayed=0.0, netPay[4], regularPay = 0.0, overtimePay = 0.0; //float variables for program calculation

FILE* fptrIN, * fptrOUT; //declaring file pointer read and write

//function main begins program execution
int main(void)
{
	mainLoop();
	//system("pause");
} //end function main

//main loop for validating file opening and calling of sub-functions
void mainLoop() {
	if ((fptrIN = fopen("payrollData.txt", "r")) == NULL) { //basic file input test to validate file read availability
		printf("Error! Reading payroll data file");
		return 0;
	}
	else if ((fptrOUT = fopen("payrollInfo.txt", "w")) == NULL) { //basic file output test to validate file write availability
		printf("Error! Writing to payroll information file");
		return 0;
	}
	else {

		txtOutput();

		highestPayedEmp(index, workers, highestPayed);

		summaryMsg(workers, grandTotalWage, str_fullname[index], highestPayed);

		system("payrollInfo.txt"); //display output text file
	}
}

//Function to output information into text file 
void txtOutput() {
	printf("%s\n\n", "Both files opened successfully");
	fprintf(fptrOUT, "%s\t\t%s\t%s\t\t%s\t\t%s\t%s\n", "Name", "Hour", "Rate", "Regular", "Overtime", "Net"); //first column heading of the text file

	while (fscanf(fptrIN, "%s%s%d%f", str_fullname[workers], str_lastName, &rate, &wage) != EOF) { //main loop receiving data from text file
		strcat(str_fullname[workers], " ");
		strcat(str_fullname[workers], str_lastName); //string concatenate to produce employee fullname 

		if (rate <= regularHours) { //calculate regular pay
			regularPay = rate * wage;
			overtimePay = 0.00;
			netPay[workers] = regularPay + overtimePay;
		}
		else { //calculate over pay
			regularPay = (regularHours * wage);
			overtimePay = (((rate - regularHours) * overTimeRate) * wage);
			netPay[workers] = regularPay + overtimePay;
		}

		grandTotalWage += netPay[workers]; //calculates the grand total wages payed to all employees

		//output to text file individual employee payroll record
		fprintf(fptrOUT, "%-10s\t%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", str_fullname[workers], rate, wage, regularPay, overtimePay, netPay[workers]);

		workers++; //count number of worker records for summary output
	}
}

//Function to determine the highest payed employee
int highestPayedEmp(int i, int w, float hp) {

	highestPayed = netPay[0];

	//simple bubble sort to find highest payed worker
	for (int i = 0; i < workers; i++) {
		if (netPay[i] > highestPayed) {
			highestPayed = netPay[i];
			index = i;
		}
	}
	return index;
}

//Function to output summary message
void summaryMsg(int w, float gtw, char str_fullname[], float hp) {
		
	//lastly output the summary information required
	fprintf(fptrOUT, "\n===============================================================================================\n");
	fprintf(fptrOUT, "%s%d\n", "Number of employees: ", w);
	fprintf(fptrOUT, "%s%.2f\n", "Grand total wage paid: K", gtw);
	fprintf(fptrOUT, "%-10s%s%.2f\n", str_fullname, " earned the most pay this week, K", hp);
	fprintf(fptrOUT, "===============================================================================================\n");

	//close file input and output (Read & Write) streams
	fclose(fptrIN);
	fclose(fptrOUT);
	//Give user useful information via console or terminal concerning program's conclusion or result
	printf("%s\n", "Refer to payroll information opened in the text file (Close text file to end the program))");
}