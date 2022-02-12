#include<stdio.h>
#define N 200//�������   
//now��¼��ǰ�洢��ѧ������  
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

 void input();//ѧ����Ϣ¼��
 void sort();//���ɼ�����
 void update();//�޸ĳɼ�
 void search();//��ѧ�Ų�ѯ�ɼ�
 void output();//���༶���ѧ����Ϣ
 void lofstudent();//������ѧ������
 void menu();//��ʾϵͳ���˵�����

//������
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
		  default:printf("û�д�ѡ�����������!");
		}
       	menu();
       scanf("%d",&op);
	}
}

//��ʾϵͳ���˵�����
void menu()  
{
     printf("               ѧ����Ϣ����ϵͳ           \n");
	 printf("   *************************************  \n");
	 printf("   *  0:�˳�       1 :����ѧ����Ϣ     *  \n");
	 printf("   *  2:�����Ϣ   3 :�޸���Ϣ         *  \n");
	 printf("   *  4:��ѯ�ɼ�   5 :�������Ŀ������ *  \n");
	 printf("   *************************************  \n");
}


//ѧ����Ϣ¼��
void input()                                   
{ 
 char ch;
 int i=0,j=0; 
 printf("������༶������");
 scanf("%d",&now);
 for(p = stu;p<stu + now;p++)
 { 
   printf("������ѧ�ţ�  ");
   scanf("%d",&p->num);
   getchar();
   printf("������������ ");
   scanf("%s",&p->name);
   getchar();
   printf("������3�ſγ̵ķ������ֱ�Ϊ��ѧ��Ӣ�������");
   scanf("%f,%f,%f",&(p->score[0]),&(p->score[1]),&(p->score[2]));
   getchar();
   for(j=0;j<3;j++)
   {	
	   (p->sum)=(p->score[0])+(p->score[1])+(p->score[2]);    
	   //ÿ��ѧ����ƽ����
	   (p->aver)=(p->sum)/(float)3.0;                         
   }
 }
}


//���༶���ѧ����Ϣ
void output()
{
 int i;
 printf("ѧ��\t����\t�� ѧ  Ӣ ��  �� ��  �ܷ�  ƽ����	����\n");
 for(p=stu;p<stu+now;p++)
  {
   {  //��ӡѧ����Ϣ
    printf("%d\t%s\t%5.2f  %5.2f  %5.2f  %5.2f  %5.2f	%2d\n",(p->num),(p->name),(p->score[0]),(p->score[1]),(p->score[2]),(p->sum),(p->aver),(p->n)); 
   }
  }
}

//�޸ĳɼ�
void update()
{
 int num,j;
 printf("Ҫ�޸�ѧ����ѧ��");
 scanf("%d",&num);
 for(j=0;j<now;j++)
 if(stu[j].num==num) break;
 if(j<now)
  {  
   printf(" ������Ҫ�޸���ѧ�ɼ�:");
   scanf("%f",&stu[j].score[0]);
   printf(" ������Ҫ�޸�Ӣ��ɼ�:");
   scanf("%f",&stu[j].score[1]);
   printf(" ������Ҫ�޸�����ɼ�:");
   scanf("%f",&stu[j].score[2]);
   //������ÿ��ѧ�����ܷ�
   stu[j].sum=stu[j].score[0]+stu[j].score[1]+stu[j].score[2];    
   //������ÿ��ѧ����ƽ����
   stu[j].aver=stu[j].sum/(float)3.0;  
  }
 else printf("û���ҵ���ѧ������Ϣ\n");
}

//��ѧ����ƽ���ֵĸߵ�����
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
 
//��ѧ�Ų�ѯ�ɼ�
void search()                                  
{
 int num,i;
 printf("������Ҫ��ѯ��ѧ��");
 scanf("%d",&num);
 printf("����\t   �� ѧ  Ӣ �� �� ��  �ܷ�  ƽ����\n"); 
 for(i=0;i<now;i++) 
 if(stu[i].num==num)break;
 if(i<now)
 {
  printf("%s\t   %5.2f %5.2f  %5.2f  %5.2f  %5.2f\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].aver);
 }
 else printf("�����ڸ�ѧ��\n");
}



//������ѧ������
void lofstudent()
{    
   int n,i;
   printf("������Ҫ�鿴�Ŀγ̱��(Ĭ�ϣ�1 ��ѧ  2 Ӣ��  3 ����):");
   scanf("%d",&n);
   printf("***************�ɼ�������ѧ����Ϣ����************\n\n");  
   printf("ѧ��     ����   �γ�%d\n",n);  
   //�˴����������ŵĿγ̣���������±�Ϊ3�������Ҫ-1
   n--;
   for(i=0;i<now;i++) 
   {
	 //���������ѧ���������ɼ� 
     if(stu[i].score[n]<60)             
		 printf("%d\t%s\t%3.1f\n",stu[i].num,stu[i].name,stu[i].score[n]);
   }
}
