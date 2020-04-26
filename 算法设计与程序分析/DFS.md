# 深度优先搜索基本原理与常见优化手段

## DFS基本原理
DFS(Deepth First Search)，深度优先搜索，是一种图论中的搜索算法，由约翰·霍普克洛夫特与罗伯特·塔扬提出。该算法遵循的最基本的策略就是去尽可能“深”的去搜索地图，是一种枚举所有完整路径以遍历所有情况的搜索方法。深度优先搜索对状态的查找采用的是立即拓展得到新的状态，而不是将当前状态全部拓展完之后再扩展新状态。因此，常使用递归函数来实现这一功能。由于DFS不会根据图的结构等信息调整执行策略，因此搜索得到的结果一般不具有最优解的特性，常用来判断一个问题的解是否存在。

#### 时空复杂度

平均情况下，在图的分支系数为b，图的最大深度为m的条件下，其时空复杂度为：

- 平均时间复杂度：$O(b^m)$
- 平均空间复杂度：$O(bm)$

#### 基本过程

在搜索过程中，首先访问起点，之后访问节点的一个邻居，先不访问除该节点之外的其他起点的邻居节点，而是访问该节点的邻居节点，如此往复，直到找到解，或者当前访问节点已经没有尚未访问的邻居节点为止。之后回溯到上一个节点并访问它的另一个邻居节点。

### 实例说明：

#### 连通图

<img src="http://www.bbbbchan.com/wp-content/uploads/2018/11/图片1.png" alt="image" style="zoom:50%;" />

- 假设搜索目的是寻找到一条从1号节点到8号节点的路径，即利用深度优先搜索的方法，从节点1开始，直到搜索找到节点8为止。
- **深度优先搜索策略：**  从起点开始，**任意**选择一个与其相连的节点，标记该节点并向下搜索，对于被选择的节点，再**任意**选择一个与其相连的节点，直到所有节点均被标记或没有新节点可以被选择为止。
  **注意**：这里强调**任意**选一个相连节点向下搜索，也就是从直观上讲，搜索过程和节点选择有一定的关系。  





- 可能的搜索路径：

  - 在最理想的情况下，选择节点的方式为1 -> 2 -> 4 -> 8，也就是不经过回溯就选到了正确路径。
  - 在一般情况下，一条可能的路径为1->3->7->9 => 7-> A => 3 ->4 -> 8 (=>表示回退)  

  可以看到，在一般情况下，可能的搜索路径是先沿着一条不正确的路径走到“死胡同”，再回退到最近的岔路口选择另一条可能的路径，直到走到终点或穷尽所有路径为止。

#### 非连通图

<img src="http://www.bbbbchan.com/wp-content/uploads/2018/11/图片2.png" style="zoom:50%;" />

-  与上一个例子类似，在搜索目的任然是寻找节点1到节点8的可能路径的条件下。对于上述非联通图，肉眼可以很清楚的看到，不存在从节点1到节点8的可能路径。

- 但是如果我们在深度优先搜索的过程中，面对上述非连通图的问题，有如下结论：

  **在得出无法到达节点8的结论前，一定会把从1开始经过的点都走过一遍**

- 可能的搜索路径是： 
  1->2->9=>2->4->3-7=>3=>4=>2=>1 =>表示回退

  可以看到，在上述搜索路径中，遍历了节点1所在的连通分量中存在的所有的道路，最终得出无法到达节点8的结论

- 这种非连通图的情况，给了我们处理一类问题的思路，也就是在一整个地图上寻找所有连通图的个数的问题。 

下面针对深度优先搜索较常见的基础问题给出了3个例题。

## 例题

### 1、水洼数量问题(Lake counting) POJ2386/P1596
#### 题目描述
> 我们用一个N*M(1<=N<=100;1<=M<=100)网格图表示。每个网格中有水('W') 或是旱地('.')。一个网格与其周围的八个网格相连，而一组相连的网格视为一个水坑。约翰想弄清楚他的田地已经形成了多少水坑。给出约翰田地的示意图，确定当中有多少水坑。  

#### 输入
> 第1行：两个空格隔开的整数：N 和 M 第2行到第N+1行：每行M个字符，每个字符是'W'或'.'，它们表示网格图中的一排。字符之间没有空格。  

#### 输出
> 一行：水坑的数量

#### 解题思路
这道题其实是一个遍历的问题，从找到一个W标记的水坑开始进行深度优先遍历，每找到一个相邻的W便把它标记成'.'，从而使得在主函数中每对一个点进行遍历，在图上该点所在的水坑都被覆盖成旱地，从而完成一次计数。 

也就是说，我们在主函数中，先读入数据，对于地图上的每一个点，如果这个点表示水坑，我们就用dfs的方法从这个点开始，把该点所在的水坑填成旱地，之后让我们的计数器加一，这样就可以完成整道题的搜索过程。  

#### 代码实现
```cpp
#include <iostream>
using namespace std;
char field[100][100];
int n, m, ans = 0;
void dfs(int i, int j){
	field[i][j] = '.';
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			int nx = i+dx, ny = j+dy;
			if(nx >= 0 && nx < n && ny >= 0 
				&& ny<m && field[nx][ny] == 'W')    //记得判断数组是否越界
				dfs(nx,ny);
		}
	}
	return;
}
int main(int argc, char const *argv[]){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> field[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(field[i][j] == 'W'){
				dfs(i,j);
				ans++;
			}
	cout << ans<< endl;
	return 0;
}
```
#### 备注
这道题利用了之前提到的利用**DFS的特性去寻找图上所有的连通分量**的思想，把每一个水洼都看成一个连通图，那么我们在寻找相连的过程时，就相当于找到了一个连通图，**统计水洼个数的过程，就是统计这些连通图的个数**。 

### 2、部分和问题
#### 题目描述
> 给定整数a1,a2...an，判断是否可以从中选出若干数，使他们的和恰好为k

#### 解题思路

这是一道很经典的深搜题目，对于每一次搜索，传入当前数字编号和当前选中的数字之和dfs(i,sum)，起始数据传入dfs(0,0)

在搜索过程中，如果传入的sum值等于k值，直接返回true，表示搜索完成。

对于当前传入的数字，有两种操作方式，即加在sum上和不加在sum上，因此也就引出两个搜索的分支
即dfs(i+1,sum)和dfs(i+1, sum+a[i])

**值得注意的是**，在我们进行深度优先搜索的过程中，一般情况下，我们进入一次搜索之后的第一件事情，就是去判断搜索是否已经结束，也就是说，对于这道题，我们需要的是先去判断我们是否已经走到看数据的末尾，再去判断是否已经达成sum==k的目标。 
另一个重要的思想是，在搜索时，对于每一次传入的节点，我们需要去考虑对于这个节点在搜索有多少种**可能的状态**，对于这个题而言，对于当前位置的数字，它与加和sum的关系只有两种可能，也就是： 

- 被加入sum
- 不被加入sum 

因此对于我们传入的每一个节点，都会引出两条分支，即即dfs(i+1,sum)和dfs(i+1, sum+a[i])

#### 代码实现
```cpp
#include <stdio.h>
int a[20];
int n,k;
bool dfs(int i, int sum){
	if(i == n)
		return sum == k;
	if(dfs(i+1, sum))
		return true;
	if(dfs(i+1, sum + a[i]))
		return true;
	return false;
}
int main(){
	scanf("%d", &n);
	for(int i =0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	if(dfs(0, 0) )	printf("Yes\n");
	else printf("No\n");
	return 0;
}
```

### 3、踩方格问题（回溯）(百炼4103)
#### 题目描述
> 有一个方格矩阵，矩阵边界在无穷远处。我们做如下假设： 
a.每走一步时，只能从当前方格移动一格，走到某个相邻的方格上； 
b.走过的格子立即塌陷无法再走第二次； 
c.只能向北、东、西三个方向走； 
请问：如果允许在方格矩阵上走n步，共有多少种不同的方案。2种走法只要有一步不一样，即被认为是不同的方案。  

#### Input
> 允许在方格上行走的步数n(n <= 20)

#### Output
> 计算出的方案数量

#### 基本思路
把问题放到矩阵中，问题抽象成从矩阵一点出发，每次只能向下或左或右移动一格。
对于每一个点枚举可能的状态，这里运用一点分治的思想，也就是把整体的问题分割成有限个小问题来解决，单就这个题而言，我们可以利用如下方式分解 
**分解问题：**
从$(i,j)$出发，走N步的方案数，等于以下三项之和： 

- 从$(i+1,j)$出发，走n-1步的方案数。前提：$(i+1,j)$没走过 
- 从$(i,j+1)$出发，走n-1步的方案数。前提：$( i,j+1)$没走过 
- 从$(i,j-1)$出发，走n-1步的方案数，前提：$( i,j-1)$没走过 

也就是说，如果下一个格子之前没有走过，我们就可以把走N步的问题变成走N-1步的问题，剩下的要考虑的就是如何处理走N-1步的问题。显而易见的是，整个过程是可以一步一步减少步数的，我们的搜索也就因此而成立。 
**回溯：**
在DFS过程中，每到达一个点，要做的第一件事情就是把这个点的状态标记成已经走过。但是，在每次搜索结束后，我们必须回溯上一次搜索的结果，也就是把当前点再置成未经过的状态。

比如我们在某一次搜索过程中走过了$(i,j)$这个点，那么我们在这一次搜索中都不会再次经过这个点了。但是，当我们完成这一次的搜索，去进行下一次的搜索的时候，这个点必须要置成未被经过的状态，因为这个点在下次搜索仍然可能被重新经过。

#### DFS基础方法小结
对于常见的DFS解决的问题，只需要明确**当前状态到下一状态**有几种可能的转移，每有一种**状态转移**就引出一个dfs分支，**在完成一次搜索过程后回溯把之前标记过的点还原**，就是DFS的基本思路。

**DFS的缺点：**

- 从刚才的题目里也能看出，对于点边较多较复杂的图，递归的深度通常是非常深的，也就直接导致我们的运算时间爆炸式的增长。也就是说，虽然我们可以解决问题，但是可能会消耗大量的时间，无论是在算法竞赛还是实际应用场景中，这都不是我们希望的结果。 

因此需要引入针对DFS的优化技巧，从而达到减少搜索分支，提高算法速度的效果。



## DFS优化技巧

对于DFS问题，最常见的优化方案就是**剪枝和记忆化**，下面结合一道比较复杂的DFS问题进行考虑：

### POJ1724 Roads

#### 题目描述
> N cities named with numbers 1 ... N are connected with one-way roads. Each road has two parameters associated with it : the road length and the toll that needs to be paid for the road (expressed in the number of coins). 
Bob and Alice used to live in the city 1. After noticing that Alice was cheating in the card game they liked to play, Bob broke up with her and decided to move away - to the city N. He wants to get there as quickly as possible, but he is short on cash. 
We want to help Bob to find the shortest path from the city 1 to the city N that he can afford with the amount of money he has. 

#### Input
> The first line of the input contains the integer **K**, 0 <= K <= 10000, **maximum number of coins that Bob can spend on his way**. 
The second line contains the integer **N**, 2 <= N <= 100, **the total number of cities**. 
The third line contains the integer **R**, 1 <= R <= 10000, **the total number of roads**. 
Each of the following R lines describes one road by specifying integers S, D, L and T separated by single blank characters : 
**S** is the source city, 1 <= S <= N 
**D** is the destination city, 1 <= D <= N 
**L** is the road length, 1 <= L <= 100 
**T** is the toll (expressed in the number of coins), 0 <= T <=100
Notice that different roads may have the same source and destination cities.  

#### Output
> The first and the only line of the output should contain the total length of the shortest path from the city 1 to the city N whose total toll is less than or equal K coins. 
If such path does not exist, only number -1 should be written to the output.   

### 题目大意

N个城市，编号1到N。城市间有R条单向道路。 
每条道路连接两个城市，有长度和过路费两个属性。 
Bob有K块钱，他想从城市1走到城市N。问最短共需要走多长的路。如果到不了N，输出-1

2 <= N <=100 
0 <= K <= 10000 
1 <= R <= 10000 
每条路的长度L, 1 <= L <= 100 
每条路的过路费, 0 <= T <= 100  

### 直接DFS思路

从城市1开始进行dfs遍历整张地图，找到所有能够到N城市的走法，选择其中最短的一条。

整个DFS过程可以简要描述为：

- 传入参数s表示从s处开始搜索

- 如果已经到达目的地N城市，比较当前路径长度和最小长度，取最小值。

- 对于每一条以s城为起点的道路，判断过路费是否足够通过这条道路，如果不行就直接考虑下一个相连道路

- 若可以通过，则可进一步进行判断，看之前是否没有经过过该城市，若之前没有经过过该城市，则令

  更新距离和路费，并记录已经过该城市。

- 对下一个起点进行dfs搜索

- 回溯信息，恢复途经信息，距离信息和路费信息。

##### 使用的数据结构
```cpp
int K, N, R;                    //bob身上的钱，城市数量，路的数量
struct  Road{                   
	int d, L, t;  
	//定义结构体road,d表示这条路指向的城市编号,L表示这条路的长度,t表示这条路的过路费
};
vector< vector< Road> > G(110); //G[i]表示从i出发能够直接到达的所有城市
int minlen;					//最短路径
int totallen;				//当前已走路径
int totalcost;				//当前已花费金额
int visited[110];			//标记是否走过该城市
```
##### 主函数
```cpp
int main(int argc, char const *argv[]){
	scanf("%d %d %d", &K, &N, &R);
	for(int i = 0; i < R; i++){
		int s;
		Road r;
		scanf("%d %d %d %d", &s, &r.d, &r.L, &r.t);
		if(s != r.d)				//去掉自环
			G[s].push_back(r);
	}
	memset(visited,0,sizeof(visited));
	minlen = 1e9;
	dfs(1);
	if(minlen != 1e9)
		printf("%d\n", minlen);
	else
		printf("-1\n");
	return 0;
}
```
主函数的主要内容如下：

- 按照题目要求把数据读入，把每条路的信息存放在以起点为下标的vector里，利用邻接表存放图的信息。
- 把visited数组置成0，表示我们没有到过任何一个城市。
- 给minlen一个很大的值，便于我们更新最小值。
- 从1节点开始进行搜索，并在搜索结束后输出minlen。 

**值得注意的一点是**，在读入数据的时候去掉了自环，因为我们稍微想一下也就能明白，自环的存在只会让我们在这个城市绕上一圈，白白花费钱和路程，因此我们在输入的时候就直接去掉这种特殊情况。

##### 基础DFS写法
```cpp
void dfs(int s){
//传入参数s表示从s处开始搜索
	if(s == N){
	//如果已经到达目的地N城市，比较当前路径长度和最小长度，取最小值。
		minlen = min(minlen, totallen);
		return;
	}
	for(int i = 0; i < G[s].size(); i++){
		Road r = G[s][i];
        //对于每一条以s城为起点的道路，首先判断过路费是否足够通过这条道路，如果不行就直接continue
		if(totalcost + r.t > K)		
			continue;
		if(!visited[r.d]){
			visited[r.d] = 1;       //标记信息
			totalcost += r.t;
			totallen += r.L;
			dfs(r.d);               //从路径终点开始进行下一次搜索
			visited[r.d] = 0;       //回溯信息
			totallen -= r.L;
			totalcost -= r.t;
		}
	}
}
```
#### 存在的问题

这样的写法已经可以让我们解决这个问题，但是作为一道时间限制为1s的题目，这种写法离正确答案还有些遥远，事实上，这种写法到了数据量为几百的规模下，就可能需要几分钟甚至几十分钟才能计算出结果了。因此我们引入**剪枝**的概念。

### 剪枝优化DFS
所谓的剪枝，就是在**递归搜索的过程中人为的加入一些判断条件，从而减少一些不必要的运算**。 
**剪枝思路：**

- **如果当我们到达某一个点的时候，我们统计的当前所走的路径长度已经超过了之前找到的最短的路径长度，之后的运算就都没有必要进行了**，这会省下大量的运算。 

加入剪枝后的算法如下：

```c++
void dfs(int s){
	if(s == N){
		minlen = min(minlen, totallen);
		return;
	}
	for(int i = 0; i < G[s].size(); i++){
		Road r = G[s][i];
		if(totalcost + r.t > K)	//判断走到下一个城市的钱是否够用
			continue;
		if(totallen + r.L >= minlen)		//剪枝：如果当前已经找到的最优路径为L，那么在继续搜索的过程中，若总长度大于等于L，则直接放弃
			continue;
		if(!visited[r.d]){
			visited[r.d] = 1;
			totalcost += r.t;
			totallen += r.L;
			dfs(r.d);
			visited[r.d] = 0;
			totallen -= r.L;
			totalcost -= r.t;
		}
	}
}
```

#### 优化效果
经过刚才的剪枝，整个程序的运行时间会大幅的缩减，对于一些要跑很久的数据可能很快就能得出结果。大概估计一下的话，在**1000到2000之间数据都可以通过测试**，但是在数据量达到10000的条件下，这种剪枝仍然不够使算法足够优秀。
因此，对于本题而言，代码任然不够优化，在oj上，这道题给的时间限制是1秒，也就是说我们还需要对运算进行进一步的优化。 
从直观上来看，我们可以想到，**在不考虑路费的情况下，如果我们到达同一个点花费的路程比之前到达这个点所花费的最短路程要长，那么我们就应该认为这种方案一定不是最优解，应当舍弃**。由此我们引入**记忆化**的概念。  

### 记忆化优化DFS
**记忆化搜索，是指在搜索过程中记录一部分运算结果，从而对后续的运算进行最优性剪枝的操作。** 与动态规划求解递归问题的思路类似，本质是为了避免多次重复运算。

**记忆化思路：**

- **在花费相同的钱走并且到相同的位置的时候，如果此时的路径长度超过当前记录的最小值的时候**，直接放弃。 

**代码优化方法：**

- 引入一个二维数组minL\[110][10005]在这个二维数组中，minL\[k][m]表示走到城市k时，在总过路费为m的条件下，最优路径的长度。 初始化为无穷大。
- 接着在最优化剪枝后加入新的操作，使得在花费相同的钱走到相同的位置的时候，如果此时的路径长度超过当前记录的最小值的时候，直接放弃。 
- 若没有舍弃，则将新的数据写入该二维数组，为之后的操作提供基础。

第二次改写后的dfs函数如下
```cpp
void dfs(int s){
	if(s == N){
		minlen = min(minlen, totallen);
		return;
	}
	for(int i = 0; i < G[s].size(); i++){
		Road r = G[s][i];
		if(totalcost + r.t > K)	//判断走到下一个城市的钱是否够用
			continue;
        //剪枝：如果当前已经找到的最优路径为L，那么在继续搜索的过程中，若总长度大于等于L，则直接放弃
		if(totallen + r.L >= minlen)		
			continue;
		if(!visited[r.d]){
      // 记忆化： 在花费相同的钱走到相同的位置的时候，如果此时的路径长度超过当前记录的最小值的时候，直接放弃
			if(totallen + r.L >= minL[r.d][totalcost + r.t]) 
				continue;
            // 	记录花费当前钱数走到的当前城市所需的最小路径的长度。
			minL[r.d][totalcost+r.t] = totallen + r.L;		
			visited[r.d] = 1;
			totalcost += r.t;
			totallen += r.L;
			dfs(r.d);
			visited[r.d] = 0;
			totallen -= r.L;
			totalcost -= r.t;
		}
	}
}
```

### 完成优化
![image](http://www.bbbbchan.com/wp-content/uploads/2018/11/图片3.png)
经过两次优化尝试后，这一次的提交就可以通过这道题目。可以看到，经过我们的优化过程，程序运行时间由最初的超时到现在的188毫秒，可以说有了大幅度的提升，这也说明了剪枝和记忆化在搜索过程中的重要性。 



## 总结

本篇文章主要介绍了深度优先搜索的基本概念及其常见优化方法。

在文章的第一部分，除了介绍了DFS的基本概念外，还针对其常见应用场景给出了三道例题，分别从连通分量计数、分支搜索以及搜索回溯三个方面给出了深度优先搜索在该场景下的思路和编码。

在文章的第二部分，通过一道较复杂的深度优先搜索问题，引入了搜索剪枝和记忆化搜索的概念。针对具体问题提出了明确的剪枝方案和记忆化方案，使得程序整体运行时间大大降低。这两种优化方法也是针对深度优先搜索问题常见的优化思路，在大部分深度优先搜索过程中均有应用。

总而言之，深度优先搜索作为一种传统的经典搜索算法，其能够获取目标图结构的拓扑排序表的特性，使其可以解决很多图论相关的问题，特别是需要获取所有可能路径的问题。在现实应用中，由于其易于编写和理解的特点，深度优先搜索在网络爬虫，拓部结构中都有很好的表现。







