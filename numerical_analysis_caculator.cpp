//头文件
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
//宏定义变量
const int MAX = 10;
int NUM;
#define FPS 60
//声明点击判断
inline bool clickBtninterpolation(int x, int y);
inline bool clickBtnapproximation(int x, int y);
//声明页面
void indexpage();
void interpolationpage();
void approximationpage();
//声明函数
//void input_data();
void Equal_Newton_interpolation();
void Unequal_Newton_interpolation();
void Lagrange_interpolation();
void Hermite_interpolation();
void cubic_spline_interpolation();
void ordinary_least_squares_techniques();
void least_squares_approximation();

int main()
{
	indexpage();
	/*    if(x==1)
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
    }*/
	return 0;
}
//运算函数
void Equal_Newton_interpolation()
{
	int n;
	double *x, *y, *f, h, t;
	printf("请输入步长（两个节点之间的距离）:");
	scanf("%lf", &h);
	printf("请输入插值节点的个数：");
	scanf("%d", &n);
	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * n);
	f = (double *)malloc(sizeof(double) * n * (n - 1) / 2);
	int i;
	int j;
	int k;
	i = 0;
	k = 0;
	while (n > i)
	{
		printf("x[%d]:", i);
		scanf("%lf", &x[i]);
		printf("y[%d]:", i);
		scanf("%lf", &y[i]);
		i++;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (i == 0)
			{
				f[k] = y[j + 1] - y[j]; //计算一阶差分
				k++;
			}
			else
			{
				f[k] = f[k + 1 + i - n] - f[k + i - n];
				k++;
			}
		}
	}
	i = 0;
	j = 0;
	k = 0;
	printf("差分表：\n");
	printf("x\t ");
	for (i = 0; i < n; i++)
	{
		printf("f[x%d]      ", i);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("------------");
	}
	printf("\n");
	for (i = 0; i < n; i++) //打印差分表
	{
		printf("%-10g  %-10g", x[i], y[i]);
		k = i - 1;
		for (j = 0; j < i; j++)
		{
			printf("%     -10g", f[k]);
			k += n - 2 - j;
		}
		if (i == j)
		{
			printf("\n");
		}
	}
	i = 0;
	k = 0;
	double a, *b;
	printf("请输入插入节点的值：");
	scanf("%lf", &a);
	b = (double *)malloc(sizeof(double) * n);
	t = (a - x[0]) / h;
	b[0] = 1.0;
	for (i = 0; i < n - 1; i++)
	{
		b[i + 1] = (b[i] * (t - i)) / (i + 1);
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a = y[i] * b[i];
		}
		else
		{
			a += b[i] * f[k];
			k = k + n - i;
		}
	}
	printf("插值节点对应的Y值为：%g\n", a);
}
void Unequal_Newton_interpolation()
{
	int n;
	double *x, *y, *f;
	printf("请输入插值节点的个数：");
	scanf("%d", &n);
	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * n);
	f = (double *)malloc(sizeof(double) * (n - 1) * n / 2);
	int i, j, k;
	i = 0;
	k = 0;
	while (n > i) //对数据进行输入
	{
		printf("x[%d]:", i);
		scanf("%lf", &x[i]);
		printf("y[%d]:", i);
		scanf("%lf", &y[i]);
		i++;
	}
	i = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (i == 0)
			{
				f[k] = (y[j + 1] - y[j]) / (x[j + 1] - x[j]); //计算一阶差商
				k++;
			}
			else
			{
				f[k] = (f[k + i - n + 1] - f[k + i - n]) / (x[j + 1 + i] - x[j]); //计算二阶及以上差商
				k++;
			}
		}
	}
	i = 0;
	j = 0;
	k = 0;
	printf("差商表：\n");
	printf("x\t  ");
	for (i = 0; i < n; i++)
	{
		printf("f[x%d]\t\t", i);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("----------------");
	}
	printf("\n");
	for (i = 0; i < n; i++) //打印差商表
	{
		printf("%-10g  %-10g", x[i], y[i]);
		k = i - 1;
		for (j = 0; j < i; j++)
		{
			printf("%     -10g", f[k]);
			k += n - 2 - j;
		}
		if (i == j)
		{
			printf("\n");
		}
	}
	i = 0;
	k = 0;
	double a, *b;
	printf("请输入要插入节点的x值：");
	scanf("%lf", &a);
	b = (double *)malloc(sizeof(double) * n);
	b[0] = 1.0;
	for (i = 0; i < n - 1; i++)
	{
		b[i + 1] = b[i] * (a - x[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a = b[i] * y[i];
		}
		else
		{
			a += b[i] * f[k];
			k += n - i;
		}
	}
	printf("插值节点对应的Y值为：%g\n", a);
}

void Lagrange_interpolation()
{
	int n;

	printf("请输入插值节点的个数：");
	scanf("%d", &n);
	double *x, *y, *f1, *f2;
	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * n);
	f1 = (double *)malloc(sizeof(double) * n);
	f2 = (double *)malloc(sizeof(double) * n);
	printf("请输入插值节点的数值：\n");
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		printf("x[%d]:", i);
		scanf("%lf", &x[i]);
		printf("y[%d]:", i);
		scanf("%lf", &y[i]);
	}
	for (i = 0; i < n; i++)
	{
		f1[i] = 1.0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				f1[i] *= (x[i] - x[j]);
			}
		}
	}
	double a;
	double result;
	printf("请输入插入节点的数值：");
	scanf("%lf", &a);
	for (i = 0; i < n; i++)
	{
		f2[i] = 1.0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				f2[i] *= (a - x[j]);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		result += (y[i] * f2[i]) / f1[i];
	}
	printf("插值点的函数值为：%lf", result);
}
//页面函数
void indexpage()
{
	int xClick, yClick;
	setcaption("插值拟合计算器");
	initgraph(960, 540, 0);
	//创建图片对象
	PIMAGE pimg = newimage();
	getimage(pimg, ".\\numerical_analysis_caculator\\mikasa.jpg");
	putimage(0, 0, pimg);
	//	delimage(pimg);

	//文字的属性设置
	setcolor(BLACK);		//文字的颜色
	setbkmode(TRANSPARENT); //设置文字背景色为透明

	int height = 80; //文字高度

	setfont(height, 0, "楷体"); //设置文字宽度和字体

	//输出文字
	xyprintf(200, 60, "插值拟合计算器");
	setfont(20, 0, "楷体");
	xyprintf(860, 480, "Eloi0424");
	xyprintf(860, 500, "developer2");
	xyprintf(860, 520, "developer3");
	setfont(30, 0, "楷体");
	xyprintf(700, 500, "developer:");
	setfont(80, 0, "楷体");
	xyprintf(200, 200, "插值");
	xyprintf(600, 200, "拟合");
	//鼠标点击检测
	for (; is_run(); delay_fps(FPS))
	{
		bool leftClick = false;
		while (mousemsg())
		{
			mouse_msg mouseMsg = getmouse();
			if (mouseMsg.is_left() && mouseMsg.is_down())
			{ //左键按下
				leftClick = true;
				xClick = mouseMsg.x;
				yClick = mouseMsg.y;
				printf("yes");
			}
		}
		//鼠标点击判断
		if (leftClick && clickBtninterpolation(xClick, yClick))
		{
			interpolationpage();
			//		closegraph();
		}
		//鼠标点击判断
		if (leftClick && clickBtnapproximation(xClick, yClick))
		{
			approximationpage();
			//		closegraph();
		}
	}
	getch();
	closegraph();
}
void interpolationpage()
{
	setinitmode(INIT_RENDERMANUAL, 100, 100); //设置为手动模式, 设置窗口位置
	initgraph(640, 640);					  //初始化窗口
	setcaption("1");						  //设置窗口标题

	setbkcolor(WHITE); //设置窗口背景为白色
	setcolor(RED);	   //设置前景色为红色
	setfillcolor(RED); //设置填充色为红色

	for (; is_run(); delay_fps(60))
	{
		//定义个鼠标结构体变量， 并初始化
		mouse_msg msg = {0};

		//改下面这个 while, 改成 if 试试
		//获取鼠标消息
		while (mousemsg())
		{
			msg = getmouse();
		}

		//鼠标移动则绘画
		if (msg.is_move())
		{
			//清屏， 可以注释掉试试
			cleardevice();

			//画红色小圆
			fillellipse(msg.x, msg.y, 5, 5);
		}
	}

	closegraph();
}
void approximationpage()
{
	setinitmode(INIT_RENDERMANUAL, 100, 100); //设置为手动模式, 设置窗口位置
	initgraph(640, 640);					  //初始化窗口
	setcaption("2");						  //设置窗口标题

	setbkcolor(WHITE); //设置窗口背景为白色
	setcolor(RED);	   //设置前景色为红色
	setfillcolor(RED); //设置填充色为红色

	for (; is_run(); delay_fps(60))
	{
		//定义个鼠标结构体变量， 并初始化
		mouse_msg msg = {0};

		//改下面这个 while, 改成 if 试试
		//获取鼠标消息
		while (mousemsg())
		{
			msg = getmouse();
		}

		//鼠标移动则绘画
		if (msg.is_move())
		{
			//清屏， 可以注释掉试试
			cleardevice();

			//画红色小圆
			fillellipse(msg.x, msg.y, 5, 5);
		}
	}

	closegraph();
}
//按钮点击判断
inline bool clickBtninterpolation(int x, int y)
{
	return (200 < x && x < 200 + 80) && (200 < y && y < 200 + 80);
}
inline bool clickBtnapproximation(int x, int y)
{
	return (600 < x && x < 600 + 80) && (200 < y && y < 200 + 80);
}
