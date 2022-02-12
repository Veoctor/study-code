#include<stdio.h>
#define N 200//最大人数   
//now记录当前存储的学生数量  
int now=0;               
struct student
{
 int num;
 char name[10];
 float score[3];
 float sum;
 float aver;
 int n;
}stu[N];
struct student *p;

 void input();//学生信息录入
 void sort();//按成绩排序
 void update();//修改成绩
 void search();//按学号查询成绩
 void output();//按班级输出学生信息
 void lofstudent();//不及格学生名单
 void menu();//显示系统主菜单函数

//主函数
void main(void)
{
   
	int op;//operation
	menu();
    scanf("%d",&op);     
	while(op!=0)
	{
		switch(op)
		{		  
		  case 1:
				input();
				break;
		  case 2:
				sort();
				output();
				break;
		  case 3:
				update();
				break;
		  case 4:
				search();
				break;
		  case 5:
				lofstudent();
				break;
		  default:printf("没有此选项，请重新输入!");
		}
       	menu();
       scanf("%d",&op);
	}
}

//显示系统主菜单函数
void menu()  
{
     printf("               学生信息管理系统           \n");
	 printf("   *************************************  \n");
	 printf("   *  0:退出       1 :输入学生信息     *  \n");
	 printf("   *  2:输出信息   3 :修改信息         *  \n");
	 printf("   *  4:查询成绩   5 :不及格科目及名单 *  \n");
	 printf("   *************************************  \n");
}


//学生信息录入
void input()                                   
{ 
 char ch;
 int i=0,j=0; 
 printf("请输入班级人数：");
 scanf("%d",&now);
 for(p = stu;p<stu + now;p++)
 { 
   printf("请输入学号：  ");
   scanf("%d",&p->num);
   getchar();
   printf("请输入姓名： ");
   scanf("%s",&p->name);
   getchar();
   printf("请输入3门课程的分数（分别为数学，英语，物理）：");
   scanf("%f,%f,%f",&(p->score[0]),&(p->score[1]),&(p->score[2]));
   getchar();
   for(j=0;j<3;j++)
   {	
	   (p->sum)=(p->score[0])+(p->score[1])+(p->score[2]);    
	   //每个学生的平均分
	   (p->aver)=(p->sum)/(float)3.0;                         
   }
 }
}


//按班级输出学生信息
void output()
{
 int i;
 printf("学号\t姓名\t数 学  英 语  物 理  总分  平均分	名次\n");
 for(p=stu;p<stu+now;p++)
  {
   {  //打印学生信息
    printf("%d\t%s\t%5.2f  %5.2f  %5.2f  %5.2f  %5.2f	%2d\n",(p->num),(p->name),(p->score[0]),(p->score[1]),(p->score[2]),(p->sum),(p->aver),(p->n)); 
   }
  }
}

//修改成绩
void update()
{
 int num,j;
 printf("要修改学生的学号");
 scanf("%d",&num);
 for(j=0;j<now;j++)
 if(stu[j].num==num) break;
 if(j<now)
  {  
   printf(" 请输入要修改数学成绩:");
   scanf("%f",&stu[j].score[0]);
   printf(" 请输入要修改英语成绩:");
   scanf("%f",&stu[j].score[1]);
   printf(" 请输入要修改物理成绩:");
   scanf("%f",&stu[j].score[2]);
   //重新求每个学生的总分
   stu[j].sum=stu[j].score[0]+stu[j].score[1]+stu[j].score[2];    
   //重新求每个学生的平均分
   stu[j].aver=stu[j].sum/(float)3.0;  
  }
 else printf("没有找到该学生的信息\n");
}

//对学生按平均分的高低排序
void sort()                 
{
 struct student p;
 int k,i,j; 
 for(i=0;i<now;i++)
 {
	stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];    
	stu[i].aver=stu[i].sum/(float)3.0;                                                
 }

	for(i=0;i<now-1;i++)                                       
	{   
	 	k=i;
		for(j=i+1;j<now;j++)
		  {
			if(stu[j].aver>stu[k].aver)
				k=j;
		  }                                                   
		if(k!=i)
		{
		 	p=stu[i];
			stu[i]=stu[k];
			stu[k]=p;
		}
	}
for(int i=0;i<now;i++)
{
	stu[i].n = i + 1;
}
}
 
//按学号查询成绩
void search()                                  
{
 int num,i;
 printf("请输入要查询的学号");
 scanf("%d",&num);
 printf("姓名\t   数 学  英 语 物 理  总分  平均分\n"); 
 for(i=0;i<now;i++) 
 if(stu[i].num==num)break;
 if(i<now)
 {
  printf("%s\t   %5.2f %5.2f  %5.2f  %5.2f  %5.2f\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].aver);
 }
 else printf("不存在该学生\n");
}



//不及格学生名单
void lofstudent()
{    
   int n,i;
   printf("请输入要查看的课程编号(默认：1 数学  2 英语  3 物理):");
   scanf("%d",&n);
   printf("***************成绩不及格学生信息如下************\n\n");  
   printf("学号     姓名   课程%d\n",n);  
   //此处是用数组存放的课程，数组最大下标为3，因此需要-1
   n--;
   for(i=0;i<now;i++) 
   {
	 //输出不及格学生名单及成绩 
     if(stu[i].score[n]<60)             
		 printf("%d\t%s\t%3.1f\n",stu[i].num,stu[i].name,stu[i].score[n]);
   }
}
