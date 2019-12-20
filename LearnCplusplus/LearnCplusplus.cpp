// LearnCplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <functional>

//#include "Cplusplus11.h"
//#include "LearnTemplate.h"
//#include "LearnSpace.h"

//
////https://blog.csdn.net/u011068702/article/details/64443949
////func_test的参数const需要注意,不能省略
////c++语义限制,临时变量不能传入非const得引用
//template<typename CLASS,typename... ARGS>
//class func_test {
//public:
//	func_test(const std::function<void(CLASS*, ARGS...)>& function) :
//		function_(function) {
//
//	};
//private:
//	std::function<void(CLASS*, ARGS...)> function_;
//};
//
//template<typename CLASS,typename... ARGS>
//func_test<CLASS, ARGS...> makefunctest(void (CLASS::*function)(ARGS...)) {
//	return func_test<CLASS, ARGS...>(function);
//}
//
//class ctest{
//public:
//	void run() {
//
//	};
//};
//
//MyString Fun();
//void runRValue();
//
//class Mem_test{
//};
//class Mem_test1 {
//	int &a;
//};
//
//void exit_fn1(void) {
//	cout << "Exit function #1 called" << endl;
//}
//
//void exit_fn2(void) {
//	cout << "Exit function #2 called" << endl;
//}
//
//void atexit_test() {
//	//有8种方式使进程终止，其中前5种为正常终止，它们是
//	//	1：从 main 返回
//	//	2：调用 exit
//	//	3：调用 _exit 或 _Exit
//	//	4：最后一个线程从其启动例程返回
//	//	5：最后一个线程调用pthread_exit
//	//	异常终止有3种，它们是
//	//	6：调用 abort
//	//	7：接到一个信号并终止
//	//	8：最后一个线程对取消请求做出响应
//
//	//其中调用 _exit，_Exit 都不会调用终止程序
//	//异常终止也不会。
//	atexit(exit_fn1);
//	atexit(exit_fn2);
//}

//libevent

#include <errno.h>
#include <stdio.h>
#include <signal.h>
#ifndef _WIN32
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/inet.h>
# endif
#include <sys/socket.h>
#endif

extern "C" {
#include "event2/event.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include "event2/listener.h"
#include "event2/util.h"
}

static const char MESSAGE[] = "Hello, World!\n";

static const int PORT = 9995;

static void listener_cb(struct evconnlistener *, evutil_socket_t,
	struct sockaddr *, int socklen, void *);
static void conn_writecb(struct bufferevent *, void *);
static void conn_eventcb(struct bufferevent *, short, void *);
static void signal_cb(evutil_socket_t, short, void *);

int main()
{
	struct event_base *base;
	struct evconnlistener *listener;
	struct event *signal_event;

	struct sockaddr_in sin;
#ifdef _WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);
#endif

	base = event_base_new();
	if (!base) {
		fprintf(stderr, "Could not initialize libevent!\n");
		return 1;
	}

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	listener = evconnlistener_new_bind(base, listener_cb, (void *)base,
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
		(struct sockaddr*)&sin,
		sizeof(sin));

	if (!listener) {
		fprintf(stderr, "Could not create a listener!\n");
		return 1;
	}

	signal_event = evsignal_new(base, SIGINT, signal_cb, (void *)base);

	if (!signal_event || event_add(signal_event, NULL) < 0) {
		fprintf(stderr, "Could not create/add a signal event!\n");
		return 1;
	}

	event_base_dispatch(base);

	evconnlistener_free(listener);
	event_free(signal_event);
	event_base_free(base);

	printf("done\n");
	//LearnSpace::Space s;
	//LearnSpace ls1;
	//LearnSpace ls2;
	//cout << LearnSpace::kA << endl;
	//cout << ls1.kA << endl;
	//cout << ls2.kA << endl;
	///*add1<int, float, double>(1, 1.2, 1.3);
	//tprintf("% world% %\n", "Hello", '!', 123);
	//runRValue();*/
	//cout << sizeof(Mem_test) << " " << sizeof(Mem_test1) << endl;

	//makefunctest(&ctest::run);
	// 
	////(void)d表示d转换为void类型,并且对其丢弃
	////ref:
	////https://www.cnblogs.com/litifeng/p/7753933.html
	//typedef char a[1];
	//a d;
	//(void)d;

	//atexit_test();
	//_exit(0);
	//LearnTemplate lt;
	//lt.run();
}




static void
listener_cb(struct evconnlistener *listener, evutil_socket_t fd,
	struct sockaddr *sa, int socklen, void *user_data)
{
	struct event_base *base = (struct event_base *)user_data;
	struct bufferevent *bev;

	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	if (!bev) {
		fprintf(stderr, "Error constructing bufferevent!");
		event_base_loopbreak(base);
		return;
	}
	bufferevent_setcb(bev, NULL, conn_writecb, conn_eventcb, NULL);
	bufferevent_enable(bev, EV_WRITE);
	bufferevent_disable(bev, EV_READ);

	bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
}

static void
conn_writecb(struct bufferevent *bev, void *user_data)
{
	struct evbuffer *output = bufferevent_get_output(bev);
	if (evbuffer_get_length(output) == 0) {
		printf("flushed answer\n");
		bufferevent_free(bev);
	}
}

static void
conn_eventcb(struct bufferevent *bev, short events, void *user_data)
{
	if (events & BEV_EVENT_EOF) {
		printf("Connection closed.\n");
	}
	else if (events & BEV_EVENT_ERROR) {
		printf("Got an error on the connection: %s\n",
			strerror(errno));/*XXX win32*/
	}
	/* None of the other events can happen here, since we haven't enabled
	 * timeouts */
	bufferevent_free(bev);
}

static void
signal_cb(evutil_socket_t sig, short events, void *user_data)
{
	struct event_base *base = (struct event_base *)user_data;
	struct timeval delay = { 2, 0 };

	printf("Caught an interrupt signal; exiting cleanly in two seconds.\n");

	event_base_loopexit(base, &delay);
}


//
//MyString Fun()
//{
//	MyString str = "hello world";
//	return str;
//}
//
//void runRValue()
//{
//	//右值引用的概念,生成的一个临时变量，把这个临时变量给a,原本的a1的值不变. 
//	int &&a = 1;
//	int a1 = 2;
//	a = a1;
//	a++;
//	cout << a << a1 << endl;
//	MyString str1 = "123";
//	MyString str2 = str1;
//	MyString str3 = Fun();
//}
