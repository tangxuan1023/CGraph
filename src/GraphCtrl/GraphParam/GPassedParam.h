/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GPassedParam.h
@Time: 2021/10/4 1:47 下午
@Desc: 
***************************/

#ifndef CGRAPH_GPASSEDPARAM_H
#define CGRAPH_GPASSEDPARAM_H

#include <unordered_map>

#include "GParamObject.h"

CGRAPH_NAMESPACE_BEGIN

class GPassedParam : public GParamObject {
public:
    /**
     * 所有的 GPassedParam 类型，内部需要实现一个 clone 方法
     * 将外部函数传到内部，如aspect和daemon
     * @param param
     */
    virtual std::unique_ptr<GPassedParam> clone() = 0;
};


/**
 * 这种类型的参数，可以用于aspect和daemon中，方便参数传递
 * 不同的地方，用不同的名字，对应的内容是同一个
 */
using GAspectParam = GPassedParam;
using GDaemonParam = GPassedParam;
using GElementParam = GPassedParam;
using GEventParam = GPassedParam;
using GPassedParamPtr = std::unique_ptr<GPassedParam>;
using GAspectParamPtr = std::unique_ptr<GAspectParam>;
using GDaemonParamPtr = std::unique_ptr<GDaemonParam>;
using GElementParamPtr = std::unique_ptr<GElementParam>;
using GEventParamPtr = std::unique_ptr<GEventParam>;

using GElementParamMap = std::unordered_map<std::string, GElementParamPtr>;

CGRAPH_NAMESPACE_END

#endif //CGRAPH_GPASSEDPARAM_H
