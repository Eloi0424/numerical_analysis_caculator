#include <stdio.h>
#include <stdlib.h>
//头文件
const int MAX=10;
int NUM;
//宏定义变量
//void input_data();
void Equal_Newton_interpolation();
void Unequal_Newton_interpolation();
void Lagrange_interpolation();
void Hermite_interpolation();
void cubic_spline_interpolation();
void ordinary_least_squares_techniques();
void least_squares_approximation();
//声明函数
int main()
{
    
    int x;
//    input_data();
    printf("请选择插值或拟合：1.插值 2.拟合 :");
    scanf("%d",&x);
    if(x==1)
    {
        printf("请选择插值类型：1.Newton插值 2.Lagrange插值 3.Hermite插值 4.cubic spline 插值 :");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
            printf("请选择Newton插值类型：1.等距节点 2.非等距节点  :");
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
            printf("输入错误");
            break;
        }
    }
    if(x==2)
    {
        printf("请选择拟合类型：1.ordinary least squares techniques拟合 2.least squares approximation插值 :");
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
            printf("输入错误");
            break;
        }
    }
    return 0;
}
/*
void input_data()
{
    printf("请输入数据量\n");
    printf("N = ");
    scanf("%d",&NUM);
    printf("请输入数据点\n");
    printf("每行一个数据点\n");
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
	printf("请输入步长（两个节点之间的距离）:");
	scanf("%lf",&h);
	printf("请输入插值节点的个数：");
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
				f[k]=y[j+1]-y[j];//计算一阶差分 
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
	printf("差分表：\n");
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
	for(i=0;i<n;i++)//打印差分表 
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
	printf("请输入插入节点的值：");
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
	printf("插值节点对应的Y值为：%g\n",a);	
}
void Unequal_Newton_interpolation()
{
	int n;
	double *x,*y,*f;
	printf("请输入插值节点的个数：");
	scanf("%d",&n);
	x=(double*)malloc(sizeof(double) *n);
	y=(double*)malloc(sizeof(double) *n);
	f=(double*)malloc(sizeof(double) *(n-1)*n/2);
	int i,j,k;
	i=0;
	k=0;
	while(n>i)//对数据进行输入 
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
				f[k]=(y[j+1]-y[j])/(x[j+1]-x[j]);//计算一阶差商 
				k++;
			}
			else
			{
				f[k]=(f[k+i-n+1]-f[k+i-n])/(x[j+1+i]-x[j]);//计算二阶及以上差商 
				k++;	
			}
		}
	}
	i=0;
	j=0;
	k=0;
	printf("差商表：\n");
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
	for(i=0;i<n;i++)//打印差商表 
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
	printf("请输入要插入节点的x值：");
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
	printf("插值节点对应的Y值为：%g\n",a);
}

void Lagrange_interpolation()
{
	int n;
	
	printf("请输入插值节点的个数：");
	scanf("%d",&n);
	double *x,*y,*f1,*f2;
	x=(double*)malloc(sizeof(double)*n);
	y=(double*)malloc(sizeof(double)*n);
	f1=(double*)malloc(sizeof(double)*n);
	f2=(double*)malloc(sizeof(double)*n);
	printf("请输入插值节点的数值：\n");
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
	printf("请输入插入节点的数值：");
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
	printf("插值点的函数值为：%lf",result);
}
