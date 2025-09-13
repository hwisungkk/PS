# [Gold II] Jumping Worm - 13365 

[문제 링크](https://www.acmicpc.net/problem/13365) 

### 성능 요약

메모리: 6104 KB, 시간: 32 ms

### 분류

그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 다이얼

### 제출 일자

2025년 9월 13일 15:50:36

### 문제 설명

<p>The forest where a little worm lives has N trees, neatly located at positions 1to N. The worm dreams to be the first ever being to place its slimy belly on the moon... Nah, not really. Well, he just wants to be at the top of the N th tree. Right now, the little worm is at the base of the 1st tree. He can move in one of the following two ways:</p>

<ol>
	<li>When he is on the i<sup>th</sup> tree, he can climb up u<sub>i</sub> units at a time. The height after any climb will never be higher than the height of the tree.</li>
	<li>He can jump from the i<sup>th</sup> tree to an adjacent tree (the (i – 1)<sup>th</sup> or the (i + 1)<sup>th</sup> tree). The worm is a good jumper, so he can jump to the same height on the nearby tree. However, if the top of the adjacent tree is lower than the worm’s current height, the worm will end up on the top of this lower tree.</li>
</ol>

<p>Each move takes the worm 1 second. But, after each move, the worm has to rest for 1 second. During this time, he will fall down due to gravity for d<sub>i </sub>units if he is on the i<sup>th</sup> tree. Yet he cannot go below height 0. There is an exception to this rule: when he jumps to the top of atree, he does not have to rest;hecan continue moving right after his previous move. Because trees are generally different, the u<sub>i</sub> and d<sub>i</sub> of different tree can be different.</p>

<p>Remarks: Each of the two maneuvers requires exactly 1 second, even in the cases where the movement does not go the full length because it reaches the top or the bottom of a tree.</p>

<p>Example: There are 8 trees, whose heights from left to right are 5, 5, 3, 3, 3, 4, 5, and 5 units, as shown below. All the u<sub>i</sub> ’sare 3 units per second, and the d<sub>i</sub> ’sare 2 units per second. Figures a) to g) show one possible way for the little worm to move from the starting position, the base of the first tree, to the top of the 8<sup>th</sup> tree in Figure f). </p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.10.30.png" style="height:98px; width:300px"></p>

<p>a) The little worm begins at the base of the first tree.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.11.25.png" style="height:101px; width:300px"></p>

<p>b) After the worm climbed 3 units up and fell 2 units down during the wait, he ended up at the position of the flag.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.12.06.png" style="height:108px; width:300px"></p>

<p>c) He must spend 5 seconds to get to the top.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.12.49.png" style="height:116px; width:300px"></p>

<p>d) Then, he jumpped to the tree 2, 3, 4, 5 on the 6th, 7th, 8th, 9th seconds respectively without having to rest.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.13.57.png" style="height:101px; width:300px"></p>

<p>e) While on the 6th tree, the little worm was not at the top, so he must rest for 1 second. During the time, he fell down 2 units. Then, he moved to the top of the tree again.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.14.47.png" style="height:115px; width:300px"></p>

<p>f) The little worm continued its journey to the top of the 8th tree.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.15.44.png" style="height:114px; width:300px"></p>

<p>g) This figure summarized the trip of the little worm from Figure a) to Figure f). The total time required for this trip is 16 seconds.</p>

<p>Now if the worm decides to instead jump from the base of one trees to the next as shown in the figure below, and only climbs up on the last tree, he will take a total of 19 seconds. Note that since the jump is not made at the top, he must rest for 1 second (shown as dots). Also, since the worm is at the base, he cannot fall further while resting.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.17.32.png" style="height:102px; width:300px"></p>

<p>It turns out for this particular example, the shortest possible travel time for the little worm is 14 seconds, as shown in the figure below.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13365/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-11%20%EC%98%A4%ED%9B%84%202.19.15.png" style="height:112px; width:300px"></p>

<p>Your task Given N trees, the u<sub>i</sub> and d<sub>i</sub> of all trees, find the shortest travel time (in seconds) from the base of the 1st tree to the top of the Nth tree.</p>

### 입력 

 <p>For the first line, there is a single integer, K, representing the number of test cases. For each test case, there are 4 lines. (1 ≤ K ≤ 10)</p>

<ol>
	<li>The first line contains a single integer, N, the number of the trees (0 < N ≤ 1000).</li>
	<li>The second line contains N numbers, h<sub>i </sub>, where i goes from 1 to N. Note that h<sub>i </sub>represents the height of each tree. (1 ≤ h<sub>i</sub> ≤ 1000)</li>
	<li>The third line contains N numbers, u<sub>i</sub> , where i goes from 1 to N. Note that u<sub>i</sub> represents the climb rate of each tree. (1 ≤ u<sub>i</sub> ≤ 1000)</li>
	<li>The fourth line contains N numbers, d<sub>i</sub> , where i goes from 1 to N. Note that d<sub>i </sub>represents the fall rate of each tree. (1 ≤ d<sub>i</sub> ≤ 1000)</li>
</ol>

### 출력 

 <p>For each test case, you print out on a single line the shortest travel time of the little worm. However, if it is not possible to reach the top of the Nth tree, you must print, in capital letter, the word “NEVER”, without the quotation.</p>

