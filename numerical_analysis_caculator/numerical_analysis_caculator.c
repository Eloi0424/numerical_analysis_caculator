#include <stdio.h>
#include <stdlib.h>
//ͷ�ļ�
const int MAX=10;
int NUM;
//�궨�����
//void input_data();
void Equal_Newton_interpolation();
void Unequal_Newton_interpolation();
void Lagrange_interpolation();
void Hermite_interpolation();
void cubic_spline_interpolation();
void ordinary_least_squares_techniques();
void least_squares_approximation();
//��������
int main()
{
    
    int x;
//    input_data();
    printf("��ѡ���ֵ����ϣ�1.��ֵ 2.��� :");
    scanf("%d",&x);
    if(x==1)
    {
        printf("��ѡ���ֵ���ͣ�1.Newton��ֵ 2.Lagrange��ֵ 3.Hermite��ֵ 4.cubic spline ��ֵ :");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
            printf("��ѡ��Newton��ֵ���ͣ�1.�Ⱦ�ڵ� 2.�ǵȾ�ڵ�  :");
            scanf("%d",&x);
            if(x==1)
			{
				Equal_Newton_interpolation();
			}
			else Unequal_Newton_interpolation();
            break;

            case 2:
            Lagrange_interpolation();
            break;

            case 3:
//            Hermite_interpolation();
            break;

            case 4:
//            cubic_spline_interpolation();
            break;

            default:
            printf("�������");
            break;
        }
    }
    if(x==2)
    {
        printf("��ѡ��������ͣ�1.ordinary least squares techniques��� 2.least squares approximation��ֵ :");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
//            ordinary_least_squares_techniques();
            break;

            case 2:
//            least_squares_approximation();
            break;

            default:
            printf("�������");
            break;
        }
    }
    return 0;
}
/*
void input_data()
{
    printf("������������\n");
    printf("N = ");
    scanf("%d",&NUM);
    printf("���������ݵ�\n");
    printf("ÿ��һ�����ݵ�\n");
    for(int i=1;i<=NUM;i++)
    {
        scanf("%d%d",&X[i],&Y[i]);
    }
}
*/
void Equal_Newton_interpolation()
{
	int n;
	double *x,*y,*f,h,t;
	printf("�����벽���������ڵ�֮��ľ��룩:");
	scanf("%lf",&h);
	printf("�������ֵ�ڵ�ĸ�����");
	scanf("%d",&n);
	x=(double*)malloc(sizeof(double)*n);
	y=(double*)malloc(sizeof(double)*n);
	f=(double*)malloc(sizeof(double)*n*(n-1)/2);
	int i;
	int j;
	int k;
	i=0;k=0;
	while(n>i)
	{
		printf("x[%d]:",i);
		scanf("%lf",&x[i]);
		printf("y[%d]:",i);
		scanf("%lf",&y[i]);
		i++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(i==0)
			{
				f[k]=y[j+1]-y[j];//����һ�ײ�� 
				k++;
			}
			else
			{
				f[k]=f[k+1+i-n]-f[k+i-n];
				k++;
			}
		}
	}
	i=0;
	j=0;
	k=0;
	printf("��ֱ�\n");
	printf("x\t ");
	for(i=0;i<n;i++)
	{
		printf("f[x%d]      ",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("------------");
	}
	printf("\n");
	for(i=0;i<n;i++)//��ӡ��ֱ� 
	{
		printf("%-10g  %-10g",x[i],y[i]);
		k=i-1;
		for(j=0;j<i;j++)	
		{
			printf("%     -10g",f[k]);
			k+=n-2-j;
		}
		if(i==j)
		{
			printf("\n");
		}
		
	}
	i=0;
	k=0;
	double a,*b;
	printf("���������ڵ��ֵ��");
	scanf("%lf",&a);
	b=(double*)malloc(sizeof(double)*n);
	t=(a-x[0])/h;
	b[0]=1.0;
	for(i=0;i<n-1;i++)
	{
		b[i+1]=(b[i]*(t-i))/(i+1);
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			a=y[i]*b[i];
		}
		else
		{
			a+=b[i]*f[k];
			k=k+n-i;
		}
	}
	printf("��ֵ�ڵ��Ӧ��YֵΪ��%g\n",a);	
}
void Unequal_Newton_interpolation()
{
	int n;
	double *x,*y,*f;
	printf("�������ֵ�ڵ�ĸ�����");
	scanf("%d",&n);
	x=(double*)malloc(sizeof(double) *n);
	y=(double*)malloc(sizeof(double) *n);
	f=(double*)malloc(sizeof(double) *(n-1)*n/2);
	int i,j,k;
	i=0;
	k=0;
	while(n>i)//�����ݽ������� 
	{
		printf("x[%d]:",i);
		scanf("%lf",&x[i]);
		printf("y[%d]:",i);
		scanf("%lf",&y[i]);
		i++;
	}
	i=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(i==0)
			{
				f[k]=(y[j+1]-y[j])/(x[j+1]-x[j]);//����һ�ײ��� 
				k++;
			}
			else
			{
				f[k]=(f[k+i-n+1]-f[k+i-n])/(x[j+1+i]-x[j]);//������׼����ϲ��� 
				k++;	
			}
		}
	}
	i=0;
	j=0;
	k=0;
	printf("���̱�\n");
	printf("x\t  ");
	for(i=0;i<n;i++)
	{
		printf("f[x%d]\t\t",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("----------------");
	}
	printf("\n");
	for(i=0;i<n;i++)//��ӡ���̱� 
	{
		printf("%-10g  %-10g",x[i],y[i]);
		k=i-1;
		for(j=0;j<i;j++)
		{
			printf("%     -10g",f[k]);
			k+=n-2-j;
		}
		if(i==j)
		{
		printf("\n");
		}
	}
	i=0;
	k=0;
	double a,*b;
	printf("������Ҫ����ڵ��xֵ��");
	scanf("%lf",&a);
	b=(double*)malloc(sizeof(double)*n);
	b[0]=1.0;
	for(i=0;i<n-1;i++)
	{
		b[i+1]=b[i]*(a-x[i]);
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			a=b[i]*y[i];
		}
		else
		{
			a+=b[i]*f[k];
			k+=n-i;
		}
	}
	printf("��ֵ�ڵ��Ӧ��YֵΪ��%g\n",a);
}

void Lagrange_interpolation()
{
	int n;
	
	printf("�������ֵ�ڵ�ĸ�����");
	scanf("%d",&n);
	double *x,*y,*f1,*f2;
	x=(double*)malloc(sizeof(double)*n);
	y=(double*)malloc(sizeof(double)*n);
	f1=(double*)malloc(sizeof(double)*n);
	f2=(double*)malloc(sizeof(double)*n);
	printf("�������ֵ�ڵ����ֵ��\n");
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		printf("x[%d]:",i);
		scanf("%lf",&x[i]);
		printf("y[%d]:",i);
		scanf("%lf",&y[i]);
	}	
	for(i=0;i<n;i++)
	{
		f1[i]=1.0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				f1[i]*=(x[i]-x[j]);
			}
		}
	}
	double a;
	double result;
	printf("���������ڵ����ֵ��");
	scanf("%lf",&a);
	for(i=0;i<n;i++)
	{
		f2[i]=1.0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				f2[i]*=(a-x[j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		result+=(y[i]*f2[i])/f1[i];
	}
	printf("��ֵ��ĺ���ֵΪ��%lf",result);
}
