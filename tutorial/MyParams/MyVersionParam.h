/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: MyVersionParam.h
@Time: 2022/5/29 22:29
@Desc: 
***************************/

#ifndef CGRAPH_MYVERSIONPARAM_H
#define CGRAPH_MYVERSIONPARAM_H

#include "CGraph.h"
#include "../src/GraphCtrl/GraphParam/GPassedParam.h"

const static char* VERSION_PARAM_KEY = "version";

struct MyVersionParam : public CGraph::GElementParam {
    MyVersionParam() = default;
    MyVersionParam(const MyVersionParam& other)
        : priority_(other.priority_), secondary_(other.secondary_)
    {}

    std::unique_ptr<CGraph::GElementParam> clone() override {
        return std::unique_ptr<MyVersionParam>(new MyVersionParam(*this));
    }

    int priority_ = 0;    // 表示 主版本号
    int secondary_ = 0;    // 表示 辅版本号
};


#endif //CGRAPH_MYVERSIONPARAM_H
