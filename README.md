# Approximation
### При написании были в полной мере использованы средства 17-го стандарта C++! 
Цель этого проекта - реализация и сравнение трёх алгоритмов интерполяции:
- [x] Метод Ньютона
- [ ] Полиномы Чебышёва
- [ ] Кусочно-линейная (методом МНК)

Отрисовка графиков функций производится прямо в программе с помощью обёртки `gnuplot`.
Сборка и запуск:
```
make
./main "ИМЯ ФАЙЛА"
```
Входные данные для корректной обработки `gnuplot`'ом должны быть организованы так:
```
x1, y1
x2, y2
x3, y3
x4, y4
...
```
Иными словами, сначла идут точка на оси `x` - запятая - пробел - точка на оси `y`.
