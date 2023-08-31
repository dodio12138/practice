#include <stdio.h>
#include <malloc.h>

struct stu
{
    /* data */
    int num;
    float score;
    struct stu *next;
};

struct stu *creat();              // ��������
struct stu *print(struct stu *p); // ��ӡ����
struct stu *find(struct stu *p);  // ��ѯ����
struct stu *sort(struct stu *p);  // �ɼ�����
struct stu *cut(struct stu *p);   // ɾ������
struct stu *add(struct stu *p);   // ��������
void menu();                      // �˵� ���û�����
void files(struct stu *p);        // �ļ�����
void file_p(struct stu *p);       // �ļ���
// void game1(); //������Ϸ
int n;

int main()
{
    menu();
    return 0;
}

struct stu *creat()
{
    printf("�����ѧ������0,��¼�����\n");
    struct stu *n1, *n2, *head;
    n = 0;
    head = NULL;
    n1 = n2 = (struct stu *)malloc(sizeof(struct stu));
    printf("please enter number:");
    scanf("%d", &n1->num);
    printf("please enter score:");
    scanf("%f", &n1->score);
    printf("\n\n");

    while (n1->num)
    {
        n++;
        if (n == 1)
        {
            head = n1;
        }
        else
        {
            n2->next = n1;
        }
        n1 = (struct stu *)malloc(sizeof(struct stu));
        n2 = n1;
        printf("please enter number:");
        scanf("%d", &n1->num);
        printf("please enter score:");
        scanf("%f", &n1->score);
        printf("\n\n");
    }
    n2->next = NULL;
    return head;
}
struct stu *print(struct stu *p)
{
    struct stu *head;
    head = p;
    n = 0;
    printf("�������\n\n");

    while (p)
    {
        printf("ѧ��Ϊ%d��ѧ���ɼ���%f\n", p->num, p->score);
        p = p->next;
        n++;
    }
    printf("\n\n");
    return head;
}
struct stu *find(struct stu*p)
{
	int a,k=0;
	struct stu*head,*i;
	i=head=p;
	printf("������ѯ������0����ѯ����������ѧ�ţ�");
	scanf("%d",&a);
	while(a!=0)
	{
		if(k!=0)
        {
		    printf("������ѯ������0��������ѯ����������ѧ�ţ�");
	        scanf("%d",&a);
     	}
	        if(a==0)
	        {
	        	goto end1;
			}else
            {
        	    if(a==p->num)
                {
        	       goto print;
		        }else
		        {
			        while(a!=p->num)//�ҳ�������� 
	                {
	        	        if(p->next)
	        	        {
			               p=p->next;
		                }else
		                {
			               printf("û�����ѧ��\n�˳�������0����������������:");//��ֹ���� 
			               scanf("%d",&a);
			               if(a==0)
					       {
					   	       goto end1;
						   } 
			               p=head;
		                }  
                    }
	    	    }
		    }
        
            print: printf("ѧ��Ϊ%d��ѧ���ɼ���%f!\n",p->num,p->score);
            k++;
            p=head;
        }
        end1:printf("");
        return i;
    }
struct stu *sort(struct stu*p)
{
	printf("�ɼ��ɸߵ�������:\n");
	struct stu *i,*q;
	int a;
	float b;
	q=p;
	while(p)
	{
	    i=p->next; 
	    while(i)
	    {    
		    if(i->score>p->score)//����ֵ 
	  	    {
			    b=i->score;
			    i->score=p->score;
			    p->score=b;
			    a=i->num;
			    i->num=p->num;
			    p->num=a;
		    }
		    i=i->next;
        }
        p=p->next;
    } 
    print(q);
    return q;
}	
struct stu *cut(struct stu*p)
{
	int a,m=0,k;
	struct stu *i,*j,*head;
	head=i=j=p;
	printf("��������������0����������������ɾ����ѧ�ţ�");
	scanf("%d",&a);
	printf("\n");
	if(a==0)
	{
		goto end4;
	}else
	 {
	cut:while(a!=0)//ѭ��Ϊ�˶��ɾ�� 
	 	{
	 	if(a==p->num)
	       {
		     p=p->next;
		    head=p;
	       }else
	       {  
	 	        while(p->num!=a)//����������� 
               	{
		            if(p->next)
		            {
		            	p=p->next;
	             	}else
		            {
		            	p=head;
		            	if(a!=p->num)
		            	{
		                 	m=-1;
			                printf("�Բ���û�����ѧ����������������0������������������: ");//���� 
			                scanf("%d",&a);
			            }
			            if(a==p->num)
			            {
			            	goto cut;
						}
			            if(a==0)
						{
							goto end4;
						 } 
		            }
		            m++;
                }
                i=j=p=head;//��p����ָ���ͷ 
                for(k=0;k<m-1;k++)
                {
                	j=j->next;
				}
				for(k=0;k<m+1;k++)
				{
					i=i->next;
				}
				m=0;
				j->next=i;
				i=j=head;    
	        } 
	 	    printf("��������������0����������������ɾ����ѧ�ţ�");
	        scanf("%d",&a);
	         printf("\n");	
		}
	    end4:print(head);
	     return head;
	}
	
	while(a<=0)
	{
		printf("û�����ѧ�������������룺");
		scanf("%d",&a);
		printf("\n"); 
	}
	
 }
 struct stu *add(struct stu*p) 
 {
 	int a,c;
 	struct stu *i,*j,*head;
 	head=p;
 	printf("����������Ϣ��ѧ������0�����������벻Ϊ0��ѧ�ţ�\n"); 
 	i=(struct stu*)malloc(sizeof(struct stu));
	scanf("%d",&i->num);
	if(i->num==0)
	{
		goto end3;
	 } else
	  {
	      while(i->num!=0)//ѭ��Ϊ�˶��������� 
          {  
	            printf("������ɼ�:");
	            scanf("%f",&i->score);
	            printf("�������Ѹ�ѧ�����ڿ�ͷ������c=0,�������������c=1\nc=");//�Ƿ��������ͷ 
	            scanf("%d",&c);
	            if(c==0)
	            {
		             i->next=p;
		             head=i;
		             p=i;
	            }else
	            {
	                 printf("����ѡ������ĸ�ѧ���ĺ��棬����������ѧ�ţ�");
                     scanf("%d",&a);
                     while(p->num!=a)//Ѱ��������� 
	                 {
		                  if(p->next)
		                  {
			                  p=p->next;
		                  }else
		                  {
			                    printf("�Բ���û�����ѧ������������0����������������: ");//���� 
		                     	scanf("%d",&a);
			                    if(a==0)
			                    {
				                    goto end3;
			                    } 
			                    p=head;
		                  }
	               }
	               j=p->next;
	               p->next=i;
	               i->next=j;
                } 
	            printf("����������Ϣ��ѧ������0�����������벻Ϊ0��ѧ�ţ�\n"); 
 	            i=(struct stu*)malloc(sizeof(struct stu));
 	            scanf("%d",&i->num);
            }
	         end3:print(head);
        }
        return head;
   }
 void menu()
 {
 	int i,h,k=0;
 	struct stu*j;
 	printf("��ӭ�������bug�ܶ��ϵͳ��\n\n");//�û�ָ�� 
 	printf("����¼����Ϣ������1\n\n������ʾ��¼����Ϣ������2\n\n�����޸ģ�ɾ����ĳ��ѧ������Ϣ����ʾ������3\n\n");
 	printf("�����޸ģ����ӣ���Ϣ����ʾ������4\n\n�����ѯĳһ��ѧ���ĳɼ�������5\n\n����ɼ�����������6���ɴ�С��\n\n�ǳ�ϵͳ������0\n\n");
    printf("��ѡ������Ҫ�Ĳ�����");
 	scanf("%d",&i);
 	while(i!=0)
 	{
 		if(k==0 && i!=1)
		 {
 			while(i!=1)
 			{
 				printf("����¼����Ϣѡ��1¼����Ϣ���ܽ�������Ĳ�����");
				 scanf("%d",&i); 
				 if(i==0)
				 goto end;//����ѭ�� 
			 }
		 }switch(i)
		{
	        case 1:j=creat();break;//�з���ֵ����Ϊÿ�ε��ò�ͬ������������������������ͬ 
		    case 2:j=print(j);break;
		    case 3:j=cut(j);break;
		    case 4:j=add(j);break;
		    case 5:j=find(j);break;
		    case 6:j=sort(j);break;
	   }
		 printf("�����������Ӧ�������֣��ǳ�ϵͳ������0��"); 
		 scanf("%d",&i); 
	     printf("\n");
		 k++;
	 }
	end: printf("��ϲ���˳����������bug��ϵͳ��\n\n");
	     files(j);
	     printf("������Ϣ���Ա��棬����Ҫ���ļ�������1������������0��");
	     scanf("%d",&h);
		 if(h==1)
		 {
		 	file_p(j);
		  } 
		 printf("����������лл����ʹ��!"); 
		  
  } 
 
 void files(struct stu*p)
 {
 	
 	char fname[30];
 	FILE *i;
 	int a;
 	printf("�����������ݱ�����ļ�������ַ��");
	scanf("%s",&fname); 
	if(!(i=fopen(fname,"w+")))
	{
		printf("��Ϊ��������%s�ļ�\n\n",fname);
	}else
	{
		printf("�ļ������ɹ���������Ϣ�����浽�ļ�%s��\n\n",fname);
	} 
	for(a=0;a<n;a++)
 	{
 		fwrite(p,sizeof(struct stu),1,i);
 		p=p->next;
	 }
	 fclose(i);
  } 
  void file_p(struct stu*p)
 {
 	
 	char fname[30];
 	FILE *i;
 	int a;
 	printf("����������Ҫ�򿪵��ļ�������ַ��");
	scanf("%s",&fname); 
	if(!(i=fopen(fname,"r+")))
	{
		printf("�Բ���û������ļ�������Ϊ��������%s�ļ�\n\n",fname);
	}else
	{
		printf("�ļ�%s�򿪳ɹ���\n\n",fname);
	} 
	printf("\t\tѧ��ѧ��\tѧ���ɼ�\n");
	for(a=0;a<n;a++)
 	{
 		fread(p,sizeof(struct stu),1,i);
 		printf("\t\t%d\t\t%f\n",p->num,p->score);
 		p->next=p;
	 }
	 fclose(i);
  } 