/**
* @file Custom.cpp
*
* Copyright (c) Huawei Technologies Co., Ltd. 2019. All rights reserved.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <memory>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "Custom.h"
#include "hiaiengine/log.h"
#include "hiaiengine/data_type_reg.h"

/**
* @ingroup hiaiengine
* @brief HIAI_DEFINE_PROCESS : implemention of the engine
* @[in]: engine name and the number of input
*/
HIAI_StatusT Custom::Init(const hiai::AIConfig &config,
    const std::vector<hiai::AIModelDescription> &modelDesc)
{
    //TODO:
    return HIAI_OK;
}

HIAI_IMPL_ENGINE_PROCESS("Custom", Custom, INPUT_SIZE)
{
    //TODO:
	//user code here

	auto a  = std::static_pointer_cast<string>(arg0);

    printf("%s\n", (*a).c_str());


	//send data
	std::shared_ptr<std::string> resultData(new std::string);
	*resultData = "App run finished!";

    HIAI_StatusT ret = SendData(0, "string", std::static_pointer_cast<void>(resultData));
    return ret;
}
