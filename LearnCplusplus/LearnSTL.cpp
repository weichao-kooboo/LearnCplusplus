#include "LearnSTL.h"
#include <map>
#include <iostream>

using namespace std;

LearnSTL::LearnSTL()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(1, 2));

	map<int, int>::iterator it = m.begin();
	for (; it != m.end(); ++it) {
		cout << it->first << "=>" << it->second << '\n';
	}
}


LearnSTL::~LearnSTL()
{
}
