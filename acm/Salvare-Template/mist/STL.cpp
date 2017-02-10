#include<bits/stdc++.h>


#include<tr1/unordered_map>
using namespace tr1;
unordered_map<int,int>mp;


partial_sort(a,a+m,a+n,cmp);

nth_element(a,a+m,a+n,cmp);
//第m大元素(从0开始数)，然后访问a[m]


bitset(支持位运算)
b.any()  //b中是否存在置为1的二进制位
b.none()  //b中不存在置为1的二进制位吗？
b.count()  //b中置为1的二进制位的个数
b.size()  //b中二进制位的个数
b.set()  //把b中所有二进制位都置为1
b.set(pos)  //把b中在pos处的二进制位置为1
b.reset()  //把b中所有二进制位都置为0
b.reset(pos)  //把b中在pos处的二进制位置为0
b.flip()  //把b中所有二进制位逐位取反
b.flip(pos)  //把b中在pos处的二进制位取反
b.to_ulong()  //用b中同样的二进制位返回一个unsigned long值
os << b  //把b中的位集输出到os流
 
