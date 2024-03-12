/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: MyConnParam.h
@Time: 2021/10/4 11:58 上午
@Desc: 
***************************/

#ifndef CGRAPH_MYCONNPARAM_H
#define CGRAPH_MYCONNPARAM_H

#include "CGraph.h"

const static char* CONN_PARAM_KEY = "conn";

struct MyConnParam : public CGraph::GPassedParam {
    MyConnParam() = default;
    MyConnParam(const MyConnParam& other)
     : ip_(other.ip_), port_(other.port_)
    {
    }
    /**
     * 必须实现 clone 函数
     * GAspectParam 和 GDaemonParam 均为 GPassedParam的同名内容
     * 继承自GPassedParam的参数，可以用于在 aspect 或 daemon 之间传递
     * 本例中，MyConnParam既用于GAspectParam(T10)传递，有用于GDaemonParam(T13)传递
     * 故写法为 `: public CGraph::GPassedParam`
     * @param param
     */
    std::unique_ptr<GPassedParam> clone() override {
        return std::unique_ptr<GPassedParam>(new MyConnParam(*this));
    }

    std::string ip_ {"0.0.0.0" };
    short port_ { 0 };
};

#endif //CGRAPH_MYCONNPARAM_H
