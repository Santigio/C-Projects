#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
 
int isItNum(char str[20])
{
	int i,j,k,flag=1;
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]>='0'&&str[i]<='9')||(str[i]=='.'))
		{}
		else
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int t,i1,j1,i2,j2,k,l,m,n,row,col,i,j;
	double isSpreadsheet[10][10]={0}; 
    /*This code instantiate a matrix to store the integer values entered by the user and the values computed as result of formula
     The actual isSpreadsheet which stores the content to be displayed
	*/
    char isSheet[10][10][20]={0};	
	int flag[10][10]={0};								
	char input[20];										
	char cellNum[4];									 
	char *subVal;
	for(i=0;i<=9;i++)										
		for(j=0;j<=9;j++)
			{
				if(i==0&&j!=0)
					isSheet[i][j][0]='A'+j-1;
				else
				if(i!=0 && j==0)
				    isSheet[i][j][0] = '0'+i;
				else
				if(i==0&&j==0)
				 isSheet[i][j][0]='\0';
				 else
				 isSheet[i][j][0]='_';
			}
	while(1)  		
    // THis code instantiate an infinite loop to take input till user quit									
	{
	 double sum=0,avg=0;
	 int maxim=INT_MIN,min = INT_MAX,cnt =0;
	 printf("\nEnter the isSpreadsheet cell number :  ");
	 scanf("%s",cellNum);
	 
	 if(cellNum[0]>='A' && cellNum[0]<='Z')
	 col = cellNum[0]-'A'+1;
	 else
	 col = cellNum[0] - 'a'+1;							
     // This code extract the row and column number from cell number
	 row = cellNum[1] - '1'+1;
	 if(row>9 || row<0 || col>9 || col<0)
	 {
	 	printf("\n You enter invalid cell number \n");
	 	continue;
	 }
	 printf("\nEnter a value(num, letter, etc) to be inserted  :  ");		
	 scanf("%s",input);
	 if(strstr(input,"AVERAGE")!= NULL )					
     // THis code check if user entered the formula : AVERAGE( , )
	 {
	 subVal = strstr(input,"(");
	 if(subVal ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(subVal+1) >= 'A' && *(subVal+1) <= 'Z')
 		j1= *(subVal+1)-'A'+1;
 		else
 		j1= *(subVal+1) - 'a'+1;
 		
 		i1 = *(subVal+2)-'1'+1;
 		
 		subVal=subVal+4;
 		
 		if(*subVal >= 'A'&& *subVal <='Z')
 		j2= *subVal - 'A'+1;
 		else
 		j2= *subVal - 'a'+1;
 		
 		i2 = *(subVal+1)-'1'+1;
 		if(i2 == i1)
 		{
 		 for(j=j1;j<=j2;j++)
 		 {
 		 	if(flag[i1][j] == 1)
 		 	{
 		 		avg+=isSpreadsheet[i1][j];
 		 		cnt++;
 		 	}
 
 		 }
 
 		}
 		if(j2 == j1)
 		{
 			for(i=i1;i<=i2;i++)
 		 {
 		 	if(flag[i][j1] == 1)
 		 	{
 		 		avg+=isSpreadsheet[i][j1];
 		 		cnt++;
 		 	}
 
 		 }
 		}
 	  isSpreadsheet[row][col] = avg/cnt;
	  sprintf(isSheet[row][col],"%.2f",isSpreadsheet[row][col]);				
	  if(strlen(isSheet[row][col])>6)
	  		{
	  		isSheet[row][col][6]='.';
 	    	isSheet[row][col][7]='.';
 	    	isSheet[row][col][8]='\0';
	  		}
	  
	  }
 
	 }
	 else
	 if(strstr(input,"SUM") != NULL)						
     // This code check if the user entered the formula  : SUM( , )
	 {
 
	 	subVal = strstr(input,"(");
	 if(subVal ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(subVal+1) >= 'A' && *(subVal+1) <= 'Z')
 		j1= *(subVal+1)-'A'+1;
 		else
 		j1= *(subVal+1) - 'a'+1;
 		
 		i1 = *(subVal+2)-'1'+1;
 		
 		subVal=subVal+4;
 		
 		if(*subVal >= 'A'&& *subVal <='Z')
 		j2= *subVal - 'A'+1;
 		else
 		j2= *subVal - 'a'+1;
 		
 		i2 = *(subVal+1)-'1'+1;
 		if(i2 == i1)
 		{
 		 for(j=j1;j<=j2;j++)
 		 {
 		 	if(flag[i1][j] == 1)
 		 	{
 		 		sum+=isSpreadsheet[i1][j];
 		 		cnt++;
 		 	}
 
 		 }
 
 		}
 		if(j2 == j1)
 		{
 			for(i=i1;i<=i2;i++)
 		 {
 		 	if(flag[i][j1] == 1)
 		 	{
 		 		sum+=isSpreadsheet[i][j1];
 		 		cnt++;
 		 	}
 
 		 }
 		}
 	  isSpreadsheet[row][col] = sum;
	  sprintf(isSheet[row][col],"%.2f",isSpreadsheet[row][col]);         
      // This code insert the result into the cell
	  if(strlen(isSheet[row][col])>6)
	  		{
	  		isSheet[row][col][6]='.';
 	    	isSheet[row][col][7]='.';
 	    	isSheet[row][col][8]='\0';
	  		}
 
	  }
 
	 }
	 else
	 if(strstr(input,"RANGE") != NULL)						
     // This code check if the user entered formula : RANGE( , )
	 {
	 subVal = strstr(input,"(");
	 if(subVal ==NULL)
	 printf("Wrong input");
	  else
	  {
 		if(*(subVal+1) >= 'A' && *(subVal+1) <= 'Z')
 		j1= *(subVal+1)-'A'+1;
 		else
 		j1= *(subVal+1) - 'a'+1;
 		
 		i1 = *(subVal+2)-'1'+1;
 		
 		subVal=subVal+4;
 		
 		if(*subVal >= 'A'&& *subVal <='Z')
 		j2= *subVal - 'A'+1;
 		else
 		j2= *subVal - 'a'+1;
 		
 		i2 = *(subVal+1)-'1'+1;
 
 
 		if(i1 == i2)
 		{
 			for(j=j1;j<=j2;j++)
 			{
 				if(flag[i1][j] == 1 && maxim<isSpreadsheet[i1][j])
 					maxim = isSpreadsheet[i1][j];
 				if(flag[i1][j] == 1 && min > isSpreadsheet[i1][j])
 					min = isSpreadsheet[i1][j];
 			}
 		}
 		if(j1 == j2)
 		{
 			for(i=i1;i<=i2;i++)
 			{
 				if(flag[i][j1] == 1 && maxim < isSpreadsheet[i][j1])
 					maxim = isSpreadsheet[i][j1];
 				if(flag[i][j1] == 1 && min > isSpreadsheet[i][j1])
 					min = isSpreadsheet[i][j1];
 
 			}
 
 		}
 		isSpreadsheet[row][col] = maxim-min;
 		sprintf(isSheet[row][col],"%.2f",isSpreadsheet[row][col]);								
         // This code Insert the result into the cell
 	    if(strlen(isSheet[row][col])>6)
	  		{
	  		isSheet[row][col][6]='.';
 	    	isSheet[row][col][7]='.';
 	    	isSheet[row][col][8]='\0';
	  		}
	 }
	}
	 else if(isItNum(input))											
     // This code check if the value entered by the user is a number
	 {
	  isSpreadsheet[row][col] = atoi(input);
	  flag[row][col] = 1;
	  strcpy(isSheet[row][col],input);
	  if(strlen(isSheet[row][col])>6)
	  		{
	  		isSheet[row][col][6]='.';
 	    	isSheet[row][col][7]='.';
 	    	isSheet[row][col][8]='\0';
	  		}
	 }
	 else
	 {
	 	strcpy(isSheet[row][col],input);					
         // This code check if value entered is text, then insert the text into the cell
	 	if(strlen(isSheet[row][col])>6)
	  		{
	  		isSheet[row][col][6]='.';
 	    	isSheet[row][col][7]='.';
 	    	isSheet[row][col][8]='\0';
	  		}
	 }
	 
	 for(i=0;i<=9;i++)
	 {
	 	for(j=0;j<=9;j++)
	 		printf("%8s   ",isSheet[i][j]);
	 	printf("\n");
	 }
 
	 printf("\n\n Previous input  :  Cell Number : %s , Value : %s\n\n",cellNum,input);
	}
	return 0;

    }

 
 		

		 

