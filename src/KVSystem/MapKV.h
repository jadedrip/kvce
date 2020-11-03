#pragma once
#include <map>
#include "IKVBase.h"

namespace kvs {
	class MapKV : public IKVBase {
	public:
		virtual bool readSteam(const std::string& key, const std::string& type, const std::function<void(std::istream&)>& func);
		virtual void writeSteam(const std::string& key, const std::string& type, int64_t expireAt, const std::function<void(std::ostream&)>& func);
		virtual bool setExpire(const std::string& key, const std::string& type, int64_t expireAt);
	private: 
		std::map<std::string, std::string> _data;
	};
}