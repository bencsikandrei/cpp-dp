#pragma once

/*
 * Old style singleton, with double IF for thread safety
 */
class Singleton {
public:
	static Singleton* get() {
		return instance;
	}
private:
	static Singleton* instance;
};
