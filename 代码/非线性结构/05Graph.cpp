//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Graph {
//public:
//	//顶点数量
//	int vertex;
//	//边数量
//	int edge;
//	//图
//	vector<vector<int>>matrix;
//
//	Graph(int v, int e) :vertex(v),edge(e),matrix(v,vector<int>(v,0)){};
//
//	//创建邻接矩阵
//	void createGraph(vector<vector<int>>&edgearr) {
//		for (int i = 0; i < edge; i++) {
//			int v1 = edgearr[i][0];
//			int v2 = edgearr[i][1];
//
//			if (v1 >= 1 && v1 <= vertex && v2 >= 1 && v2 <= vertex && v1 != v2 && matrix[v1 - 1][v2 - 1] == 0) {
//				matrix[v1 - 1][v2 - 1] = 1;
//				matrix[v2 - 1][v1 - 1] = 1;
//			}
//		}
//	}
//
//	void BFS(int start) {
//		queue<int>q;
//		vector<bool> flag(vertex, false);
//		q.push(start);
//		flag[start] = true;
//
//		while (!q.empty()) {
//			int cur = q.front();
//			q.pop();
//			//访问当前节点
//			cout << cur << " ";
//			//访问节点
//			for (int i = 0; i < vertex; i++) {
//				// 若存在边且未访问，则加入队列
//				if (matrix[cur][i] == 1 && !flag[i]) {
//					q.push(i);
//					flag[i] = true; // 标记为已访问（避免重复入队）
//				}
//			} 
//		}
//	}
//
//	void myDFS(vector<bool>& mark, int begin) {
//		cout << begin << " ";
//		mark[begin - 1] = true;
//		for (int i = 0; i < vertex; i++){
//			if (matrix[begin - 1][i] == 1 && mark[i] == 0) {
//				myDFS(mark, i + 1);
//			}
//		}
//	}
//
//	void DFS(int begin) {
//		vector<bool>mark(vertex, false);
//		myDFS(mark,begin);
//	}
//};
//
//int main() {
//
//	return 0;
//}