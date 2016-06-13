////
//// Created by 鲁蕴铖 on 16/6/13.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <time.h>
//using namespace std;
//
//#define TASK_NUM 10
///*
//task manager question;
//input:
//n tasks needs 1 time sets:S{a1,a2,,,an}
//n int deadline time D{d1,d2,,,dn},we expect task ai have  been done before di;
//n punish time W{w1,w2,,,wn},if ai haven't been done before di,get wi punish;
//*/
//
//
//typedef struct task {
//	int key;
//	int deadline;
//	int punish;
//}task;
//
//int cmp(const struct task &a1, const struct task &a2) {
//	return a1.punish > a2.punish;
//}
//
//int check(task *A) {
//	vector<int> time;
//	vector<task> drop;
//	vector<pair<int,int> > seq;
//	int punish = 0;
//	for (int i = 1; i <= 100; i++) {
//		time.push_back(i);
//	}
//	for (int i = 0; i < TASK_NUM; i++) {
//		int deadline = A[i].deadline;
//		/*vector<int>::iterator it;*/
//		vector<int>::iterator it = upper_bound(time.begin(), time.end(), deadline);
//
//		if(it != time.end() && it != time.begin())
//			it = prev(it);
//
//		if (*it > deadline) {
//			cout << "drop" << A[i].key << " " << A[i].punish << endl;
//			drop.push_back(A[i]);
//		} else {
//			seq.push_back(make_pair(A[i].key,*it));
//			time.erase(it);
//		}
//
//	}
//	cout<< "Select:" <<endl;
//	for (int i = 0; i < seq.size(); i++) {
//		cout << "No:" << seq[i].first << "  time:" << seq[i].second << endl;
//	}
//	cout<<" Drop:" <<drop.size()<<endl;
//	for (int i = 0; i < drop.size(); i++) {
//		cout << "key:" << drop[i].key << endl;
//		punish += drop[i].punish;
//	}
//	cout << "punish:\t" << punish << endl;
//	return 0;
//}
//int main()
//{
//	task A[TASK_NUM];
//	srand(time(0));
//	for (int i = 0;i < TASK_NUM;i++)
//	{
//		A[i].key = i;
//		A[i].deadline = rand() % 10 + 1;
//		A[i].punish = rand() % 100 + 1;
//		cout << "key: " <<A[i].key << "\tdeadline: " <<A[i].deadline << "\tpunish: " << A[i].punish <<"\n";
//	}
//	sort(A, A + TASK_NUM, cmp);
//	check(A);
//}