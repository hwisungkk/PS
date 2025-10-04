# [Platinum V] Clock Tree - 18785 

[문제 링크](https://www.acmicpc.net/problem/18785) 

### 성능 요약

메모리: 2452 KB, 시간: 0 ms

### 분류

그래프 이론, 그리디 알고리즘, 그래프 탐색, 트리, 깊이 우선 탐색, 불변량 찾기

### 제출 일자

2025년 10월 1일 04:44:40

### 문제 설명

<p>Farmer John's new barn has a truly strange design: it consists of $N$ rooms ($2 \leq N \leq 2500$), conveniently numbered $1 \ldots N$, and $N-1$ corridors. Each corridor connects a pair of rooms, in such a way that it is possible to walk from any room to any other room along a series of corridors.</p>

<p>Every room in the barn has a circular clock on the wall with the standard integers $1 \ldots 12$ around its face. However, these clocks only have one hand, which always points directly at one of the integers on the clock face (it never points between two of these integers).</p>

<p>Bessie the cow wants to synchronize all the clocks in the barn so they all point to the integer 12. However, she is somewhat simple-minded, and as she walks around the barn, every time she enters a room, she moves the hand on its clock ahead by one position. For example, if the clock pointed at 5, it would now point at 6, and if the clock pointed at 12, it would now point at 1. If Bessie enters the same room multiple times, she advances the clock in that room every time she enters.</p>

<p>Please determine the number of rooms in which Bessie could start walking around the barn such that she could conceivably set all the clocks to point to 12. Note that Bessie does not initially advance the clock in her starting room, but she would advance the clock in that room any time she re-entered it. Clocks do not advance on their own; a clock only advances if Bessie enters its room. Furthermore, once Bessie enters a corridor she must exit through the other end (it is not allowed to walk partially through the corridor and loop back around to the same room).</p>

### 입력 

 <p>The first line of input contains $N$. The next line contains $N$ integers, each in the range $1 \ldots 12$, specifying the initial clock setting in each room. The next $N-1$ lines each describe a corridor in terms of two integers $a$ and $b$, each in the range $1 \ldots N$, giving the room numbers connected by the corridor.</p>

### 출력 

 <p>Print the number of rooms in which Bessie could start, such that it is possible for her to set all clocks to point to 12.</p>

