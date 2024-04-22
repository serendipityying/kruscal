//克鲁斯卡尔（Kruscal）算法求最小生成树
#include <stdio.h>
#define MAX 100       //定义最大顶点数
typedef struct        //建立一个边集合数组，其中包括边的起始点、终止点以及这条边的权值
{
	int u;         //一条边的起始顶点
	int v;         //一条边的终止顶点
	int w;         //边的权值（权重）
}Edge;             //边的类型定义
Edge E[MAX];       //定义一个全局数组E，用于存储图的各条边（创建边的数组）     


//创建一个无向网图
int CreateEdge()
{
	int i;
	int anum;
	printf("\n输入无向网的边数：");
	scanf_s("%d", &anum);

	for (i = 0; i < anum; ++i)
	{
		printf("\n输入第%d条边的起始顶点、终止顶点以及该边的权值（v1、v2、w）：\n", i + 1);
		scanf_s("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
	}
	return anum;
}


//对边表进行从小到大排序算法
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


//在边表中查看顶点v在哪个连通集合中
int seeks(int set[], int v)
{
	int i = v;

	while (set[i] > 0)
		i = set[i];
	return(i);
}


//克鲁斯卡尔算法的核心环节
void Kruskal(Edge E[], int n)    //算法核心环节
{
	int sum = 0;                  //定义权值总和
	int set[MAX];                //创建状态临时数组(辅助标志数组)
	int v1, v2, i;               //数组中的下标的临时变量

	for (i = 0; i < MAX; i++)
		set[i] = 0;              //给set数组中的每个元素赋予初值
	i = 0;                       //i表示特获取的生成树种的边数，初值为1

	while (i < n)                   //按边权递增顺序，逐边检查该边是否应加入到生成树中                             
	{
		v1 = seeks(set, E[i].u);    //确定顶点v所在的连通集
		v2 = seeks(set, E[i].v);

		if (v1 != v2)              //当v1，v2不在同一顶点集合，确定该边应当选入生成树
		{
			printf("(%d,%d) %d\n", E[i].u, E[i].v, E[i].w);
			set[v1] = v2;          //将v2加入到v1的集合中
			sum += E[i].w;
		}
		i++;
	}
	printf("weight of MST is %d \n", sum);
}


void main()
{
	int n;
	n = CreateEdge();                    //调用生成边表函数
	if (n > 0)                            //判断输入的n值是否合法（n>0）
	{
		sort(n);                       //对边表集合进行排序
		printf("\n最小生成树为( (顶点,顶点) 权值 ):\n");
	}
	else
		printf("\n输入边数错误，请重新输入！\n");
	Kruskal(E, n);                      //调用克鲁斯卡尔算法求最小生成树
}

