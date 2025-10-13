# [Gold V] Plus Minus Four Squares - 30538 

[문제 링크](https://www.acmicpc.net/problem/30538) 

### 성능 요약

메모리: 2188 KB, 시간: 60 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 제출 일자

2025년 10월 8일 17:21:03

### 문제 설명

<p>Every non-negative integer $n$ may be written as the sum of the squares of four integers:</p>

<p>$$n = a^2 + b^2 + c^2 + d^2$$</p>

<p>By allowing subtraction, $n$ may be written in many more ways; in fact infinitely many.</p>

<p>In this problem you will count the number of different ways to express an input $n$ as a sum or difference of four squares with several restrictions:</p>

<p>First, we need to decide what <em>different</em> means.</p>

<p>Any of $a$, $b$, $c$, $d$ may be replaced by its negative. We do not want to count these as <em>different</em> so we will only count different <em>squared</em> values.</p>

<p>Reordering $a$, $b$, $c$, $d$ does not give a <em>different</em> representation.</p>

<p>So, we define a <em>plus minus four square</em> representation of a non-negative integer $n$ as a sequence of four perfect squares in <em>non-increasing</em> order with plus or minus signs whose computation results in $n$.</p>

<p>In addition, we add the following restrictions:</p>

<ul>
	<li>The first square must be no more than $n$ to avoid having infinitely many representations.</li>
	<li>If the same square appears multiple times <strong>all</strong> appearances must be preceded by (a possibly implicit) plus sign or <strong>all</strong> must be preceded by a minus sign. This avoids something like: $$64 + 36 - 36 + 0$$</li>
	<li>A square of zero <em>must</em> be preceded by a plus sign.</li>
</ul>

<p>For example, the only sums of squares which add to 64 are:</p>

<p>$$64 + 0 + 0 + 0$$ $$16 + 16 + 16 + 16$$</p>

<p>If we allow minus signs with the above additional restrictions we have the following which each sum up to $64$:</p>

<p>$$64 + 25 - 16 - 9$$ $$64 - 25 + 16 + 9$$ $$64 + 0 + 0 + 0$$ $$49 + 49 - 25 - 9$$ $$49 + 36 - 25 + 4$$ $$49 + 25 - 9 - 1$$ $$49 + 16 - 1 + 0$$ $$36 + 36 - 9 + 1$$ $$36 + 36 - 4 - 4$$ $$36 + 25 + 4 - 1$$ $$36 + 16 + 16 - 4$$ $$16 + 16 + 16 + 16$$</p>

<p>Write a program which takes as input a <em>non-negative</em> integer $n$ and outputs a count of the number of different <em>four square plus minus</em> representations of $n$.</p>

### 입력 

 <p>Input consists of one line containing a single non-negative decimal integer ($0 < n ≤ 5000$).</p>

### 출력 

 <p>There is one line of output that consists of a single decimal integer giving a count of the number of different <em>four square plus minus</em> representations of $n$.</p>

