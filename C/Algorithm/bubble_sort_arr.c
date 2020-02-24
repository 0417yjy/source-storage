#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int* list, int n)
{
	int i, j, temp;
	int flag = 1;
	for (i = n - 1; flag>0; i--) {
		flag = 0;
		// 0 ~ i-1 까지 가면서 크기 비교하여 자리 바꿈
		for (j = 0; j<i; j++)
			if (list[j]>list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				flag = 1;
			}
	}
}