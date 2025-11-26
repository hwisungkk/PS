# [Gold II] Rączy jelonek - 8446 

[문제 링크](https://www.acmicpc.net/problem/8446) 

### 성능 요약

메모리: 108384 KB, 시간: 96 ms

### 분류

임의 정밀도 / 큰 수 연산, 너비 우선 탐색, 그래프 이론, 그래프 탐색, 수학, 런타임 전의 전처리

### 제출 일자

2025년 11월 26일 19:06:27

### 문제 설명

<p>Rączy jelonek zmierza długimi susami na polanę. Rozpiera go energia, więc każdy jego skok może być nawet dwa razy dłuższy od poprzedniego.</p>

<p>Formalnie rzecz ujmując, w każdym momencie energia jelonka jest na określonym poziomie <em>i</em>. Jelonek ma dwie możliwości ruchu:</p>

<ul>
	<li>skok o <em>i</em> metrów w przód lub w tył, powodujący automatyczne przełączenie na poziom energii 2<em>i</em>,</li>
	<li>skok wzwyż, który nie powoduje przemieszczenia na drodze do polany oraz skutkuje przełączeniem na poziom <em>i</em>/2.</li>
</ul>

<p>Początkowo, jelonek ma energię równą 1. W momencie, gdy jego energia jest równa 1 i jelonek skoczy wzwyż, zatrzymuje się.</p>

<p>Poniżej przedstawiono przykładową podróż rączego jelonka, która rozpoczęła się w punkcie po lewej stronie drogi. Numery nad strzałkami oznaczają poziom energii jelonka <i>po</i> danym skoku. Wartość 0 oznacza, że jelonek się zatrzymał.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ffcd3ced-4a3d-4a55-a1ae-45f96f3085ed/-/preview/"></p>

<p>Droga prowadząca do polany jest nieskończona w obydwóch kierunkach. Oznacza to, że jelonek w trakcie podróży może znaleźć się za polaną lub przed punktem, z którego wyrusza. Jelonka od celu dzieli początkowo <i>n</i> metrów. Oblicz, jaka jest najmniejsza liczba skoków, która pozwoli mu dotrzeć do polany i zatrzymać się tam.</p>

### 입력 

 <p>Pierwsza linia wejścia, zawiera jedną liczbę całkowitą <em>n</em> (1 ≤ n ≤ 10<sup>100</sup>) oznaczająca odległość pomiędzy jelonkiem a polaną. Dodatkowo, w testach wartych sumarycznie 40% punktów, <em>n</em> ≤ 100 000.</p>

### 출력 

 <p>Wypisz jedną liczbę całkowitą równą minimalnej liczbie skoków, które musi wykonać jelonek, aby dotrzeć do polany i zatrzymać się.</p>

