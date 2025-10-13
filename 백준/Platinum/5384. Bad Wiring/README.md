# [Platinum V] Bad Wiring - 5384 

[문제 링크](https://www.acmicpc.net/problem/5384) 

### 성능 요약

메모리: 2184 KB, 시간: 180 ms

### 분류

브루트포스 알고리즘, 그리디 알고리즘

### 제출 일자

2025년 10월 13일 01:51:01

### 문제 설명

<p>The ninja Ryu has infiltrated the Shadow Clan fortress and finds himself in a long hallway. Although ninjas are excellent fighters, they primarily rely on stealth to complete their missions. However, many lights are turned on in the hallway, and this way it will not take long before Ryu is spotted by a guard. To remain unseen, Ryu will need to turn off all the lights as quickly as possible.</p>

<p>The hallway contains a sequence of n lights L<sub>1</sub> . . . L<sub>n</sub>. Some of these lights are turned on. Destroying the lights with his shurikens would be too loud, so he needs to turn them off the old-fashioned way, using light switches. Luckily, there is a switch box nearby with a light switch S<sub>i</sub> for every light L<sub>i</sub>. However, after trying one of the switches, he notices something funny. When he flips the switch S<sub>i</sub>, it does not only turn on/off light L<sub>i</sub>, but also some of the neighboring lights. Ryu notices that there is a parameter D such that flipping switch S<sub>i</sub> turns on/off all the lights L<sub>i-D</sub> . . . L<sub>i+D</sub>, if they exist<sup>2</sup>. Turning on or off lights can attract the attention of the guards, so Ryu would like to turn off all the lights with the minimum number of times flipping a switch. Can you help him out?</p>

<p><sup>2</sup>This means that S<sub>1</sub> turns on/off all the lights L<sub>1</sub> . . . L<sub>D+1</sub> and S<sub>n</sub> turns on/off all the lights L<sub>n-D</sub> . . . L<sub>n</sub>. Of course, if D ≥ n, then L<sub>D+1</sub> and L<sub>n-D</sub> will not exist either.</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with two integers n (1 ≤ n ≤ 100) and D (0 ≤ D ≤ 15): the number of lights and the parameter mentioned above.</li>
	<li>One line with n integers. The i<sup>th</sup> integer describes the current state of light L<sub>i</sub>, where 0 means off and 1 means on.</li>
</ul>

### 출력 

 <p>For every test case in the input, the output should contain one integer on a single line: the minimum number of times Ryu needs to flip a switch to turn off all the lights. If it is impossible to turn off all the lights, then output the string “impossible” instead.</p>

