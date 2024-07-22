#include "test.pb.h"
#include <iostream>
using namespace fixbug;
#include <string>

int main()
{
    // LoginResponse rsp;
    // ResultCode* rc= rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmessage("登录处理失败了");

    GetfriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_result(); // 获取成员变量的指针
    rc->set_errcode(0);
    rc->set_errmessage("");

    User *user1 = rsp.add_friend_list();//列表成员变量
    user1->set_name("zhangsan");
    user1->set_age(10);
    user1->set_sex(User::MAN);


    std::cout<<rsp.friend_list_size()<<std::endl;


    return 0;
}

// int main()
// {
//     // 封装了login请求对象的数据
//     LoginRequest req;
//     std::string send_str;
//     req.set_name("zhang san");
//     req.set_pwd("123456");
//     // 对象数据序列化=》char*
//     if (req.SerializeToString(&send_str))
//         std::cout << send_str.c_str() << std::endl;

//     // 从send_str反序列化一个login请求对象
//     LoginRequest reqB;
//     if (reqB.ParseFromString(send_str))
//     {
//         std::cout << reqB.name() << std::endl;
//         std::cout << reqB.pwd() << std::endl;
//     }

//     return 0;
// }