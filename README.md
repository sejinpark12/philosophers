# philosophers

---

## 1. 프로젝트 설명

![image](https://user-images.githubusercontent.com/19530862/129676790-c03afdf7-a945-4481-a9ad-3c97b6daa310.png)

### 개요

- 스레드의 동작 개념 이해와 멀티스레딩 프로그래밍을 작성할 때 발생할 수 있는 교착상태를 코드를 통해 좀 더 깊게 이해하고자 식사하는 철학자 문제를 프로그래밍 했습니다.

### 목표

- 스레드의 목적과 의미 이해
- 스레드와 프로세스의 차이
- 스레드의 구조적 특징
- 교착상태 해결하기 위한 방법

### 상세 기능

- pthread 라이브러리를 사용하여 POSIX 시스템에서 식사하는 철학자 문제를 시물레이션합니다.

### 사용라이브러리

- pthread

### 제작 기간

- 2021.07 ~ 2021.08

### 플로우 차트

![image](https://user-images.githubusercontent.com/19530862/129673226-d18127ac-d9c9-4aac-ae0f-a87ad8c2a769.png)

## 2. philosophers 결과물

### build

```shell
git clone https://github.com/sejinpark12/philosophers.git && cd philosophers && make all
```

### run
#### 철학자 4명, 죽는 시간 410, 식사하는 시간 200, 잠사는 시간 200
```shell
./philo 4 410 200 200 
```

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
201 1 is sleeping
201 4 has taken a fork
201 4 has taken a fork
201 4 is eating
201 3 is sleeping
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
403 2 is sleeping
403 4 is sleeping
407 1 is thinking
407 1 has taken a fork
407 1 has taken a fork
407 1 is eating
...
```
![4_410_200_200](https://user-images.githubusercontent.com/19530862/129678265-357691b3-0fd3-45dc-98d6-3b70c83cb489.png)

#### 철학자 5명, 죽는 시간 800, 식사하는 시간 200, 잠사는 시간 200
```shell
./philo 5 800 200 200
```

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
201 1 is sleeping
201 3 is sleeping
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
201 4 has taken a fork
201 4 has taken a fork
201 4 is eating
402 5 has taken a fork
403 4 is sleeping
403 5 has taken a fork
403 5 is eating
404 2 is sleeping
406 1 is thinking
406 1 has taken a fork
407 3 is thinking
407 3 has taken a fork
407 3 has taken a fork
407 3 is eating
604 5 is sleeping
604 1 has taken a fork
...
```
![5_800_200_200](https://user-images.githubusercontent.com/19530862/129678649-6adbb949-7466-49a3-8e7f-a417bf903501.png)

#### 철학자 51명, 죽는 시간 800, 식사하는 시간 200, 잠사는 시간 200
```shell
./philo 51 800 200 200
```

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
0 5 has taken a fork
0 5 has taken a fork
0 5 is eating
0 7 has taken a fork
0 7 has taken a fork
0 7 is eating
0 9 has taken a fork
0 9 has taken a fork
0 9 is eating
0 11 has taken a fork
0 11 has taken a fork
0 11 is eating
0 13 has taken a fork
0 13 has taken a fork
0 13 is eating
1 15 has taken a fork
1 15 has taken a fork
1 15 is eating
1 17 has taken a fork
1 17 has taken a fork
1 17 is eating
1 19 has taken a fork
1 19 has taken a fork
1 19 is eating
1 21 has taken a fork
1 21 has taken a fork
1 21 is eating
1 23 has taken a fork
1 23 has taken a fork
1 23 is eating
1 25 has taken a fork
1 25 has taken a fork
1 25 is eating
1 27 has taken a fork
1 27 has taken a fork
1 27 is eating
1 29 has taken a fork
1 29 has taken a fork
1 29 is eating
1 31 has taken a fork
1 31 has taken a fork
1 31 is eating
1 33 has taken a fork
1 33 has taken a fork
1 33 is eating
2 35 has taken a fork
2 35 has taken a fork
2 35 is eating
2 37 has taken a fork
2 37 has taken a fork
2 37 is eating
2 39 has taken a fork
2 39 has taken a fork
2 39 is eating
2 41 has taken a fork
2 41 has taken a fork
2 41 is eating
2 43 has taken a fork
2 43 has taken a fork
2 43 is eating
2 45 has taken a fork
2 45 has taken a fork
2 45 is eating
2 47 has taken a fork
2 47 has taken a fork
2 47 is eating
2 49 has taken a fork
2 49 has taken a fork
2 49 is eating
202 9 is sleeping
202 11 is sleeping
202 13 is sleeping
202 12 has taken a fork
202 12 has taken a fork
202 12 is eating
202 3 is sleeping
202 1 is sleeping
202 14 has taken a fork
202 2 has taken a fork
202 2 has taken a fork
202 6 has taken a fork
...
```
![51_800_200_200](https://user-images.githubusercontent.com/19530862/129678886-bce28804-e51f-43a2-b0d8-fe25f50c8e52.png)