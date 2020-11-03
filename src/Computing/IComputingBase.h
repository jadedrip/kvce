#pragma once
#include <string>
#include <vector>
#include <functional>

#include "../KVSystem/IKVBase.h"

namespace kvc {
	interface IComputingBase{
		virtual bool invoke(
			kvs::IKVBase* kvSystem,
			const std::string& key, 
			const std::string& methodName, 
			const std::vector<std::string>& paramters, 
			const std::function<void(std::ostream&)>& output,
			const std::function<void(std::string&/*type*/, std::string&/*message*/)>& exception	// 发生异常时调用 
		) = 0;
	};
}
