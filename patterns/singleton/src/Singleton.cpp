#include <Singleton.hpp>

SingletonNew& SingletonNew::get() {
	static SingletonNew instance;
	return instance;
}
