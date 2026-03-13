#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define VEX_NUM 6   
#define E 8
typedef struct {
	string vexs[VEX_NUM];
	int arcs[VEX_NUM][VEX_NUM];
}Mgraph;

void print(Mgraph& g)
{
	int i, j; cout << setw(4) << "  ";
	for (i = 0; i < VEX_NUM; i++)
		cout << setw(10) << g.vexs[i];
	cout << endl << endl;

	for (i = 0; i < VEX_NUM; i++)
	{
		cout << setw(4) << g.vexs[i];
		for (j = 0; j < VEX_NUM; j++)
			if (g.arcs[i][j] == 0x7fffffff)
				cout << setw(10) << "max";
			else cout << setw(10) << g.arcs[i][j];
		cout << endl << endl;
	}
}


void create(Mgraph& G, int e)
{
	int i, j, m;   string v[VEX_NUM] = { "v0","v1","v2","v3","v4","v5" };
	int edge[] = { 0,2, 0,4, 0,5, 1,2, 2,3, 3,5, 4,3, 4,5 };
	int cost[] = { 10,   30, 100,  5,  50,  10,  20,  60 };

	for (i = 0; i < VEX_NUM; i++)
		G.vexs[i] = v[i];
	for (i = 0; i < VEX_NUM; i++)
		for (j = 0; j <= i; j++)
			if (i == j) G.arcs[i][j] = 0;
			else        G.arcs[i][j] = G.arcs[j][i] = 0x7fffffff;
	m = 0;
	for (int k = 0; k < 2 * e; k += 2)
		i = edge[k], j = edge[k + 1], G.arcs[i][j] = cost[m++];
}

int path[VEX_NUM];
int dist[VEX_NUM];

void dijkstra(Mgraph& g, int u0, int path[], int dist[])
//调用语句  dijkstra(g, 0, path, dist);
{
	int v, s[VEX_NUM];
	//下面单层循环初始化标识数组s[],最短距离数组dist[],前驱顶点数组path[]

	for (v = 0; v < VEX_NUM; v++)
	{
		s[v] = 0; dist[v] = g.arcs[u0][v];   //dist[]中存储从初始点到其他顶点的距离
		if (dist[v] < 0x7fffffff) path[v] = u0;
		else                   path[v] = -1;
	}

	int min, w; int i, j;
	dist[u0] = 0; s[u0] = 1; //s[u0]=1  表示源点到源点的最短距离已经求出 
	//s[i]=1表示源点到i点最短距离已经求出；否则s[i]=0 表示源点到i点最短距离未求出
	for (i = 1; i < VEX_NUM; i++)   //i从1到VEX_NUM-1    表示共VEX_NUM个顶点，从某顶点到其他点（VEX_NUM-1个点）的最短距离
	{
		min = 0x7fffffff, v = -1;//min存储最小距离值，v存顶点序号
		for (w = 0; w < VEX_NUM; w++)
			if (!s[w] && dist[w] < min)  //s[w]等于0（表示u0到w点的最小距离还没有找到），同时dist[w]比min小
				v = w, min = dist[w];
		//上面单层循环退出后，第i次找到初始点u0到其他的点中的一个点的最小距离

		if (v != -1) {
			s[v] = 1;//当前初始点到其他点中的最短距离为V点
			for (j = 0; j < VEX_NUM; j++)
				//初始点u0到V点距离最小，那么下面修正经过或不经过V到其他点（去掉本身和没有路径的情况）距离，取最小
				if (g.arcs[v][j] == 0x7fffffff || v == j)  continue;
				else
					if (!s[j] && (min + g.arcs[v][j] < dist[j]))
						dist[j] = min + g.arcs[v][j], path[j] = v;
		}//end if v!=-1

		//源点经V到（其他点j表示）j的 最短路径 比 原来的源点到j （不经过V点）路径小，
		// 则更新最短距离dist[j] = min + g.arcs[v][j];和
		//源点到j 经过v的  对j 来说的前驱顶点V  即path[j] = v;

	}//end for i

}//end  dijkstra

void putpath(int u0, int p[], int d[])
{
	int next;
	for (int i = 0; i < VEX_NUM; i++)
		if (d[i] < 0x7fffffff && i != u0)
		{
			cout << "v" << i << "<--";
			next = p[i];
			while (next != u0)
			{
				cout << "v" << next << "<--"; next = p[next];
			}
			cout << "v" << u0 << ":" << d[i] << endl;
		}
		else
			if (i != u0) cout << "v" << i << "<--v" << u0 << ":no path" << endl;
}



int main()
{
	Mgraph g;
	create(g, E);
	print(g);
	dijkstra(g, 0, path, dist);
	putpath(0, path, dist);
	return 0;
}