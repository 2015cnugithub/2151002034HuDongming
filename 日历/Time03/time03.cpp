#include <stdio.h>

YDAYS(int year)
{	int	i,n=0;
	int Ydays,sum=0;
	for(i=1990;i<year;i++)
	{	if((i%4==0 && i%100!=0) ||(i%400==0))
		{
			n++;
		}
	}
	Ydays=(year-1990)*365+n;      
	printf("===========Ydays = %d============\n",Ydays);
	return Ydays;
}
MDAYS(int year,int month)
{	
int j,days;
	int Mdays=0;
	for(j=1;j<month;j++)
	{	
if (j==1||j==3 || j==5 || j==7|| j==8|| j==10 || j==12)
	  {
		days=31;	
	   }
	   else if(j==2)
		{
			if(year%4==0 && year%100!=0 ||year%400==0)
			{
				days=29;
			}
			else
			{
			  days=28;
			}
}
		else
			{		
days=30;	
}
	Mdays+=days;
}
return Mdays;	
}

total(int year,int month)
{	int totaldays;
	totaldays= YDAYS(year)+MDAYS(year,month);
	return totaldays;

}

MONTH(int year,int month)
{	
int days;
if (month==1||month==3 || month==5 || month==7|| month==8|| month==10 || month==12)
{
	days=31;	
}
else if(month==2)
{
	if(year%4==0 && year%100!=0 ||year%400==0)
	{
		days=29;
	}
	else
	{
		days=28;
	}
}
else
{		
days=30;	
}
return days;
}

firstDayOfMonth(int year,int month)
{
	int temp,first,totaldays;
	totaldays = total(year,month);
	temp=totaldays%7+1;
	if(temp==7)
		first=0;
	else
		first=temp;
	return first;
}

void print(int year,int month)
{	
	int k,m;
	int totaldays = total(year,month);
	int first = firstDayOfMonth(year,month);
	int days= MONTH(year,month);
	printf("***************************************************\n");
	printf("日\t一\t二\t三\t四\t五\t六\n");
	printf("***************************************************\n");
	for(k=0;k<first;k++)
	{	
		printf("\t");
			}
	for(m=1;m<=days;m++)
	{
		if(1+(totaldays+m-1)%7==6)
		{
			printf("%d\n",m);
		 }
		else
			printf("%d\t",m);
	}
	printf("***************************************************\n");
}
void main()
{	
	int year,month;
	printf("请输入要查询的年份和月份：");
	scanf("%d%d",&year,&month);
	print(year,month);
	
}
