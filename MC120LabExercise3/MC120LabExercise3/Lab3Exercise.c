//Created by Jerome Kris Semos
//CopyRight MCS department (2022) 
/*Your survey program must explain the scale to users upon start-up, before asking the user to rate each issue
using your scale. You are to prompt all five questions to a user before another user can respond. On successful,
survey responses of all five students, the program is to display a summary of the results of your five social or
academic questions .*/

#define _CRT_SECURE_NO_WARNINGS
#define surveyMax 6
#define maxScale 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function prototypes created by user
void surveyPrompt();
void welcomeMsg();
void thanksMsg();
void exitMsg();
void summary();
void calcAvg();
void surveyQ1Result();
void surveyQ2Result();
void surveyQ3Result();
void surveyQ4Result();
void surveyQ5Result();

//global variables declared here 
float avg1, avg2, avg3, avg4, avg5;
int i = 1, totalQ1 = 0, totalQ2 = 0, totalQ3 = 0, totalQ4 = 0, totalQ5 = 0, q1, q2, q3, q4, q5;
char str_question1[200] = "How often do you play sports to socialise? ";
char str_question2[200] = "How often do you go into town for shopping or leisure?  ";
char str_question3[200] = "How often do you attend church?  ";
char str_question4[200] = "How often do you eat at the dinning hall? ";
char str_question5[200] = "How often do you borrow and read library books? ";

//function main begins program execution
int main(void)
{
	surveyPrompt();
	
	calcAvg();

	summary();

	surveyQ1Result();
	surveyQ2Result();
	surveyQ3Result();
	surveyQ4Result();
	surveyQ5Result();

	exitMsg();

	//system("pause");
}

//main user or survey program prompt with validator (rating 1 to 5)
void surveyPrompt() {
	for (i; i <= surveyMax; i++) {
	surveyError:
		welcomeMsg();

		printf(str_question1);
		scanf_s("%i", &q1);

		printf(str_question2);
		scanf_s("%i", &q2);

		printf(str_question3);
		scanf_s("%i", &q3);

		printf(str_question4);
		scanf_s("%i", &q4);

		printf(str_question5);
		scanf_s("%i", &q5);

		if ((q1 == 0 || q1 > maxScale) || (q2 == 0 || q2 > maxScale) || (q3 == 0 || q3 > maxScale) || (q4 == 0 || q4 > maxScale) || (q5 == 0 || q5 > maxScale)) {
			printf("\n%s\n\n", "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x--x-x-x-x-x-x-x-x-x-x-x-x-x-x-x--x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-");
			printf("%s%d%s\n\n", "Participant ", i, " One of your entries was invalid. Please retake the survey answering with a rating between 1 to 5");
			printf("%s\n\n\n", "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x--x-x-x-x-x-x-x-x-x-x-x-x-x-x-x--x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-");
			goto surveyError;
		}

		totalQ1 += q1; totalQ2 += q2; totalQ3 += q3; totalQ4 += q4; totalQ5 += q5;

		thanksMsg();
		system("pause");
		system("cls");
	}
}

//function to calculate average
void calcAvg() {
	avg1 = (float)totalQ1 / surveyMax;
	avg2 = (float)totalQ2 / surveyMax;
	avg3 = (float)totalQ3 / surveyMax;
	avg4 = (float)totalQ4 / surveyMax;
	avg5 = (float)totalQ5 / surveyMax;
}

//function for welcome message
void welcomeMsg() {
	printf("%s\n", "**********************************************************************************************************");
	printf("%s\n", "**************                     Welcome to Jerome's surveying program                    **************");
	printf("%s\n", "----------------------------------------------------------------------------------------------------------");
	printf("%s\n", "This survey conducted is aimed at understanding DWU students perception of social and academic activities");
	printf("%s\n%s\n","**************              Answer each of the five questions on a scale from 1 to 5.       **************", 
		"********   Scale rating : 1 - never, 2 - rarely, 3 - sometimes, 4 - often or 5 - every time     **********");
	printf("%s\n\n", "**********************************************************************************************************");
	printf("%s%d%s\n\n", "Thank you, participant number ", i, " please answer the following five questions");
	printf("%s\n", "----------------------------------------------------------------------------------------------------------");
}

//function for thank you message
void thanksMsg() {
	printf("%s\n", "----------------------------------------------------------------------------------------------------------");
	printf("\n%s\n", "**********************************************************************************************************");
	printf("%s\n", "**************                                                                              **************");
	printf("%s%d%s\n", "**************          Thank you participating in this survey. Participant number ", i ,"        **************");
	printf("%s\n", "**************                                                                              **************");
	printf("%s\n\n", "**********************************************************************************************************");
}

//function for summary prompt
void summary() {
	printf("%s\n", "***********************************************************************************");
	printf("%s\n\n", "------------------------------ SURVEY SUMMARY -------------------------------------");
}

//function for exit message
void exitMsg() {
	printf("\n\n%s\n", "----------- CopyRight Mathematics and Computing Science 2022 - Mr. Semos ---------");
	printf("%s\n", "***********************************************************************************");
}

//function to summarise question 1 survey result
void surveyQ1Result() {
	printf("%s%.1f%s", "Question 1 rating is ", avg1, ", therefore, ");

	if (avg1 > 0.0 && avg1 <= 1.0) {
		printf("%s\n", "DWU Students NEVER play sports to socialise");
	}
	else if (avg1 > 1.0 && avg1 <= 2.0) {
		printf("%s\n", "DWU Students RARELY play sports to socialise");
	}
	else if (avg1 > 2.0 && avg1 <= 3.0) {
		printf("%s\n", "DWU Students SOMETIMES play sports to socialise");
	}
	else if (avg1 > 3.0 && avg1 <= 4.0) {
		printf("%s\n", "DWU Students OFTEN play sports to socialise");
	}
	else if (avg1 > 4.0 && avg1 <= 5.0) {
		printf("%s\n", "DWU Students EVERYTIME play sports to socialise");
	}
	else {
		printf("%s\n", "Question 1 result could not be qualified");
	}
}

//function to summarise question 2 survey result
void surveyQ2Result() {
	printf("%s%.1f%s", "Question 2 rating is ", avg2, ", therefore, ");

	if (avg2 > 0.0 && avg2 <= 1.0) {
		printf("%s\n", "DWU Students NEVER go into town for shopping or leisure");
	}
	else if (avg2 > 1.0 && avg2 <= 2.0) {
		printf("%s\n", "DWU Students RARELY go into town for shopping or leisure");
	}
	else if (avg2 > 2.0 && avg2 <= 3.0) {
		printf("%s\n", "DWU Students SOMETIMES go into town for shopping or leisure");
	}
	else if (avg2 > 3.0 && avg2 <= 4.0) {
		printf("%s\n", "DWU Students OFTEN go into town for shopping or leisure");
	}
	else if (avg2 > 4.0 && avg2 <= 5.0) {
		printf("%s\n", "DWU Students EVERYTIME go into town for shopping or leisure");
	}
	else {
		printf("%s\n", "Question 2 result could not be qualified");
	}
}

//function to summarise question 3 survey result
void surveyQ3Result() {
	printf("%s%.1f%s", "Question 3 rating is ", avg3, ", therefore, ");

	if (avg3 > 0.0 && avg3 <= 1.0) {
		printf("%s\n", "DWU Students NEVER attend church");
	}
	else if (avg3 > 1.0 && avg3 <= 2.0) {
		printf("%s\n", "DWU Students RARELY attend church");
	}
	else if (avg3 > 2.0 && avg3 <= 3.0) {
		printf("%s\n", "DWU Students SOMETIMES attend church");
	}
	else if (avg3 > 3.0 && avg3 <= 4.0) {
		printf("%s\n", "DWU Students OFTEN attend church");
	}
	else if (avg3 > 4.0 && avg3 <= 5.0) {
		printf("%s\n", "DWU Students EVERYTIME attend church");
	}
	else {
		printf("%s\n", "Question 3 result could not be qualified");
	}
}

//function to summarise question 4 survey result
void surveyQ4Result() {
	printf("%s%.1f%s", "Question 4 rating is ", avg4, ", therefore, ");

	if (avg4 > 0.0 && avg4 <= 1.0) {
		printf("%s\n", "DWU Students NEVER eat at the dinning hall");
	}
	else if (avg4 > 1.0 && avg4 <= 2.0) {
		printf("%s\n", "DWU Students RARELY eat at the dinning hall");
	}
	else if (avg4 > 2.0 && avg4 <= 3.0) {
		printf("%s\n", "DWU Students SOMETIMES eat at the dinning hall");
	}
	else if (avg4 > 3.0 && avg4 <= 4.0) {
		printf("%s\n", "DWU Students OFTEN eat at the dinning hall");
	}
	else if (avg4 > 4.0 && avg4 <= 5.0) {
		printf("%s\n", "DWU Students EVERYTIME eat at the dinning hall");
	}
	else {
		printf("%s\n", "Question 4 result could not be qualified");
	}
}

//function to summarise question 5 survey result
void surveyQ5Result() {
	printf("%s%.1f%s", "Question 5 rating is ", avg5, ", therefore, ");

	if (avg5 > 0.0 && avg5 <= 1.0) {
		printf("%s\n", "DWU Students NEVER borrow and read library books");
	}
	else if (avg5 > 1.0 && avg5 <= 2.0) {
		printf("%s\n", "DWU Students RARELY borrow and read library books");
	}
	else if (avg5 > 2.0 && avg5 <= 3.0) {
		printf("%s\n", "DWU Students SOMETIMES borrow and read library bookse");
	}
	else if (avg5 > 3.0 && avg5 <= 4.0) {
		printf("%s\n", "DWU Students OFTEN borrow and read library books");
	}
	else if (avg5 > 4.0 && avg5 <= 5.0) {
		printf("%s\n", "DWU Students EVERYTIME borrow and read library books");
	}
	else {
		printf("%s\n", "Question 5 result could not be qualified");
	}
}