void insertion_sort(int list[], int n)
{
	int temp;
	int j;
	for (int i = 0; i < n; i++)
	{
		temp = list[i];
		for (j = i - 1; j >= 0 && temp < list[j]; j--) //매번 자신의 알맞은 위치를 탐색하여 삽입
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
	}
}