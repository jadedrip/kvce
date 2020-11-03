#pragma once
#define interface struct

#include <string>
#include <istream>
#include <ostream>
#include <memory>
#include <functional>

namespace kvs {
	/**
	* 读写底层 KV 数据库的基本接口
	*/
	interface IKVBase {
		virtual bool readSteam(const std::string& key, const std::string& type, const std::function<void(std::istream&)>& func) = 0;
		virtual void writeSteam(const std::string& key, const std::string& type, int64_t expireAt, const std::function<void(std::ostream&)>& func) = 0;
		virtual bool setExpire(const std::string& key, const std::string& type, int64_t expireAt) = 0;
	};
}
