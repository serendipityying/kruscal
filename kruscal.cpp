//��³˹������Kruscal���㷨����С������
#include <stdio.h>
#define MAX 100       //������󶥵���
typedef struct        //����һ���߼������飬���а����ߵ���ʼ�㡢��ֹ���Լ������ߵ�Ȩֵ
{
	int u;         //һ���ߵ���ʼ����
	int v;         //һ���ߵ���ֹ����
	int w;         //�ߵ�Ȩֵ��Ȩ�أ�
}Edge;             //�ߵ����Ͷ���
Edge E[MAX];       //����һ��ȫ������E�����ڴ洢ͼ�ĸ����ߣ������ߵ����飩     


//����һ��������ͼ
int CreateEdge()
{
	int i;
	int anum;
	printf("\n�����������ı�����");
	scanf_s("%d", &anum);

	for (i = 0; i < anum; ++i)
	{
		printf("\n�����%d���ߵ���ʼ���㡢��ֹ�����Լ��ñߵ�Ȩֵ��v1��v2��w����\n", i + 1);
		scanf_s("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
	}
	return anum;
}


//�Ա߱���д�С���������㷨
void sort(int n)
{
	int i, j;
	Edge t;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (E[i].w > E[j].w)
			{
				t = E[i];
				E[i] = E[j];
				E[j] = t;
			}
}


//�ڱ߱��в鿴����v���ĸ���ͨ������
int seeks(int set[], int v)
{
	int i = v;

	while (set[i] > 0)
		i = set[i];
	return(i);
}


//��³˹�����㷨�ĺ��Ļ���
void Kruskal(Edge E[], int n)    //�㷨���Ļ���
{
	int sum = 0;                  //����Ȩֵ�ܺ�
	int set[MAX];                //����״̬��ʱ����(������־����)
	int v1, v2, i;               //�����е��±����ʱ����

	for (i = 0; i < MAX; i++)
		set[i] = 0;              //��set�����е�ÿ��Ԫ�ظ����ֵ
	i = 0;                       //i��ʾ�ػ�ȡ���������ֵı�������ֵΪ1

	while (i < n)                   //����Ȩ����˳����߼��ñ��Ƿ�Ӧ���뵽��������                             
	{
		v1 = seeks(set, E[i].u);    //ȷ������v���ڵ���ͨ��
		v2 = seeks(set, E[i].v);

		if (v1 != v2)              //��v1��v2����ͬһ���㼯�ϣ�ȷ���ñ�Ӧ��ѡ��������
		{
			printf("(%d,%d) %d\n", E[i].u, E[i].v, E[i].w);
			set[v1] = v2;          //��v2���뵽v1�ļ�����
			sum += E[i].w;
		}
		i++;
	}
	printf("weight of MST is %d \n", sum);
}


void main()
{
	int n;
	n = CreateEdge();                    //�������ɱ߱���
	if (n > 0)                            //�ж������nֵ�Ƿ�Ϸ���n>0��
	{
		sort(n);                       //�Ա߱��Ͻ�������
		printf("\n��С������Ϊ( (����,����) Ȩֵ ):\n");
	}
	else
		printf("\n��������������������룡\n");
	Kruskal(E, n);                      //���ÿ�³˹�����㷨����С������
}

