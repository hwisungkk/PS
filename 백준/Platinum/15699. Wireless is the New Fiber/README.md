# [Platinum IV] Wireless is the New Fiber - 15699 

[문제 링크](https://www.acmicpc.net/problem/15699) 

### 성능 요약

메모리: 2552 KB, 시간: 16 ms

### 분류

그래프 이론, 그리디 알고리즘, 정렬, 트리, 차수열

### 제출 일자

2025년 10월 26일 11:48:50

### 문제 설명

<p>A new type of unbounded-bandwidth wireless communication has just been tested and proved to be a suitable replacement for the existing, fiber-based communications network, which is struggling to keep up with traffic growth. You have been charged with deciding the layout of the new communications network. The current communications network consists of a set of nodes (which route messages), and links of fiber, each of which connects two different nodes. For each pair of nodes, there exists at least one way (but possibly more, for bandwidth purposes) to travel along the fiber between the two.</p>

<p>The new communications network will not have any fiber. Instead, it will have wireless links, each connecting two nodes. These links have unbounded bandwidth but are expensive, so it has been decided that as few of these links will be built as possible to provide connectivity; for each pair of nodes there should be exactly one way to travel between them along the wireless links. Moreover, you discovered that the nodes have each been built with a particular number of connections in mind. For each node, if it will be connected to a different number of links than it is today, it will have to be reorganized, and that is costly.</p>

<p>Your task is to design the new network so that it has precisely one path between each pair of nodes while minimizing the number of nodes that do not have the same number of connections as in the original network. Figure K.1 shows the original network and a solution for Sample Input 1.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15699/1.png" style="width: 526px; height: 245px;"></p>

<p style="text-align: center;">Figure K.1: Illustration of Sample Input 1.</p>

### 입력 

 <p>The input begins with a line containing two integers n (2 ≤ n ≤ 10<sup>4</sup>) and m (1 ≤ m ≤ 10<sup>5</sup>), denoting the number of nodes and the number of fiber links in the existing network. The nodes are numbered from 0 to n − 1. Each of the next m lines contains two distinct integers a<sub>i</sub> and b<sub>i</sub>, denoting the fact that the i<sup>th</sup> fiber link connects nodes numbered a<sub>i</sub> and b<sub>i</sub>. It is guaranteed that for each pair of nodes there exists at least one path connecting the two nodes. Any pair of nodes may have more than one fiber link connecting them.</p>

### 출력 

 <p>Display the smallest number of nodes for which the number of connected links needs to change. Starting on the next line, display a system of connections in the same format as the input. That is, display a line containing the number of nodes (this will be the same as in the input) and the number of wireless links, and then on subsequent lines descriptions of the links. If more than one layout is possible, any valid layout will be accepted.</p>

