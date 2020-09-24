template < class LE >
void quickPartition(LE keyList[], int numKeys, int left, int right);

template < class LE >
void quickSort ( LE keyList [], int numKeys )

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )

// Recursive partner of the quickSort routine. Partitions the array
// entries between left and right into two subarrays. One subarray
// contains the keys that are less than or equal to splitValue, and
// the other contains the keys that are greater than splitValue.
// Recursively sorts each of these subarrays.

{
	if (numKeys <= 1)
		return;

	// partition operation
	int i, j;
	LE pivot;
	i = left; j = right + 1;
	pivot = keyList[left];
	while (i < j) {	//pivot 보다 작은 것과 큰 것으로 나누어 스왑
		while (keyList[++i] < pivot);
		while (keyList[--j] > pivot);
		if (i < j) {
			//swap(&keyList[i], &keyList[j]);
			LE temp = keyList[i];
			keyList[i] = keyList[j];
			keyList[j] = temp;
		}
	}
	//  pivot을 중간에 놓고 j 반환
	//swap(&keyList[left], &keyList[j]);
	LE temp = keyList[left];
	keyList[left] = keyList[j];
	keyList[j] = temp;

	// 각 파티션에 대하여 quickSort
	if (numKeys > 1) {
		quickPartition(keyList, j - left, left, j - 1);
		quickPartition(keyList, right - j, j + 1, right);
	}
}