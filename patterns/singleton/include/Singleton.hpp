#pragma once

class SingletonNew {
public:
	static SingletonNew& get();

private:
	SingletonNew() = default;
	SingletonNew(SingletonNew const& rhs) = default;
	SingletonNew& operator=(SingletonNew const& rhs) = delete;
	SingletonNew& operator=(SingletonNew && rhs) = delete;
};
