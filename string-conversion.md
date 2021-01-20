# 언어별 스트링 <-> int 변환 방법 정리
## String -> Int
### C
```
#include <stdlib.h>
int atoi(const char *string);
```
### C++
>string object
>```
>#include <string>
>std::stoi(string str); 
>```
>c-str
>```
>#include <cstdlib>
>std::atoi(const char *string);
>```
### Java
```
Integer.parseInt(String str);
```
### Python
```
int(string)
```
## Int -> String
### C
```
#include <stdio.h>
sprintf(char *str, "%d", int value);
```
### C++
```
#include <string>
std::to_string(int value);  // string object
```
### Java
```
Integer.toString(int value);
```
### Python
```
str(value)
```