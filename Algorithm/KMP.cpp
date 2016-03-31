////
//// Created by 鲁蕴铖 on 16/3/31.
////
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int maxn=100;
//int nextval[maxn];
//int nextval2[maxn];
//void initnextval(char *p)
//{
//	nextval[0]=-1;
//	int j=-1;
//	int len=strlen(p);
//	for(int i=1;i<len;i++){
//		while(j!=-1 && (p[j+1]!=p[i])) {
//			j=nextval[j];
//		}
//		if(p[j+1]==p[i]) ++j;
//
//		nextval[i]=j;
//	}
//}
//void find(char *s,char *p)
//{
//	int j=-1;
//	int n=strlen(s);
//	int m=strlen(p);
//	for(int i=0;i<n;i++) {
//		while(j>=0 && (p[j+1]!=s[i])) {
//			j=nextval[j];
//		}
//		if(p[j+1]==s[i])++j;
//		if(j==m-1)
//		{
//			printf("occurs :%d\n",i-m+1);
//			j=nextval[j];
//			//return 1;
//		}
//	}
//}
//
//void GetNext(char* p)
//{
//    int pLen = strlen(p);
//    nextval2[0] = -1;
//    int k = -1;
//    int j = 0;
//    while (j < pLen - 1)
//    {
//        //p[k]表示前缀，p[j]表示后缀
//        if (k == -1 || p[j] == p[k])
//        {
//            ++j;
//            ++k;
//            //较之前next数组求法，改动在下面4行
//            if (p[j] != p[k])
//                nextval2[j] = k;   //之前只有这一行
//            else
//                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
//                nextval2[j] = nextval2[k];
//        }
//        else
//        {
//            k = nextval2[k];
//        }
//    }
//}
//
//int KmpSearch(char* s, char* p)
//{
//    int i = 0;
//    int j = 0;
//    int sLen = strlen(s);
//    int pLen = strlen(p);
//    while (i < sLen && j < pLen)
//    {
//        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
//        if (j == -1 || s[i] == p[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
//            //next[j]即为j所对应的next值
//            j = nextval2[j];
//        }
//    }
//    if (j == pLen){
//    	printf("search2 occurs: %d\n",i-j);
//    	return i-j;
//    }
//    else
//        return -1;
//}
//int main()
//{
//	char s[]="mississippi";
//	char p[]="issip";
//	memset(nextval,0,sizeof(nextval));
//	memset(nextval2,0,sizeof(nextval2));
//	initnextval(p);
//	//GetNext(p);
//	for(int i=0;i<7;i++)
//		printf("%2c ",p[i]);
//	cout<<endl;
//	for(int i=0;i<7;i++)
//		printf("%2d ", nextval[i]);
//	cout<<endl;
//	for(int i=0;i<7;i++)
//		printf("%2d ", nextval2[i]);
//	cout<<endl;
//	find(s,p);
//	KmpSearch(s,p);
//}