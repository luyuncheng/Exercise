////
//// Created by 鲁蕴铖 on 16/3/24.
////
//
//
///**
// * eloop_event_type - eloop socket event type for eloop_register_sock()
// * @EVENT_TYPE_READ: Socket has data available for reading
// * @EVENT_TYPE_WRITE: Socket has room for new data to be written
// * @EVENT_TYPE_EXCEPTION: An exception has been reported
// */
//
//
////eloop 的socket数据
//struct eloop_sock
//{
//    /* data */
//    int sock;
//    void *eloop_data;
//    void *user_data;
///**
// * eloop_sock_handler - eloop socket event callback type
// * @sock: File descriptor number for the socket
// * @eloop_ctx: Registered callback context data (eloop_data)
// * @sock_ctx: Registered callback context data (user_data)
// */
//    eloop_sock_handler handler;
//};
//
////eloop 的超时数据
//struct eloop_timeout
//{
//    struct dl_list list;
//    struct os_time time;
//    void *eloop_data;
//    void *user_data;
///**
// * eloop_timeout_handler - eloop timeout event callback type
// * @eloop_ctx: Registered callback context data (eloop_data)
// * @sock_ctx: Registered callback context data (user_data)
// */
//    eloop_timeout_handler handler;
//};
//
////eloop 的信号数据
//struct eloop_signal
//{
//    int sig;
//    void *user_data;
///**
// * eloop_signal_handler - eloop signal event callback type
// * @sig: Signal number
// * @signal_ctx: Registered callback context data (user_data from
// * eloop_register_signal(), eloop_register_signal_terminate(), or
// * eloop_register_signal_reconfig() call)
// */
//    eloop_signal_handler handler;
//
//};
//
////eloop 的socket表
//struct eloop_sock_table
//{
//    /* data */
//    int count;
//    //eloop_sock的数组
//    struct eloop_sock *table;
//    int changed;
//};
//
////eloop 数据
//struct eloop_data
//{
//    /* data */
//    int max_sock;
//    // 统计所有的表的总和
//    int count;
//
////eloop_sock表的三个表示 socket_table数据
//    struct eloop_sock_table readers;
//    struct eloop_sock_table writers;
//    struct eloop_sock_table exceptions;
//
////超时数据 dl_list 为双向链表
//    struct dl_list timeout;
//
////信号数据
//    //信号个数
//    int signal_count;
//    //信号数据数组
//    struct eloop_signal *signals;
//    //信号标记，是否有信号来
//    int signaled;
//    //pending中止？
//    int pending_terminate;
//
////中止信号？
//    int terminate;
////读表改变标记
//    int reader_table_changed;
//};
//
//static struct eloop_data eloop;
//
//#ifdef WPA_TRACE
//
//static void eloop_sigsegv_handler(int sig)
//{
//	wpa_trace_show("eloop SIGSEGV");
////有segment fault错误中断 就异常终止程序
//	abort();
//}
//#else
//
//#define eloop_trace_sock_add_ref(table) do { } while (0)
//#define eloop_trace_sock_remove_ref(table) do { } while (0)
//
//#endif /* WPA_TRACE */
//
////初始化eloop事件
///**
// * eloop_init() - Initialize global event loop data
// * Returns: 0 on success, -1 on failure
// *
// * This function must be called before any other eloop_* function.
// */
//int eloop_init(void)
//{
//    os_memset(&eloop,0,sizeof(eloop));
//    //双向链表初始化(把自己的指针赋值給next和prev)
//    dl_list_init(&eloop.timeout);
//    //注册了追踪就把段错误处理函数注册进去
//#ifdef WPA_TRACE
//    signal(SIGSEGV, eloop_sigsegv_handler);
//#endif
//    return 0;
//}
//
////socket表加入sockt
//// 往table里面加入一个eloop_sock数据
////第一个参数为table表
////第二个参数为文件描述符
////第三个为传入的为sock事件的回调函数
////第4，5个参数分别为两个需哟的数据
//static int eloop_sock_table_add_sock(struct eloop_sock_table *table,
//                                     int sock, eloop_sock_handler handler,
//                                     void *eloop_data, void *user_data)
//{
//    struct eloop_sock *tmp;
//    int new_max_sock;
////最大文件描述符
//    if(sock > eloop.max_sock) new_max_sock=sock;
//    else  					  new_max_sock=eloop.max_sock;
//
//    if(table = NULL)	return -1;
//
//    //ELOOP_POLL这种方法忽略
//
//    eloop_trace_sock_remove_ref(table);
////为table分配一个数组空间，空间长度为count＋1 每个位置大小为一个结构体的eloop_sock大小
////这个里面会调用os_realloc  它是重新分配动态内存，其本质就是重新开一个，把原有的copy 在free  由于不同系统操作不一样，所以封装了接口
//    tmp = os_realloc_array(table->table, table->count+1, sizeof(struct elop_sock));
//
//    if(tmp == NULL) return -1;
//
////数据赋值
//    tmp[table->count].sock=sock;
//    tmp[table->count].eloop_data=eloop_data;
//    tmp[table->count].user_data = user_data;
//    tmp[table->count].handler = handler;
//
//    table->count++;
//    table->table=tmp
//
//    eloop.max_sock = new_max_sock;
//    eloop.count++;
//    table->changed=1;
//
//    eloop_trace_sock_add_ref(table);
//
//    return 0;
//}
//
////从table里面移除sock
//static void eloop_sock_table_remove_sock(struct eloop_sock_table *table, int sock)
//{
//    int i;
//    if (table == NULL || table->table == NULL || table->count == 0)	return;
//
//    for(i = 0; i < table->count; i++){
//        if(table->table[i].sock == sock)
//            break;
//    }
//    if(i == table->count)
//        return;
//
//    eloop_trace_sock_remove_ref(table);
//
//    if(i != table->count-1){
//        //os_memmove 是把第二个参数的数据移动 n个byte(第三个参数) 到第一个参数
//        os_memmove(&table->table[i], &table->table[i+1], (table->count-i-1)*sizeof(struct eloop_sock));
//    }
//    table->count--;
//    eloop.count--;
//    table->changed = 1;
//    eloop_trace_sock_add_ref(table);
//}
//
////为table表设置文件表示符
//static void eloop_sock_table_set_fds(struct eloop_sock_table *table, fd_set *fds)
//{
//    int i;
//
//    FD_ZERO(fds);
//
//    if (table->table == NULL)
//        return;
//    //給每个table里面的每个的sock设置到fds里面
//    for (i = 0; i < table->count; i++)
//        FD_SET(table->table[i].sock, fds);
//}
//
////eloop 表中socket的事件分发
//static void eloop_sock_table_dispatch(struct eloop_sock_table *table,
//                                      fd_set *fds)
//{
//    int i;
//
//    if (table == NULL || table->table == NULL)
//        return;
//
//    table->changed = 0;
//    //轮询查table中的sock是否在描述符集合里面，然后分发调用处理函数
//    for (i = 0; i < table->count; i++) {
//        if (FD_ISSET(table->table[i].sock, fds)) {
//            table->table[i].handler(table->table[i].sock,
//                                    table->table[i].eloop_data,
//                                    table->table[i].user_data);
//            //如果执行过程中改变了表要跳出来
//            if (table->changed)
//                break;
//        }
//    }
//}
//
////表的析构
//static void eloop_sock_table_destroy(struct eloop_sock_table *table)
//{
//    if (table) {
//        int i;
//        //这里都是输出信息
//        for (i = 0; i < table->count && table->table; i++) {
//            wpa_printf(MSG_INFO, "ELOOP: remaining socket: "
//                               "sock=%d eloop_data=%p user_data=%p "
//                               "handler=%p",
//                       table->table[i].sock,
//                       table->table[i].eloop_data,
//                       table->table[i].user_data,
//                       table->table[i].handler);
//            wpa_trace_dump_funcname("eloop unregistered socket "
//                                            "handler",
//                                    table->table[i].handler);
//            wpa_trace_dump("eloop sock", &table->table[i]);
//        }
//        //直接free掉表
//        os_free(table->table);
//    }
//}
//
////得到sock表 主要是給三个不同事件的指针表
//static struct eloop_sock_table *eloop_get_sock_table(eloop_event_type type)
//{
//    switch (type) {
//        case EVENT_TYPE_READ:
//            return &eloop.readers;
//        case EVENT_TYPE_WRITE:
//            return &eloop.writers;
//        case EVENT_TYPE_EXCEPTION:
//            return &eloop.exceptions;
//    }
//
//    return NULL;
//}
//
////注册一个sock事件，这个事件类型有参数type指定，对于不同类型放到不同的事件sock表里面去
///**
// * eloop_register_sock - Register handler for socket events
// * @sock: File descriptor number for the socket
// * @type: Type of event to wait for
// * @handler: Callback function to be called when the event is triggered
// * @eloop_data: Callback context data (eloop_ctx)
// * @user_data: Callback context data (sock_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register an event notifier for the given socket's file descriptor. The
// * handler function will be called whenever the that event is triggered for the
// * socket. The handler function is responsible for clearing the event after
// * having processed it in order to avoid eloop from calling the handler again
// * for the same event.
// */
//int eloop_register_sock(int sock, eloop_event_type type,
//                        eloop_sock_handler handler,
//                        void *eloop_data, void *user_data)
//{
//    struct eloop_sock_table *table;
////首先获取表的类别
//    table = eloop_get_sock_table(type);
////然后加入进去，这个函数在前面说过了
//    return eloop_sock_table_add_sock(table, sock, handler,
//                                     eloop_data, user_data);
//}
//
////为sock注册一个读事件
///**
// * eloop_register_read_sock - Register handler for read events
// * @sock: File descriptor number for the socket
// * @handler: Callback function to be called when data is available for reading
// * @eloop_data: Callback context data (eloop_ctx)
// * @user_data: Callback context data (sock_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register a read socket notifier for the given file descriptor. The handler
// * function will be called whenever data is available for reading from the
// * socket. The handler function is responsible for clearing the event after
// * having processed it in order to avoid eloop from calling the handler again
// * for the same event.
// */
//int eloop_register_read_sock(int sock, eloop_sock_handler handler,
//                             void *eloop_data, void *user_data)
//{
//    return eloop_register_sock(sock, EVENT_TYPE_READ, handler,
//                               eloop_data, user_data);
//}
//
////注销一个sock 类型也是参数传的，然后remove_sock前面写了
///**
// * eloop_unregister_sock - Unregister handler for socket events
// * @sock: File descriptor number for the socket
// * @type: Type of event for which sock was registered
// *
// * Unregister a socket event notifier that was previously registered with
// * eloop_register_sock().
// */
//void eloop_unregister_sock(int sock, eloop_event_type type)
//{
//    struct eloop_sock_table *table;
//
//    table = eloop_get_sock_table(type);
//    eloop_sock_table_remove_sock(table, sock);
//}
//
////注销一个读sock
///**
// * eloop_unregister_read_sock - Unregister handler for read events
// * @sock: File descriptor number for the socket
// *
// * Unregister a read socket notifier that was previously registered with
// * eloop_register_read_sock().
// */
//void eloop_unregister_read_sock(int sock)
//{
//    eloop_unregister_sock(sock, EVENT_TYPE_READ);
//}
//
//
////注册一个时间处理事件
////第一个参数为还有多少时间结束
////第二个参数为微秒时间结束 用了的时间？？？？
////第三个参数为时间结束处理函数
////第四，五个参数为数据
///**
// * eloop_register_timeout - Register timeout
// * @secs: Number of seconds to the timeout
// * @usecs: Number of microseconds to the timeout
// * @handler: Callback function to be called when timeout occurs
// * @eloop_data: Callback context data (eloop_ctx)
// * @user_data: Callback context data (sock_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register a timeout that will cause the handler function to be called after
// * given time.
// */
//int eloop_register_timeout(unsigned int sec, unsigned int usecs,
//                           eloop_timeout_handler handler,
//                           void *eloop_data, void *user_data)
//{
//    struct eloop_timeout *timeout, *tmp;
//    //long型数据 当前时间
//    os_time_t now_sec;
//
//    timeout = os_zalloc(sizeof(*timeout));
//    if (timeout == NULL) return -1;
//
////os_get_time是得到当前时间，sec表示，传入的值为buffer指针
//    if (os_get_time(&timeout->time) < 0) {
//        os_free(timeout);
//        return -1;
//    }
//
//    now_sec = timeout->time.sec;
//    //申请的时间＋还有多少时间要结束
//    timeout->time.sec += secs;
//    //如果申请的时间＋结束的时间小于当前时间就表示分配时间不够
//    if (timeout->time.sec < now_sec) {
//        /*
//         * Integer overflow - assume long enough timeout to be assumed
//         * to be infinite, i.e., the timeout would never happen.
//         */
//        wpa_printf(MSG_DEBUG, "ELOOP: Too long timeout (secs=%u) to "
//                "ever happen - ignore it", secs);
//        os_free(timeout);
//        return 0;
//    }
//    //加上使用的时间
//    timeout->time.usec += usecs;
//    //如果超过了就保证值在小于1000000s里面
//    while (timeout->time.usec >= 1000000) {
//        timeout->time.sec++;
//        timeout->time.usec -= 1000000;
//    }
//    timeout->eloop_data = eloop_data;
//    timeout->user_data = user_data;
//    timeout->handler = handler;
//
//    wpa_trace_add_ref(timeout, eloop, eloop_data);
//    wpa_trace_add_ref(timeout, user, user_data);
//    wpa_trace_record(timeout);
//
//    /* Maintain timeouts in order of increasing time */
//    //下面这个操作是为了保证时间为增序的
//    //遍历整个双向链表
//    dl_list_for_each(tmp, &eloop.timeout, struct eloop_timeout, list) {
//        if (os_time_before(&timeout->time, &tmp->time)) {
//            dl_list_add(tmp->list.prev, &timeout->list);
//            return 0;
//        }
//    }
//    //把当前事件插入到双向链表的最尾端
//    dl_list_add_tail(&eloop.timeout, &timeout->list);
//
//    return 0;
//
//}
//
////移除timeout事件 就是把它从双向链表里面删除
//static void eloop_remove_timeout(struct eloop_timeout *timeout)
//{
//    dl_list_del(&timeout->list);
//    wpa_trace_remove_ref(timeout, eloop, timeout->eloop_data);
//    wpa_trace_remove_ref(timeout, user, timeout->user_data);
//    os_free(timeout);
//}
//
////取消匹配的了的超时事件
///**
// * eloop_cancel_timeout - Cancel timeouts
// * @handler: Matching callback function
// * @eloop_data: Matching eloop_data or %ELOOP_ALL_CTX to match all
// * @user_data: Matching user_data or %ELOOP_ALL_CTX to match all
// * Returns: Number of cancelled timeouts
// *
// * Cancel matching <handler,eloop_data,user_data> timeouts registered with
// * eloop_register_timeout(). ELOOP_ALL_CTX can be used as a wildcard for
// * cancelling all timeouts regardless of eloop_data/user_data.
// */
//int eloop_cancel_timeout(eloop_timeout_handler handler,
//                         void *eloop_data, void *user_data)
//{
//    struct eloop_timeout *timeout, *prev;
//    int removed = 0;
////遍历链表，找到匹配的的处理事件，从双向链表里面移除
//    dl_list_for_each_safe(timeout, prev, &eloop.timeout,
//    struct eloop_timeout, list) {
//        if (timeout->handler == handler &&
//            (timeout->eloop_data == eloop_data ||
//             eloop_data == ELOOP_ALL_CTX) &&
//            (timeout->user_data == user_data ||
//             user_data == ELOOP_ALL_CTX)) {
//            eloop_remove_timeout(timeout);
//            removed++;
//        }
//    }
//
//    return removed;
//}
//
//
////判断传入的处理超时事件在双向链表里面
///**
// * eloop_is_timeout_registered - Check if a timeout is already registered
// * @handler: Matching callback function
// * @eloop_data: Matching eloop_data
// * @user_data: Matching user_data
// * Returns: 1 if the timeout is registered, 0 if the timeout is not registered
// *
// * Determine if a matching <handler,eloop_data,user_data> timeout is registered
// * with eloop_register_timeout().
// */
//int eloop_is_timeout_registered(eloop_timeout_handler handler,
//                                void *eloop_data, void *user_data)
//{
//    struct eloop_timeout *tmp;
//
//    dl_list_for_each(tmp, &eloop.timeout, struct eloop_timeout, list) {
//        if (tmp->handler == handler &&
//            tmp->eloop_data == eloop_data &&
//            tmp->user_data == user_data)
//            return 1;
//    }
//
//    return 0;
//}
//
////处理信号事件，对于不同信号事件，其实是把信号标记为1 留待以后处理
//static void eloop_handle_signal(int sig)
//{
//    int i;
//
//#ifndef CONFIG_NATIVE_WINDOWS
//    if ((sig == SIGINT || sig == SIGTERM) && !eloop.pending_terminate) {
//        /* Use SIGALRM to break out from potential busy loops that
//         * would not allow the program to be killed. */
//        eloop.pending_terminate = 1;
//        signal(SIGALRM, eloop_handle_alarm);
//        alarm(2);
//    }
//#endif /* CONFIG_NATIVE_WINDOWS */
//
//    eloop.signaled++;
//    for (i = 0; i < eloop.signal_count; i++) {
//        if (eloop.signals[i].sig == sig) {
//            eloop.signals[i].signaled++;
//            break;
//        }
//    }
//}
//
////eloop_signal进程挂起signal
//static void eloop_process_pending_signals(void)
//{
//    int i;
//
//    if (eloop.signaled == 0)
//        return;
//    eloop.signaled = 0;
//
//    if (eloop.pending_terminate) {
//#ifndef CONFIG_NATIVE_WINDOWS
//        alarm(0);
//#endif /* CONFIG_NATIVE_WINDOWS */
//        eloop.pending_terminate = 0;
//    }
//
////有中断标记了，就响应中断处理函数handler
//    for (i = 0; i < eloop.signal_count; i++) {
//        if (eloop.signals[i].signaled) {
//            eloop.signals[i].signaled = 0;
//            eloop.signals[i].handler(eloop.signals[i].sig,
//                                     eloop.signals[i].user_data);
//        }
//    }
//}
//
//
////eloop注册一个信号
////传入第一个值为信号量
////第二个参数为处理函数
////第三个参数为user_data
///**
// * eloop_register_signal - Register handler for signals
// * @sig: Signal number (e.g., SIGHUP)
// * @handler: Callback function to be called when the signal is received
// * @user_data: Callback context data (signal_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register a callback function that will be called when a signal is received.
// * The callback function is actually called only after the system signal
// * handler has returned. This means that the normal limits for sighandlers
// * (i.e., only "safe functions" allowed) do not apply for the registered
// * callback.
// */
//int eloop_register_signal(int sig, eloop_signal_handler handler,
//                          void *user_data)
//{
//    struct eloop_signal *tmp;
//
//    tmp = os_realloc_array(eloop.signals, eloop.signal_count + 1,
//                           sizeof(struct eloop_signal));
//    if (tmp == NULL)
//        return -1;
//
//    tmp[eloop.signal_count].sig = sig;
//    tmp[eloop.signal_count].user_data = user_data;
//    tmp[eloop.signal_count].handler = handler;
//    tmp[eloop.signal_count].signaled = 0;
//    eloop.signal_count++;
//    eloop.signals = tmp;
//    //将这个信号处理函数注册到内核
//    signal(sig, eloop_handle_signal);
//
//    return 0;
//}
//
////注册中止信号程序
///**
// * eloop_register_signal_terminate - Register handler for terminate signals
// * @handler: Callback function to be called when the signal is received
// * @user_data: Callback context data (signal_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register a callback function that will be called when a process termination
// * signal is received. The callback function is actually called only after the
// * system signal handler has returned. This means that the normal limits for
// * sighandlers (i.e., only "safe functions" allowed) do not apply for the
// * registered callback.
// *
// * This function is a more portable version of eloop_register_signal() since
// * the knowledge of exact details of the signals is hidden in eloop
// * implementation. In case of operating systems using signal(), this function
// * registers handlers for SIGINT and SIGTERM.
// */
//int eloop_register_signal_terminate(eloop_signal_handler handler,
//                                    void *user_data)
//{
//    int ret = eloop_register_signal(SIGINT, handler, user_data);
//    if (ret == 0)
//        ret = eloop_register_signal(SIGTERM, handler, user_data);
//    return ret;
//}
//
//
////注册一个处理重配置的事件 这个具体说明见下面英文
///**
// * eloop_register_signal_reconfig - Register handler for reconfig signals
// * @handler: Callback function to be called when the signal is received
// * @user_data: Callback context data (signal_ctx)
// * Returns: 0 on success, -1 on failure
// *
// * Register a callback function that will be called when a reconfiguration /
// * hangup signal is received. The callback function is actually called only
// * after the system signal handler has returned. This means that the normal
// * limits for sighandlers (i.e., only "safe functions" allowed) do not apply
// * for the registered callback.
// *
// * This function is a more portable version of eloop_register_signal() since
// * the knowledge of exact details of the signals is hidden in eloop
// * implementation. In case of operating systems using signal(), this function
// * registers a handler for SIGHUP.
// */
//int eloop_register_signal_reconfig(eloop_signal_handler handler,
//                                   void *user_data)
//{
//#ifdef CONFIG_NATIVE_WINDOWS
//    return 0;
//#else /* CONFIG_NATIVE_WINDOWS */
//    return eloop_register_signal(SIGHUP, handler, user_data);
//#endif /* CONFIG_NATIVE_WINDOWS */
//}
//
////终止eloop
///**
// * eloop_terminate - Terminate event loop
// *
// * Terminate event loop even if there are registered events. This can be used
// * to request the program to be terminated cleanly.
// */
//void eloop_terminate(void)
//{
//    eloop.terminate = 1;
//}
//
////检查是否中止了
///**
// * eloop_terminated - Check whether event loop has been terminated
// * Returns: 1 = event loop terminate, 0 = event loop still running
// *
// * This function can be used to check whether eloop_terminate() has been called
// * to request termination of the event loop. This is normally used to abort
// * operations that may still be queued to be run when eloop_terminate() was
// * called.
// */
//int eloop_terminated(void)
//{
//    return eloop.terminate;
//}
//
////等待一个读信号，这个是将传入的文件描述符作为一个阻塞等待的读信号事件
///**
// * eloop_wait_for_read_sock - Wait for a single reader
// * @sock: File descriptor number for the socket
// *
// * Do a blocking wait for a single read socket.
// */
//void eloop_wait_for_read_sock(int sock)
//{
//
//    fd_set rfds;
//
//    if (sock < 0)
//        return;
////就是都把文件描述符值0，
//    FD_ZERO(&rfds);
//    FD_SET(sock, &rfds);
////选择这个文件描述符（第一个位最大文件描述符），返回等待的读事件
//    select(sock + 1, &rfds, NULL, NULL, NULL);
//}
//
////eloop 跑起来
///**
// * eloop_run - Start the event loop
// *
// * Start the event loop and continue running as long as there are any
// * registered event handlers. This function is run after event loop has been
// * initialized with event_init() and one or more events have been registered.
// */
//void eloop_run(void)
//{
//
//    fd_set *rfds, *wfds, *efds;
//    struct timeval _tv;
//    int res;
//    struct os_time tv, now;
//
//    rfds = os_malloc(sizeof(*rfds));
//    wfds = os_malloc(sizeof(*wfds));
//    efds = os_malloc(sizeof(*efds));
//    if (rfds == NULL || wfds == NULL || efds == NULL)
//        goto out;
//
//    //当eloop没有标记中断，且 （ 超时事件双向链表不为空 或者 有读处理事件 或者 有写处理事件 或者有异常处理事件 ）
//    while (!eloop.terminate &&
//           (!dl_list_empty(&eloop.timeout) || eloop.readers.count > 0 ||
//            eloop.writers.count > 0 || eloop.exceptions.count > 0)) {
//        //判断是否超时 并得到剩余时间
//        struct eloop_timeout *timeout;
//        timeout = dl_list_first(&eloop.timeout, struct eloop_timeout,
//        list);
//        if (timeout) {
//            os_get_time(&now);
//            if (os_time_before(&now, &timeout->time))
//                os_time_sub(&timeout->time, &now, &tv);
//            else
//                tv.sec = tv.usec = 0;
//
//            _tv.tv_sec = tv.sec;
//            _tv.tv_usec = tv.usec;
//        }
//
////每次都重新把表中的文件描述符重新赋值到三个fds中
//        eloop_sock_table_set_fds(&eloop.readers, rfds);
//        eloop_sock_table_set_fds(&eloop.writers, wfds);
//        eloop_sock_table_set_fds(&eloop.exceptions, efds);
////返回等待就绪的描述符数目  最后一个值为前面判断过的时间剩余值
//        res = select(eloop.max_sock + 1, rfds, wfds, efds,
//                     timeout ? &_tv : NULL);
//        if (res < 0 && errno != EINTR && errno != 0) {
//            perror("select");
//            goto out;
//        }
//        //处理那些signed了的事件
//        eloop_process_pending_signals();
//
//        /* check if some registered timeouts have occurred */
//        //检查是否有超时事件需要处理
//        timeout = dl_list_first(&eloop.timeout, struct eloop_timeout,
//        list);
//        //如果超时了 給出书处理事件
//        if (timeout) {
//            os_get_time(&now);
//            if (!os_time_before(&now, &timeout->time)) {
//                void *eloop_data = timeout->eloop_data;
//                void *user_data = timeout->user_data;
//                eloop_timeout_handler handler = timeout->handler;
//                //先移除在处理
//                eloop_remove_timeout(timeout);
//                handler(eloop_data, user_data);
//            }
//
//        }
//
//        if (res <= 0)
//            continue;
//
//        // 分发事件
//        eloop_sock_table_dispatch(&eloop.readers, rfds);
//        eloop_sock_table_dispatch(&eloop.writers, wfds);
//        eloop_sock_table_dispatch(&eloop.exceptions, efds);
//    }
//
//    out:
//    os_free(rfds);
//    os_free(wfds);
//    os_free(efds);
//    return;
//}
//
////销毁eloop
///**
// * eloop_destroy - Free any resources allocated for the event loop
// *
// * After calling eloop_destroy(), other eloop_* functions must not be called
// * before re-running eloop_init().
// */
//void eloop_destroy(void)
//{
//    struct eloop_timeout *timeout, *prev;
//    struct os_time now;
//
//    os_get_time(&now);
//    dl_list_for_each_safe(timeout, prev, &eloop.timeout,
//    struct eloop_timeout, list) {
//        int sec, usec;
//        sec = timeout->time.sec - now.sec;
//        usec = timeout->time.usec - now.usec;
//        if (timeout->time.usec < now.usec) {
//            sec--;
//            usec += 1000000;
//        }
//        wpa_printf(MSG_INFO, "ELOOP: remaining timeout: %d.%06d "
//                           "eloop_data=%p user_data=%p handler=%p",
//                   sec, usec, timeout->eloop_data, timeout->user_data,
//                   timeout->handler);
//        wpa_trace_dump_funcname("eloop unregistered timeout handler",
//                                timeout->handler);
//        wpa_trace_dump("eloop timeout", timeout);
//        eloop_remove_timeout(timeout);
//    }
//    eloop_sock_table_destroy(&eloop.readers);
//    eloop_sock_table_destroy(&eloop.writers);
//    eloop_sock_table_destroy(&eloop.exceptions);
//    os_free(eloop.signals);
//
//}
