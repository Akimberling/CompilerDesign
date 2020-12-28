#pragma once
#ifndef STACKPAC
#define STACKPAC

template<class T, int n>
class STACK
{
private:
	T st[n];
	int z;

public:
	void clearStack()
	{
		z = 0;
	}
	bool emptyStack()
	{
		return (z == 0) ? true : false;
	}
	bool fullStack()
	{
		return (z == n) ? true : false;
	}
	void pushStack(T x)
	{
		st[z] = x;
		z++;
	}
	T popStack()
	{
		z--;
		return st[z];
	}
};
#endif