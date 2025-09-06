# [Gold III] Black and white stones - 10396 

[문제 링크](https://www.acmicpc.net/problem/10396) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 9월 6일 14:28:39

### 문제 설명

<p>Shagga and Dolf like to play a game with stones, each of which is either black or white. At the beginning of the game, Dolf arranges all the stones in a single line from left to right. Then, Shagga’s goal is to reorder the stones so that all the black stones are to the left of all the white stones. To do this, he can choose any pair of stones of different color and swap their positions, paying A coins to Dolf in the process. However, if the two stones whose positions he is swapping are adjacent, Dolf must give him a refund of B coins, meaning that the operation will effectively cost Shagga only A − B coins.</p>

<p>Shagga is not very bright, so he hasn’t realized yet that he will only loose coins while playing this game. However, he is aware of his limitations, so he knows that if he played optimally he would loose fewer coins than he is loosing right now, with his strategy of randomly choosing the stones he swaps in each movement. Therefore, he wants to know the minimum number of coins he will have to pay Dolf in order to get to the desired arrangement of stones, and is threatening to feed you to the goats if you don’t help him.</p>

### 입력 

 <p>The first line contains two integers A and B (0 ≤ B < A ≤ 10<sup>6</sup>), representing respectively the cost of swapping two stones and the value of the refund when swapping adjacent stones. The second line contains a non-empty string S of at most 5000 characters. The i-th character of S indicates the color of the i-th stone, from left to right, in the initial arrangement of the stones. The character is either the uppercase letter “B” or the uppercase letter “W”, indicating respectively a black or a white stone.</p>

### 출력 

 <p>Output a line with an integer representing the minimum number of coins Shagga will have to pay Dolf in order to arrange the stones such that all the black ones are to the left of all the white ones.</p>

