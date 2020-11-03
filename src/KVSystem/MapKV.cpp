#include "MapKV.h"
#include <sstream>

namespace kvs {
	bool MapKV::readSteam(const std::string& key, const std::string& type, const std::function<void(std::istream&)>& func)
	{
		auto iter = _data.find(key + "::" + type);
		if (iter == _data.end()) {
			return false;
		}
		std::istringstream ss(iter->second);
		func(ss);
		return true;
	}

	void MapKV::writeSteam(const std::string& key, const std::string& type, int64_t expireAt, const std::function<void(std::ostream&)>& func)
	{
		std::ostringstream ss;
		func(ss);
		_data[key + "::" + type] = ss.str();
	}

	bool MapKV::setExpire(const std::string& key, const std::string& type, int64_t expireAt)
	{
		// TODO: ‘›≤ª µœ÷
		return true;
	}
}
