void selectionSort ( int keyList [], int numKeys )

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
	int i, j, min_idx;

	for (i = 0; i < numKeys - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < numKeys; j++) {
			if (keyList[j] < keyList[min_idx]) {
				min_idx = j;
			}
		}
		int temp = keyList[min_idx];
		keyList[min_idx] = keyList[i];
		keyList[i] = temp;
	}

}