
template < class LE >
void merge_sort(LE list[], int left, int right)
{
	int center;
	if (left < right) {
		center = (left + right) / 2;
		// 왼쪽 절반과 오른쪽 절반에 대하여 merge_sort
		merge_sort(list, left, center);
		merge_sort(list, center + 1, right);
		
		// 정렬된 두 부분을 합병
		merge(list, left, center, right);
	}
}

// merge
template < class LE >
void merge(LE list[], int left, int center, int right)
{
	int i, j, k, n;
	LE sorted[MAX_SIZE];
	i = left;
	j = center + 1; 
	k = left;
	// 정렬된 리스트 합침
	while (i <= center && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else                  
			sorted[k++] = list[j++];
	}

	if (i > center)
		for (n = j; n <= right; n++)
			sorted[k++] = list[n]; // 남은 부분
	else
		for (n = i; n <= center; n++)
			sorted[k++] = list[n]; // 남은 부분

	 // 합병 결과를 list[]로 다시 복사
	for (n = left; n <= right; n++)
		list[n] = sorted[n];
}