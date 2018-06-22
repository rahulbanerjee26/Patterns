#include <stdio.h>
#include <math.h>


/*
 
 INPUT : 5 
 Half of a Square
 #####
 ####
 ###
 ##
 #

 */

void pattern1(){
	int rows;
	printf("Enter the number of Rows\n");
	scanf("%d",&rows);
	int i,j;
	for(i=rows;i>0;i--){
		for(j=1;j<=i;j++)
			printf("#");
		printf("\n");
	}
	if(rows<=0)
	printf("Error! Input a correct number");
}

/*
 
 INPUT : 5 
 Square
 #####
 #####
 #####
 #####
 #####

*/

void pattern2(){
	int rows;
	printf("Enter the number of Rows\n");
	scanf("%d",&rows);
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<rows;j++)
			printf("#");
		printf("\n");
	}
	if(rows<=0)
	printf("Error! Input a correct number");
	double sqrt=pow(rows,.5);
	printf("The square root of the number is %.5lf\n",sqrt);
}

/*
 
  INPUT: 5 
  Sideways Triangle 
 #
 ##
 ###
 ##
 #

 */
 
void pattern3(){
	printf("Enter the number of Rows\n");
	int rows;
	scanf("%d",&rows);
	int i,j;
	for(i=1;i<=rows;i++){
		for(j=1;j<=rows/2+1-abs(rows/2+1-i);j++)
			printf("#"); 
		printf("\n");
	}
}

/*
 
  Enter the number of rows in the triangle: 5
    ^
   ^ ^
  ^   ^
 ^     ^
^^^^^^^^^

*/

void pattern4(){
	int rows;
	int i,j,k,a,b;
    printf("Enter the number of rows in the triangle: ");
	scanf("%d",&rows);
	
	//Top Row
	for(i=1;i<rows;i++){
		printf(" ");
	}
	printf("^\n");
	
	//Middle Row
	if(rows>1){
	    
		for(b=1;b<rows-1;b++){
		
			for(j=rows-b-1;j>0;j--){ //space before first ^ 
				printf(" ");
				}
		
			printf("^"); // first ^
		
			for(a=1;a<=2*b-1;a++){ //space between the two ^
				printf(" ");
			}
		
			printf("^ \n"); // end ^
		}
		
		//last row
		for(k=0;k<2*rows-1;k++){
			printf("^");
		}			
	}
	printf("\n");

}

/*

 Enter the number of rows: 5
            1
         1     1
      1     2     1
   1     3     3     1
1     4     6     4     1
 
*/

//Factorial Function
int factorial(int n){

	int factorialresult=1;int i;

	if(n==0){

		factorialresult=1;

	}

	else{

		for(i=n;i>0;i--){

			factorialresult=factorialresult*i;

		}

	return factorialresult;

	}

}


//Fubction to find computation
int chose(int r,int n){

	int computation;

	if(r==n){

		computation=1;

	}

	else if(r==0&&n!=0){

		computation=1;

	}

	else{

		computation=factorial(n)/( factorial(r)*factorial(n-r));

	}

	return  computation;

}


//Function to assign spaces
int space(int rowNumber){

	int i;

	for(i=1;i<=3*(rowNumber-1);i++){

		printf(" ");

	}

	return 0;

}

//Function to generate the triangles
void triangle(int numberOfRows){

	int rowNumber;

	for(rowNumber=0;rowNumber<numberOfRows;rowNumber++){

		space(numberOfRows-rowNumber);

		int colummNumber;

		for(colummNumber=rowNumber;colummNumber>=0;colummNumber--){

			int d=chose(colummNumber,rowNumber);
            //6 spaces reserved for each number
			if(d>100){

				printf("%d   ",d);

			}

			else if(d>=10){

				printf("%d    ",d);

			}

			else{

				printf("%d     ",d);

			}

		}

		printf("\n");

	}

}

int pattern5(){

	int rows;

	printf("Enter the number of rows: ");

	scanf("%d",&rows);

	while(rows>=0&&rows<=13){ //Assuming max number of rows is 13

		triangle(rows);

		printf("Enter the number of rows: ");

		scanf("%d",&rows);

	}

	return 0;

}

int main(int argc, char **argv)
{
	pattern5();
	return 0;
}
