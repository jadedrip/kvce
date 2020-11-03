#include <sstream>
#include "RedisMock.h"

namespace kvc {
	static std::ostringstream empty;
	bool RedisMock::invoke(kvs::IKVBase* kvSystem, const std::string& key, const std::string& methodName, const std::vector<std::string>& paramters, const std::function<void(std::ostream&)>& output, const std::function<void(std::string&, std::string&)>& exception)
	{
		if (methodName == "set") {
			return set(kvSystem, key, paramters, output);
		}
		else if (methodName == "get") {
			return get(kvSystem, key, output);
		}
		return false;
	}

	bool RedisMock::set(kvs::IKVBase* kvSystem, const std::string& key, const std::vector<std::string>& paramters, const std::function<void(std::ostream&)>& output)
	{
		static std::ostringstream ok("OK");
		if (paramters.empty()) {
			output(empty);
			return true;
		}

		const std::string& data = paramters.at(0);
		kvSystem->writeSteam(key, "", 0, [data](std::ostream& os) {
			os.write(data.c_str(), data.size());
			});

		output(ok);
		return true;
	}
	bool RedisMock::get(kvs::IKVBase* kvSystem, const std::string& key, const std::function<void(std::ostream&)>& output)
	{
		bool b=kvSystem->readSteam(key, "", [output](std::ostream& os) {
			output(os);
			});
		if (!b) {
			output(empty);
		}
		return true;
	}
}
