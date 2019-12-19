#pragma once
#ifndef _LEARN_SPACE_H_INCLUDE_
#define	_LEARN_SPACE_H_INCLUDE_

class LearnSpace {
public:
	struct Space {
		int A;
		int B;
	};
	static const int kA;
	static const int kB = 2;
	LearnSpace();
	int Get();
};

#endif // !_LEARN_SPACE_H_INCLUDE_
