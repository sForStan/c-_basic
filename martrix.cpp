#include<stdio.h>
#include<stdlib.h>
#define M 4
#define N 4
#define MaxSize 200
typedef int ElemType;
typedef struct {
	int row;
	int col;
	ElemType d;
}TupNode;
typedef struct {
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;
TSMatrix A, B;
void createMat(TSMatrix &t, ElemType A[M][N])
{
	int i, j;
	t.rows = M;
	t.cols = N;
	t.nums = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i][j]!=0)
			{
//				printf("%d->\n",A[i][j]);
				t.data[t.nums].row = i;
				t.data[t.nums].col = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
		}
	}
}
bool value(TSMatrix& t, ElemType x, int i, int j)//设定第i行，第j行的元素值
{
	int k = 0, k1;
	if (i > t.rows || j > t.cols)
		return false;
	while (k < t.nums)
	{
		if (i > t.data[k].row)
			k++;
		else if (i == t.data[k].row && j > t.data[k].col)
			k++;
		else
			break;
	}
	if (t.data[k].row == i && t.data[k].col == j)
		t.data[k].d = x;
	else
	{
		for (k1 = t.nums; k1 > k; k1--)
		{
			t.data[k1].row = t.data[k1 - 1].row;
			t.data[k1].col = t.data[k1 - 1].col;
			t.data[k1].d = t.data[k1 - 1].d;
		}
		t.data[k].row = i;
		t.data[k].col = j;
		t.data[k].d = x;
		t.nums++;
	}
	return true;

}
int  assign(TSMatrix t,int i, int j)//查找某位置的元素
{
	int k = 0; int x;
	if (i > t.rows || j > t.cols)
		return false;
	while (k<t.nums && i>t.data[k].row)k++;
	while (k<t.nums && j>t.data[k].col&&i==t.data[k].row)k++;
	if (t.data[k].row == i && t.data[k].col == j)
		x = t.data[k].d;
	else
		x = 0;
	return x;
}
void DispMat(TSMatrix t)//打印三元体数组t.data[]
{
	int k;
	if (t.nums <= 0)
		return;
	printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf("\t--------------------------------\t\n");
	for (k = 0; k < t.nums; k++)
		printf("\t%d\t%d\t%d\n", t.data[k].row, t.data[k].col, t.data[k].d);
}
void TranTat(TSMatrix t, TSMatrix& tb)  //矩阵的转置函数
{
	int k, k1 = 0, v;
	tb.rows = t.cols; tb.cols = t.rows; tb.nums = t.nums;

	if (t.nums != 0) {
		for (v = 0; v < t.cols; v++)
			for (k = 0; k < t.nums; k++)
				if (t.data[k].col == v)
				{
					tb.data[k1].row = t.data[k].col;
					tb.data[k1].col = t.data[k].row;
					tb.data[k1].d = t.data[k].d;
					k1++;
				}
	}
}
bool matrixAdd(TSMatrix a, TSMatrix b, TSMatrix& result)
{
	if (a.cols != b.cols || a.rows != b.rows || a.rows != result.rows || a.cols != result.cols)
		return false;
	else
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				int item = assign(a, i, j) + assign(b, i, j);
				if (item != 0)
					value(result,item,i,j);
			}
		}
	}
	return true;
}
void matrixMult(TSMatrix a, TSMatrix b, TSMatrix& result)
{
	if (a.cols != b.rows || a.rows != result.rows || b.cols != result.cols)
		return ;
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < b.cols; j++)
		{
			int sum = 0;
			for (int k = 0; k < b.rows; k++)
			{
				sum += assign(a,i,k)* assign(b,k,j);
			}
			if (sum != 0)
				value(result, sum, i, j);
		}
	}
}
int main()
{
	int a[M][N] = {
	1, 0, 3, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 1, 1 };
	int b[M][N] = {
		3, 0, 0, 0,
		 0, 4, 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 2 };
	createMat(A, a);
	createMat(B, b);
	printf("第一个三元体：\n");
	DispMat(A);
	printf("\n第二个三元体：\n");
	DispMat(B);
	TSMatrix go;
	TranTat(A, go);
	printf("\n矩阵A的转置矩阵如下：\n");
	DispMat(go);
	TranTat(B, go);
	printf("\n矩阵B的转置矩阵如下：\n");
	DispMat(go);
	matrixAdd(A, B,go);
	printf("\n矩阵A,B的加和矩阵如下：\n");
	DispMat(go);
	matrixMult(A, B, go);
	printf("\n矩阵A,B的相乘矩阵如下：\n");
	DispMat(go);
	return 0;
}