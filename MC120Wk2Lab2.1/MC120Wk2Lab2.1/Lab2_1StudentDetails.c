//Created by Jerome Kris Semos
//CopyRight MCS department (2022) 
//MC120 Lab2.1 Basic student details (ID Number, fullname & program of study)

#include <stdio.h>

//declared variables
char str_id[10] = "ID# 1111";
char str_name[50] = "Jerome Kris Semos";
char str_program[100] = "Mathematics and Computer Science";


//function main begins program execution
int main(void)
{
	printf("ID# 1111 \n");
	printf("Jerome Kris Semos \n");
	printf("Mathematics and Computer Science\n\n");


	printf("Output from declared variables\n");
	printf("%s\n%s\n%s\n", str_id, str_name, str_program);

} //end function main