# [Gold III] K-Words Problem - 30037 

[문제 링크](https://www.acmicpc.net/problem/30037) 

### 성능 요약

메모리: 2700 KB, 시간: 72 ms

### 분류

자료 구조, 구현, 스택, 문자열

### 제출 일자

2025년 2월 25일 13:56:15

### 문제 설명

<p>아티초크는 교양과목 '한국 문화로 보는 프로그래밍 언어론'을 수강 중이다.</p>

<p>아티초크는 지난주에 과제로 '아희가 한국 문화에 미친 영향'을 주제로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5\,000$</span></mjx-container>단어 분량의 보고서를 작성했는데, 이번 주에는 이 보고서를 짧게 요약하는 과제가 나왔다.</p>

<p>이번 학기에 전공과목만 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$7$</span></mjx-container>과목을 수강하고 있었던 아티초크는 보고서 요약을 직접 할 여유가 없었다.</p>

<p>따라서 아래의 규칙에 따라 보고서를 요약해주는 프로그램을 만들기로 했다. 규칙은 다음과 같다.</p>

<ol>
	<li>보고서에 단어 'Korea'가 등장할 경우, 다음에 나오는 단어와 합쳐 'K-단어'로 축약한다. (ex. Korea language → K-Language)
	<ul>
		<li>단어 'Korea'는 대문자와 소문자를 구분한다.</li>
		<li>단어 'Korea' 다음에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.</li>
		<li>이 규칙을 여러 번 연달아 적용할 수 있는 경우 뒤에서부터 적용한다.</li>
		<li>단어 'Korea' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.</li>
	</ul>
	</li>
	<li>보고서에 단어 'of' 직후에 단어 'Korea'가 등장할 경우, 단어 'of' 직전에 나오는 단어와 합쳐 K-단어로 축약한다. (ex. Language of Korea → K-Language)
	<ul>
		<li>단어 'of'와 'Korea'는 대문자와 소문자를 구분한다.</li>
		<li>단어 'of' 직전에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다.</li>
		<li>이 규칙을 여러 번 연달아 적용할 수 있는 경우 앞에서부터 적용한다.</li>
		<li>단어 'of' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.</li>
		<li>단어 'of' 앞에 단어가 없거나, 단어 'of' 직전에 나오는 단어에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다.</li>
		<li>단어 'Korea' 뒤에 문장 부호가 붙어있는 경우, 단어 'Korea' 뒤의 문장 부호를 단어 'of' 직전에 나오는 단어 뒤에 붙인다. </li>
	</ul>
	</li>
	<li>1번 규칙과 2번 규칙을 한 문장에 동시에 적용할 수 있는 경우, 2번 규칙을 먼저 적용한다.</li>
</ol>

<p>아티초크는 전공 과제가 너무 밀려, 보고서 요약 프로그램을 작성할 여유조차 없었다. 그런 아티초크를 대신하여 구현해 보자.</p>

### 입력 

 <p>첫 번째 줄에 문장의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>5</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N (1 \le N \le 5\,000)$</span></mjx-container> 이 주어진다.</p>

<p>다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 알파벳 대소문자와 문장부호 느낌표(!), 물음표(?), 쉼표(,), 마침표(.)로 구성된 문장이 주어진다.</p>

<p>각 문장들은 하나 이상의 단어로 이루어져 있으며, 각 단어마다 하나 이상의 알파벳이 존재함이 보장된다.</p>

<p>한 단어의 길이는 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>50</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$50$</span></mjx-container>자, 입력으로 들어오는 단어들의 수의 합은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5\,000$</span></mjx-container>을 넘지 않는다.</p>

<p>단어들 사이는 하나의 공백(띄어쓰기)로 구분하며, 문장들 사이는 줄바꿈 문자로 구분한다.</p>

<p>문장부호는 단어의 끝에서만 등장할 수 있으며, 단어 하나당 문장부호는 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개까지 들어갈 수 있다.</p>

<p>특히 마침표의 경우 문장의 마지막 단어에 반드시 등장하며, 이외의 위치에서는 등장하지 않는다.</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 문제에서 제시된 규칙에 맞게 요약된 보고서를 출력한다.</p>

