# Допълнително упражнение (14.12.2019г.) - Подготовка за второ контролно.

## Символни низове

### Задача 1
Напишете програма, която обръща даден символен низ наобратно. Използвайте я, за да определите дали един низ е палиндром ( дали обърнат наобратно дава същият резултат).

[Решение](./strings/task1.cpp)

### Задача 2
Напишете програма, която обхожда символен низ. Програмата трябва да замени последователности от тип буква-цифра със буквата, изместена с толкова символи напред в ASCII таблицата. Резултатът да бъде записан в нов масив
Пример: `a1bb1c5 -> bbch`

[Решение](./strings/task2.cpp)

## Двумерни масиви

### Задача 1
Напишете програма, която смята сбора на елементите над главния диагонал на матрица със елементите под второстепенния диагонал (някои от тях съвпадат, тоест трябва да се вземат два пъти)

**Забележка:** Формулите за диагоналитте можете да видите [ТУК](http://web-tourist.net/login/login/view.php?st=3401&fbclid=IwAR11VEZjLVgJH2pdt_HnimEKy_yPw4DTjpfpN5pi85r8A27BPjJX1FIYrFg) 

[Решение](./matrices/task1.cpp)
       
### Задача 2
Напишете програма, която попълва матрица по няколко начина – стандартно (ред по ред), стълб по стълб, диагонално, започвайки от горен ляв ъгъл.

### Задача 3
Транспонирайте матрица

### Задача 4
Напишете програма, която приема X точки и ги складира в двумерен масив ( т.е всяка точка на отделен ред/колона). Програмата сортира точките по разстоянието им от началото на координатната система, във възходящ ред.
 
[Решение](./matrices/task4.cpp)

## Рекурсия

### Задача 1
Напишете програма, която изчислява Фибоначи и Факториел рекурсивно (**NB! Don’t do this IRL**)

[Решение](./recursion/task1.cpp)

### Задача 2
Напишете програма, която обхожда рекурсивно лабиринт. Лабиринтът представлява матрица NxK, като започваме от горният ляв ъгъл и приключваме, когато стигнем до клетка с числото `4`. Ако матрицата съдържа `1` в дадена клетка, то през нея не можем да минем. За други числа – клетката е свободна.

[Решение](./recursion/task2.cpp)

### Задача 3
Напишете програма, която проверява рекурсивно дали дадена редица е растяща.

[Решение](./recursion/task3.cpp)

### Задача 4
Напишете функция, която рекурсивно обръща символен низ. Използвайте я, за да обходите символен низ. Програмата трябва да обърне всички думи(!) в низа, без да обръща редът им на появяване.

[Решение](./recursion/task4.cpp)