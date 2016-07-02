////
//// Created by 鲁蕴铖 on 16/6/29.
////
//
//#include <signal.h>
//#include <iostream>
//#include "stdio.h"
//
//typedef void Sigfunc(int);
//
//Sigfunc *siganl(int signo, Sigfunc *func)
//{
//    struct sigaction act,oact;
//    act.__sigaction_u.__sa_handler = func;
//    sigemptyset(&act.sa_mask);
//    act.sa_flags = 0;
//    if(signo == SIGALRM) {
//#ifdef SA_INTERRUPT
//        act.sa_flags |= SA_INTERRUPT;
//#endif
//    } else {
//#ifdef SA_RESTART
//        act.sa_flags |= SA_RESTART;
//#endif
//    }
//    if(sigaction(signo, &act, &oact) < 0)
//        return (SIG_ERR);
//    return (oact.__sigaction_u.__sa_handler);
//}
//
//signal(SIGCHLD, sig_chld);
///*
//void sig_chld(int signo) {
//    pid_t pid;
//    int stat;
//
//    pid = wait(&stat);
//    printf("child %d terminated\n",pid);
//    return;;
//}*/
//void sig_chld(int signo) {
//    pid_t pid;
//    int stat;
//    while( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
//        printf("child %d terminated\n",pid);
//    return;
//}
