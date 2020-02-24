// partition
int partition(int list[], int left, int right)
{
	int i, j, pivot;
	i = left; j = right + 1;
	pivot = list[left];
	while (i<j) {	//pivot 보다 작은 것과 큰 것으로 나누어 스왑
		while (list[++i] < pivot);
		while (list[--j]>pivot);
		if (i<j) swap(&list[i], &list[j]);
	}
	//  pivot을 중간에 놓고 j 반환
	swap(&list[left], &list[j]);
	return j;
}

// quick sort
void quick_sort(int list[], int left, int right)
{
	int j;
	if (left<right) {

		//  절반으로 나누어 파티션
		j = partition(list, left, right);
		// 각 파티션에 대하여 quick_sort
		quick_sort(list, left, j - 1);
		quick_sort(list, j + 1, right);
	}
}