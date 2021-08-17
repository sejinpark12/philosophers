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

```shell
./philo 4 410 200 200 // 철학자 4명, 죽는 시간 410, 식사하는 시간 200, 잠사는 시간 200
```