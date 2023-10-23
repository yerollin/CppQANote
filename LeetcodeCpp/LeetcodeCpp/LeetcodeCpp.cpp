#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

int Q2678(vector<string>& details) {//简单题
	int answer = 0;
	for (size_t i = 0; i < details.size(); i++)
	{
		if ((details[i][11] - '0')>6)
			answer++;
		else if ((details[i][11] - '0') ==6 && (details[i][12] - '0') != 0)
			answer++;
	}
	return answer;
}

vector<double> Q1093(vector<int>&& count) {
	vector<double> answer;
	answer.resize(5,0);
	double& minimum = answer[0];//最小元素
	double& maximum = answer[1];//最大元素
	double& mean = answer[2];//样本的平均值
	double& median = answer[3];//中位数
	double& mode = answer[4];  //保众数是 唯一
	
	for (size_t i = 0; i < 256; i++){
		if (count[i] != 0) {
			minimum = i;
			break;
		}
	}
	for (int i = 255; i>=0 ; i--){
		if (count[i] != 0) {
			maximum = i;
			break;
		}
	}
	
	int Nums = 0;//总数
	long long  AllAdd=0;//总和
	for (size_t i = 0; i < 256; i++)
	{
		Nums += count[i];
		AllAdd += i * count[i];

		mode = count[mode] > count[i] ? mode : i;
	}
	mean = (double)AllAdd / Nums;

	int mediaIndex = Nums / 2;//后边那个,
	int tempIndex = 0;//原始数据下标
	for (size_t i = 0; i < 256; i++)
	{
		if (tempIndex + count[i] > mediaIndex) {
			median = i;//数据本身，也就是输入数据的下标
			break;
		}
		else
			tempIndex += count[i];
	}
	
	if (Nums % 2 == 0)//两个数字
	{
		tempIndex = 0; 
		mediaIndex--;//拿到前一个做平均

		for (size_t i = 0; i < 256; i++)
		{
			if (tempIndex + count[i] > mediaIndex){
				median += i;
				median /= 2;
				break;
			}
			else
				tempIndex += count[i];
		}

	}
	
	return answer;
}

int dis(int length,int p1,int p2)
{
	int l1 = abs(p1 < p2 ? p2 : p1 - length);//右边
	int l2 = p1 > p2 ? p2 : p1;//左边
	int l0 = abs(p1 - p2);//中间

	return min(l1 + l2, l0);
}
int mhy知乎451239130(int n,int m, int ax,int ay, int bx, int by, int cx, int cy)
{
	int x1 = dis(n,ax,bx);
	int y1 = dis(m,ay,by);

	int x2 = dis(n, cx, bx);
	int y2 = dis(m, cy, by);

	return x1 + y1 + x2 + y2;
}

int trap(vector<int>& height) {//乐扣myh题库，提交四次，总计一小时
	int answer = 0;

	int maxH = 0,hindex=0;
	for (auto i = 0; i < height.size(); i++){
		if (height[i]> maxH){
			maxH = height[i]; 
			hindex = i;
		}
	}

	for (size_t i = 0; i < hindex; i++){//左边界
		for (size_t j = i+1; j <= hindex; j++){//右边界
			if (height[j]>=height[i]){
				//进入逻辑，
				for (size_t k = i+1; k < j; k++){  //当前遍历
					if (height[i]-height[k]>0){//左边是最低的，所以是i
						answer += height[i] - height[k];
						cout<<k<<"号位置+"<< height[i] - height[k]<<endl;
					}
				}
				i = j;
			}
		}
	}
	for (int i = height.size() - 1; i > hindex;i--)//起始边界
	{
		for (int j = i - 1; j >= hindex; j--) {//高终点边界
			if (height[j] >= height[i]) {
				//进入逻辑，
				for (int k = i - 1; k > j; k--) {
					if (height[i] - height[k] > 0) {
						answer += height[i] - height[k];
						cout << k << "号位置+" << height[i] - height[k] << endl;
					}
				}
				i = j;
			}
		}
	}
	return answer;
}

int main()
{
	cout << mhy知乎451239130(5, 3, 4, 1,1, 1, 1, 3);//3


	
	

}
