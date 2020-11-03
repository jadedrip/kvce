#pragma once
#include "../KVSystem/IKVBase.h"
#include "IComputingBase.h"

namespace kvc {
	class RedisMock : public IComputingBase
	{
	public:
		virtual bool invoke(
			kvs::IKVBase* kvSystem,
			const std::string& key,
			const std::string& methodName,
			const std::vector<std::string>& paramters,
			const std::function<void(std::ostream&)>& output,
			const std::function<void(std::string&/*type*/, std::string&/*message*/)>& exception	// 发生异常时调用 
		);
	public:
		bool set(
			kvs::IKVBase* kvSystem,
			const std::string& key,
			const std::vector<std::string>& paramters,
			const std::function<void(std::ostream&)>& output
		);

		bool get(
			kvs::IKVBase* kvSystem,
			const std::string& key,
			const std::function<void(std::ostream&)>& output
		);
	};
}
