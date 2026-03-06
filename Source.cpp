#include "Header.h"

void find(const std::vector<std::vector<int>>& a, int k, int s, const std::vector<int>& w, double& weight)
{
	if (k == 0 || s == 0) return;
	if (a[k][s] == a[k - 1][s]) // если коробка не была выбрана
	{
		find(a, k - 1, s, w, weight);
	}
	else // если коробка была выбрана
	{
		std::cout << k << " "; // выводим номер коробки
		weight += w[k];
		find(a, k - 1, s - w[k], w, weight); // ищем оставшиеся коробки
	}
}
