
#ifndef  __RPC_SERVER_H_
#define  __RPC_SERVER_H_
#include <iostream>
#include <../utils/sds.h>

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&); \
    TypeName& operator=(const TypeName&);



namespace krpc {

using namespace google::protobuf;
using __gnu_cxx::hash_map;


struct RpcMethod {
    RpcMethod(Service* p_service,
              const Message* p_req,
              const Message* p_rep,
              const MethodDescriptor* p_meth)
        : service(p_service),
          request(p_req),
          response(p_rep),
          method(p_meth) {
    }

    Service* service;
    const Message* request;
    const Message* response;
    const MethodDescriptor* method;
};


}  //end if namespace krpc

class RpcServer{
public:
	
	~RpcServer();
    bool Start();
    bool Wait();
	bool Stop();

    static void RpcCall(int event_fd,void *arg);
    static void* RpcReader(void *arg);
    static void* RpcWriter(void *arg);
    
    // kill oldversion 
    bool RestartWorkThread(pthread_t thread_id,long runing_version);
    
    static RpcServer& GetInstance();
    static RpcServer& GetInstance(const std::string& config_file);

    private:
       
 private:
    RpcServer(const std::string &cfg_file = "rpc_server.cfg");
    bool Initalize(const std::string &cfg_file);
    bool ErrorSendMsg(int event_fd,const std::string& error_msg);



    // 优化   不允许未知的  拷贝构造如果需要请用引用和指针
    DISALLOW_COPY_AND_ASSIGN(RpcServer);

private:
    // 控制注册表
    RWLock hashmap_rwlock_;
    


private:
	int socket;
	int worknum;
}

int loadcfg()
{
    return 0;
}

int start()
{
    return 0;
}

int distribute()
{
    return 0;
}


int stop()
{
    return 0;
}


#endif  //__RPC_SERVER_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
