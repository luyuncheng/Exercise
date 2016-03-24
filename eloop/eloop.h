////
//// Created by 鲁蕴铖 on 16/3/24.
////
//
//#ifndef CPP_LYC_ELOOH_H
//#define CPP_LYC_ELOOH_H
//
//#endif //CPP_LYC_ELOOH_H
//
///**
// * eloop_sock_handler - eloop socket event callback type
// * @sock: socket的文件描述符
// * @eloop_ctx: 注册了的回调函数数据eloop_data
// * @sock_ctx: 注册了的回调函数数据 user_data
// */
//typedef void (*eloop_sock_handler)(int sock, void *eloop_ctx, void *sock_ctx);
//
///**
// * eloop_timeout_handler - eloop timeout event callback type
// * @eloop_ctx: Registered callback context data (eloop_data)
// * @sock_ctx: Registered callback context data (user_data)
// */
//typedef void (*eloop_timeout_handler)(void *eloop_data, void *user_ctx);
//
///**
// * eloop_signal_handler - eloop signal event callback type
// * @sig: Signal number
// * @signal_ctx: Registered callback context data (user_data from
// * eloop_register_signal(), eloop_register_signal_terminate(), or
// * eloop_register_signal_reconfig() call)
// */
//typedef void (*eloop_signal_handler)(int sig, void *signal_ctx);