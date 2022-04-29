# Python

## Sorting
리스트 정렬하기
```python
리스트.sort(key=함수, reverse=boolean)
# key는 정렬 조건 (보통 lambda 함수로)
# reverse가 True면 내림차순
```

## 2차원 배열 
2차원 배열 초기화
```python
board = [[0] * col for _ in range(row)]
```

## 순열, 조합
itertools 라이브러리 필요

* 순열 (한 리스트 내에서)
```python
from itertools import permutations
p = list(permutations(리스트, n))
```

* 조합 (한 리스트 내에서)
```python
from itertools import combinations
c = list(combinations(리스트, n))
```

* 조합 (리스트 of 리스트)
```python
from itertools import product
items = [['a', 'b', 'c,'], ['1', '2', '3', '4'], ['!', '@', '#']]
list(product(*items))
# [('a', '1', '!'), ('a', '1', '@'), ('a', '1', '#'), ('a', '2', '!'), ('a', '2', '@'), ('a', '2', '#'), ('a', '3', '!'), ('a', '3', '@'), ('a', '3', '#'), ('a', '4', '!'), ('a', '4', '@'), ('a', '4', '#'), ('b', '1', '!'), ('b', '1', '@'), ('b', '1', '#'), ('b', '2', '!'), ('b', '2', '@'), ('b', '2', '#'), ('b', '3', '!'), ('b', '3', '@'), ('b', '3', '#'), ('b', '4', '!'), ('b', '4', '@'), ('b', '4', '#'), ('c,', '1', '!'), ('c,', '1', '@'), ('c,', '1', '#'), ('c,', '2', '!'), ('c,', '2', '@'), ('c,', '2', '#'), ('c,', '3', '!'), ('c,', '3', '@'), ('c,', '3', '#'), ('c,', '4', '!'), ('c,', '4', '@'), ('c,', '4', '#')]
```

## 깊은 복사
```python
from copy import deepcopy
a = [1, 2, 3]
b = deepcopy(a)
```