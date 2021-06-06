
#include <iostream>

using namespace std;

bool is_subordinate(const char* employee, const char* manager, const char* leaders[][2], size_t n) {

	if (employee == nullptr) {
		return false;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(employee, leaders[i][0]) == 0)
		{
			if (strcmp(manager, leaders[i][1]) == 0) 
			{
				return true;
			}
			else 
			{
				return is_subordinate(leaders[i][1], manager, leaders, n);
			}
			
		}
	}

	return false;
}

const char* the_big_boss(const char* leaders[][2], size_t n)
{
	const char* boss = leaders[0][1];
	for (size_t i = 0; i < n; i++)
	{
		boss = leaders[i][1];

		bool isBoss = true;

		for (size_t j = 0; j < n; j++)
		{
			if (strcmp(boss, leaders[j][0]) == 0)
			{
				isBoss = false;
			}
			
		}

		if (isBoss) {
			return boss;
		}
	} 

	return nullptr;
}
//
//int main() 
//{
//	const char* leaders[3][2] = 
//	{
//		"Ivan", "Mariq",
//		"Mariq", "Ivo",
//		"Ivo", "Stoqn"
//	};
//
//	cout << is_subordinate("Mariq", "Ivan", leaders, 3);
//
//	cout << the_big_boss(leaders, 3);
//
//	return 0;
//}
//

