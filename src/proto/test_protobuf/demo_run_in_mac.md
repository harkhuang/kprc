#protobuf
[toc]

## protobuf
安装请见proto_c_install.md



补充:
` `
`环境：mac  Apple LLVM version 8.1.0 (clang-802.0.42)  `

## 使用步骤

#### 看下目录结构
```
hk-mac:mytest hk$ tree
.
|____include
|____dst
| |____write
| |____addressbook.pb.h //protoc自动生成
| |____bj_apue_k        //数据文件
| |____addressbook.pb.cc   //protoc自动生成
| |____writeMsg.cc         //write protobuf
| |____readMsg.cc        //  read protobuf
|____src
| |____addressbook.proto  //定义protobuf数据结构

```

####通过protoc工具生成相关的c++的读写端

-  生成文件  里面有关于结构的读写接口（预先编写好自己的`addressbook.proto`)
```
 #protoc -I=src/ --cpp_out=dst/ src/addressbook.proto
 #ls
 addressbook.pb.cc  addressbook.pb.h
```


- 编写自己读写文件
```
 $ g++ -std=c++11 writeMsg.cc addressbook.pb.cc  -o write  -lprotobuf
 $ g++ -std=c++11 readMsg.cc addressbook.pb.cc  -o read  -lprotobuf
```

- 如果有rpc支撑 ，这么看基于rest的服务显得太简单了吧
 
```
# ./write
//do something
# ./read
```

