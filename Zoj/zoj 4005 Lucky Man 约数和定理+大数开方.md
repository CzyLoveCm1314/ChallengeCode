# [zoj 4005] Lucky Man 约数和定理+大数开方

**Time Limit**: 2 Seconds      **Memory Limit**: 65536 KB

​	BaoBao is keen on collection. Recently he is abandoning himself to Kantai Collection, especially to collecting cute girls, known as "Fleet Girls".

![img](http://acm.zju.edu.cn/onlinejudge/showImage.do?name=2018monthly.Kantai_Collection_sample_cards.jpg)

​	There are  various types of girls in the game. To get a girl, one can use some materials to build her. The probability to get a type of girl by building is the same for all types of girls. From the [Coupon Collector's Problem](https://en.wikipedia.org/wiki/Coupon_collector%27s_problem) we know that, to collect all types of girls, the expected number of times of building is  $ \sum_{i=1}^n \frac{n}{n-i+1}​$.

​	But this rule does not apply to BaoBao, as he is always luckier than the ordinary players (maybe because he's an European). For BaoBao to collect all types of girls, the expected number of times of building is $\sum_{i=1}^n \lfloor\frac{n}{n-i+1}\rfloor$ , where  means the maximum integer that doesn't exceed .

​	As a lucky man, BaoBao is not interested in the actual value of , and he just wants to know whether  is odd or even. Can you help him?

#### Input

The first line of the input is an interger  (about 100), indicating the number of test cases. For each test case:

The first line contains an integer  (), indicating the number of types of girls.

#### Output

For each test case, if  is odd output "1" (without quotes), if  is even output "0" (without quotes).

#### Sample Input

```
9
2
3
23
233
2333
23333
233333
2333333
23333333
```

#### Sample Output

```
1
1
0
1
0
0
1
1
0
```

------

**Author**: ZHAO, Jinglin

**Source**: ZOJ Monthly, March 2018



​	之前做数学题，都是感觉大概对就差不多了，比赛打多了之后，还是做不出数学题。这道题目我转换式子了很久，但是还是不会做，还好队友@lzx把我带飞了。

### 思路

​	即判断$\sum_{i=1}^n \lfloor\frac{n}{n-i+1}\rfloor$（1）的==奇偶性==。

​	从式子的角度分析，$\sum_{i=1}^n \lfloor\frac{n}{n-i+1}\rfloor$$$\iff$$$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor$（2），最开始我并不理解，不过我在写了几个样例之后发现的确是这样子的。这两个式子的数学含义是，$\sum_{i=1}^n \lfloor\frac{n}{n-i+1}\rfloor$从==n到1的顺序==，$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor$是==1到n的顺序==，因此我们得到式子$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor$。

​	然后我们进行分析式子$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor​$，这个式子有什么数学含义。因为在比赛的时候（1）和（2）只是顺序不同，我分析了很久并不能作出有效的转化，但是队友@lzx分析出这是求，<u>1到n这n个数中，所有因数的个数</u>。当然，在赛场上我并没有理解，因此现在来仔细思考。

​	举一个例子$n=5$，当$i=1$的时候，$\lfloor5/1\rfloor=5$，意味着$1,2,3,4,5$这五个数中约数$1$有5个。

​	接下来，$i=2$的时候，$\lfloor5/2\rfloor=2$，意味着$1,2,3,4,5$这五个数中约数$2$有2个，观察得出，2,4的约数有2个，符合情况。

​	$i=3$的时候，$\lfloor5/3\rfloor=1$，意味着$1,2,3,4,5$这五个数中约数$3$有1个，观察得出，3的约数有1个，符合情况。

​	其他情况，以此类推，所以得出<u>$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor​$是求1...n这n个数中的约数个数和</u>。

### 约数个数定理和约数和定理

​	因为涉及到了约数个数，不得不提到==小学奥赛==的这个约数个数定理。

​	对于一个大于1正整数n可以分解质因数：$n=p_1^{a_1} *p_2^{a_2}* p_3^{a_3} ……*p_k^{a_k}​$，则n的正约数个数为$(a_1+1)*(a_2+1)*(a_3+1)……*（a_k+1）​$个。

​	记$d(n)​$为$n​$的约数个数，则$\sum_{i=1}^n \lfloor\frac{n}{i}\rfloor=\sum_{i=1}^n d(i)​$，因此只用判断$\sum_{i=1}^n d(i)​$奇偶性。

​	由于$n=p_1^{a_1} *p_2^{a_2}* p_3^{a_3} ……*p_k^{a_k}$，则$d(n)=(a_1+1)*(a_2+1)*(a_3+1)……*（a_k+1）$，则$d(n)$若为奇数，则$a_1,a_2,a_3……a_k​$均为偶数才行。

​	若$a_1,a_2,a_3……a_k​$均为偶数，则显然$n​$是一个完全平方数。

​	因为我们经过一系列转换，求的是$\sum_{i=1}^n d(i)$的奇偶性，因此要去找$d(i)$为奇数的个数，推出$\sum_{i=1}^n d(i)的奇偶性等价于d(i)(i=1……n)中的完全平方数的个数的奇偶性$，因此从$1……n$中完全平方数的数量为$\lfloor \sqrt{n}\rfloor$，因此只需要判断$\lfloor \sqrt{n}\rfloor$的奇偶性。



​	本来以为这个题目就完了，也不需要大数，也不需要什么高精c++板子，用python直接开根号就完事了(结果sqrt似乎不能处理超大数，无限非0返回)。



### 开根号

​	当时队友给的参考网址：https://blog.csdn.net/yjpyjp2014/article/details/52132295。

​	当然赛后自学了，只会牛顿迭代法，求出根号a的近似值：首先随便猜一个近似值x，然后不断令x等于x和a/x的平均数，迭代个六七次后x的值就已经相当精确了。这个链接中 “古老的中国技术”，好像高中数竞老师讲过，然是已经忘了。

​	当然高精度的情况下，还是要用“古老的中国方法”。

```c++
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
char p[100000];
int num=0;
int l;
int work(int o,char *O,int I)
{
    char c, *D=O ;
    if(o>0)
    {
        for(l=0;D[l];D[l++]-=10)
        {
            D[l++]-=120;
            D[l]-=110;
            while(!work(0,O,l))
                D[l]+=20;
            p[num++]=((D[l]+1032)/20);
        }
        //p[num++]=10;
    }
    else
    {
        c=o+(D[I]+82)%10-(I>l/2)*(D[I-l+I]+72)/10-9;
        D[I]+=I<0 ? 0 : !(o=work(c/10,O,I-1))*((c+999)%10-(D[I]+92)%10);
    }
    return o;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        num=0;
        char s[1200];s[0]='0';
        scanf("%s",s+1);
        if(strlen(s)%2 == 1)
            work(2,s+1,0);
        else
            work(2,s,0);
        if((p[num-1]-'0')%2==1)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    
    return 0;
}
```

以上代码，板子来源于另一位大佬：https://www.cnblogs.com/vainglory/p/8549201.html?tdsourcetag=s_pcqq_aiomsg。