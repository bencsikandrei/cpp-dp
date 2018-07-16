#pragma once

#include <mutex>
/*
 * Old style singleton, with double IF for thread safety
 */
class Singleton {
public:
	static Singleton& get();
private:
	Singleton() = default;
	static Singleton* instance;
	static std::mutex singletonLock;
};
