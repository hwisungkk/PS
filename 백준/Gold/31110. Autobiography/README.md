# [Gold IV] Autobiography - 31110 

[문제 링크](https://www.acmicpc.net/problem/31110) 

### 성능 요약

메모리: 34548 KB, 시간: 200 ms

### 분류

조합론, 차수열, 그래프 이론, 수학

### 제출 일자

2025년 10월 28일 12:24:37

### 문제 설명

<p>Bobo has an undirected graph with $n$ vertices and $m$ edges. The vertices are numbered by $1, \dots, n$, and the $i$-th edge is between the $a_i$-th and the $b_i$-th vertex. Plus, the $i$-th vertex is associated with a character $c_i$.</p>

<p>Find the number of ways to choose four <strong>distinct</strong> vertices $(u, v, w, x)$ such that</p>

<ul>
	<li>$u$ and $v$, $v$ and $w$, $w$ and $x$ are connected by an edge,</li>
	<li>$c_u = \mathtt{b}$, $c_v = \mathtt{o}$, $c_w = \mathtt{b}$, $c_x = \mathtt{o}$.</li>
</ul>

### 입력 

 <p>The input consists of several test cases terminated by end-of-file. For each test case,</p>

<p>The first line contains two integers $n$ and $m$.</p>

<p>The second line contains $n$ characters $c_1 \dots c_n$.</p>

<p>For the following $m$ lines, the $i$-th line contains two integers $a_i$ and $b_i$.</p>

### 출력 

 <p>For each test case, output an integer which denotes the number of ways.</p>

