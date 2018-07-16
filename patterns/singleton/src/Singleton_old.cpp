#include <Singleton_old.hpp>
#include <iostream>
#include <mutex>

Singleton& Singleton::get() {

	if(not instance) {
		singletonLock.lock();
		if(not instance) {
			instance = new Singleton;
		}
		singletonLock.unlock();
	}
	return *instance;
}

Singleton* Singleton::instance{nullptr};
std::mutex Singleton::singletonLock{};
