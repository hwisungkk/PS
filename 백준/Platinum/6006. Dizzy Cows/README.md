# [Platinum IV] Dizzy Cows - 6006 

[문제 링크](https://www.acmicpc.net/problem/6006) 

### 성능 요약

메모리: 12548 KB, 시간: 72 ms

### 분류

그래프 이론, 위상 정렬, 방향 비순환 그래프

### 제출 일자

2025년 11월 8일 18:28:09

### 문제 설명

<p>The cows have taken to racing each other around the farm but they get very dizzy when running in circles, and everyone knows that dizzy cows don't produce any milk. Farmer John wants to convert all of the two-way cow paths in the farm to one-way paths in order to eliminate any 'cycles' and prevent the cows from getting dizzy. A 'cycle' enables a cow to traverse one or more cow paths and arrive back at her starting point, thus completing a loop or circle.</p>

<p>The farm comprises N pastures (1 <= N <= 100,000) conveniently numbered 1..N. M1 (1 <= M1 <= 100,000) one-way cow paths and M2 two-way cow paths (1 <= M2 <= 100,000) connect the pastures. No path directly connects a pasture to itself, although multiple paths might connect two different pastures. A cow may or may not be able to travel between any two given pastures by following a sequence of cow paths.</p>

<p>Your job is to assign a direction to the two-way cow paths such that the entire farm (ultimately with only one-way paths) has no cycles. That is, there should be no sequence of one-way cow paths which leads back to its starting position. The existing one-way cow paths do not form a cycle and should be left as they are.</p>

<p>One-way cow paths run from pasture A_i (1 <= A_i <= N) to pasture B_i (1 <= B_i <= N). Two-way cow paths connect pastures X_i (1 <= X_i <= N) and Y_i (1 <= Y_i <= N).</p>

<p>Consider this example:</p>

<pre>             1-->2
             |  /|
             | / |
             |/  |
             3<--4</pre>

<p>The cow paths between pastures 1 and 3, 2 and 3, and 2 and 4 are two-way paths. One-way paths connect 1 to 2 and also 4 to 3. One valid way to convert the two-way paths into one-way paths in such a way that there are no cycles would be to direct them from 1 to 3, from 2 to 3, and from 3 to 4:</p>

<pre>             1-->2
             |  /|
             | / |
             vL  v
             3<--4</pre>

### 입력 

 <ul>
	<li>Line 1: Three space separated integers: N, M1, and M2</li>
	<li>Lines 2..1+M1: Line i+1 describes a one-way cow path using two space separated integers: A_i and B_i</li>
	<li>Lines 2+M1..1+M1+M2: Line i+M1+1 describes a two-way cow path using two space separated integers: X_i and Y_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..M2: Line i should contain two space-separated integers: either X_i and Y_i or Y_i and X_i, depending on the direction assigned to the i-th two-way path. The two-way paths must appear in the same order in the output as they do in the input. If there is no solution, output "-1" on a single line.</li>
</ul>

<p> </p>

