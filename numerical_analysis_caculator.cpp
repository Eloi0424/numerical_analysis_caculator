//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
//�궨�����
const int MAX = 10;
int NUM;
#define FPS 60
//��������ж�
inline bool clickBtninterpolation(int x, int y);
inline bool clickBtnapproximation(int x, int y);
//����ҳ��
void indexpage();
void interpolationpage();
void approximationpage();
//��������
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
    }*/
	return 0;
}
//���㺯��
void Equal_Newton_interpolation()
{
	int n;
	double *x, *y, *f, h, t;
	printf("�����벽���������ڵ�֮��ľ��룩:");
	scanf("%lf", &h);
	printf("�������ֵ�ڵ�ĸ�����");
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
				f[k] = y[j + 1] - y[j]; //����һ�ײ��
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
	printf("��ֱ�\n");
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
	for (i = 0; i < n; i++) //��ӡ��ֱ�
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
	printf("���������ڵ��ֵ��");
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
	printf("��ֵ�ڵ��Ӧ��YֵΪ��%g\n", a);
}
void Unequal_Newton_interpolation()
{
	int n;
	double *x, *y, *f;
	printf("�������ֵ�ڵ�ĸ�����");
	scanf("%d", &n);
	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * n);
	f = (double *)malloc(sizeof(double) * (n - 1) * n / 2);
	int i, j, k;
	i = 0;
	k = 0;
	while (n > i) //�����ݽ�������
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
				f[k] = (y[j + 1] - y[j]) / (x[j + 1] - x[j]); //����һ�ײ���
				k++;
			}
			else
			{
				f[k] = (f[k + i - n + 1] - f[k + i - n]) / (x[j + 1 + i] - x[j]); //������׼����ϲ���
				k++;
			}
		}
	}
	i = 0;
	j = 0;
	k = 0;
	printf("���̱�\n");
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
	for (i = 0; i < n; i++) //��ӡ���̱�
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
	printf("������Ҫ����ڵ��xֵ��");
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
	printf("��ֵ�ڵ��Ӧ��YֵΪ��%g\n", a);
}

void Lagrange_interpolation()
{
	int n;

	printf("�������ֵ�ڵ�ĸ�����");
	scanf("%d", &n);
	double *x, *y, *f1, *f2;
	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * n);
	f1 = (double *)malloc(sizeof(double) * n);
	f2 = (double *)malloc(sizeof(double) * n);
	printf("�������ֵ�ڵ����ֵ��\n");
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
	printf("���������ڵ����ֵ��");
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
	printf("��ֵ��ĺ���ֵΪ��%lf", result);
}
//ҳ�溯��
void indexpage()
{
	int xClick, yClick;
	setcaption("��ֵ��ϼ�����");
	initgraph(960, 540, 0);
	//����ͼƬ����
	PIMAGE pimg = newimage();
	getimage(pimg, ".\\numerical_analysis_caculator\\mikasa.jpg");
	putimage(0, 0, pimg);
	//	delimage(pimg);

	//���ֵ���������
	setcolor(BLACK);		//���ֵ���ɫ
	setbkmode(TRANSPARENT); //�������ֱ���ɫΪ͸��

	int height = 80; //���ָ߶�

	setfont(height, 0, "����"); //�������ֿ�Ⱥ�����

	//�������
	xyprintf(200, 60, "��ֵ��ϼ�����");
	setfont(20, 0, "����");
	xyprintf(860, 480, "Eloi0424");
	xyprintf(860, 500, "developer2");
	xyprintf(860, 520, "developer3");
	setfont(30, 0, "����");
	xyprintf(700, 500, "developer:");
	setfont(80, 0, "����");
	xyprintf(200, 200, "��ֵ");
	xyprintf(600, 200, "���");
	//��������
	for (; is_run(); delay_fps(FPS))
	{
		bool leftClick = false;
		while (mousemsg())
		{
			mouse_msg mouseMsg = getmouse();
			if (mouseMsg.is_left() && mouseMsg.is_down())
			{ //�������
				leftClick = true;
				xClick = mouseMsg.x;
				yClick = mouseMsg.y;
				printf("yes");
			}
		}
		//������ж�
		if (leftClick && clickBtninterpolation(xClick, yClick))
		{
			interpolationpage();
			//		closegraph();
		}
		//������ж�
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
	setinitmode(INIT_RENDERMANUAL, 100, 100); //����Ϊ�ֶ�ģʽ, ���ô���λ��
	initgraph(640, 640);					  //��ʼ������
	setcaption("1");						  //���ô��ڱ���

	setbkcolor(WHITE); //���ô��ڱ���Ϊ��ɫ
	setcolor(RED);	   //����ǰ��ɫΪ��ɫ
	setfillcolor(RED); //�������ɫΪ��ɫ

	for (; is_run(); delay_fps(60))
	{
		//��������ṹ������� ����ʼ��
		mouse_msg msg = {0};

		//��������� while, �ĳ� if ����
		//��ȡ�����Ϣ
		while (mousemsg())
		{
			msg = getmouse();
		}

		//����ƶ���滭
		if (msg.is_move())
		{
			//������ ����ע�͵�����
			cleardevice();

			//����ɫСԲ
			fillellipse(msg.x, msg.y, 5, 5);
		}
	}

	closegraph();
}
void approximationpage()
{
	setinitmode(INIT_RENDERMANUAL, 100, 100); //����Ϊ�ֶ�ģʽ, ���ô���λ��
	initgraph(640, 640);					  //��ʼ������
	setcaption("2");						  //���ô��ڱ���

	setbkcolor(WHITE); //���ô��ڱ���Ϊ��ɫ
	setcolor(RED);	   //����ǰ��ɫΪ��ɫ
	setfillcolor(RED); //�������ɫΪ��ɫ

	for (; is_run(); delay_fps(60))
	{
		//��������ṹ������� ����ʼ��
		mouse_msg msg = {0};

		//��������� while, �ĳ� if ����
		//��ȡ�����Ϣ
		while (mousemsg())
		{
			msg = getmouse();
		}

		//����ƶ���滭
		if (msg.is_move())
		{
			//������ ����ע�͵�����
			cleardevice();

			//����ɫСԲ
			fillellipse(msg.x, msg.y, 5, 5);
		}
	}

	closegraph();
}
//��ť����ж�
inline bool clickBtninterpolation(int x, int y)
{
	return (200 < x && x < 200 + 80) && (200 < y && y < 200 + 80);
}
inline bool clickBtnapproximation(int x, int y)
{
	return (600 < x && x < 600 + 80) && (200 < y && y < 200 + 80);
}
