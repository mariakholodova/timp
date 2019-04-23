#  Практическая работа №7

Задание: 
- Реализовать Быструю сортировку;
- Реализовать Пирамидальную сортировку.

Методическое пособине находится на сайте [http://edu.fb.tusur.ru/](http://edu.fb.tusur.ru)
Отчет оформлен по [markdown'у](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet 'Тык').
________________________________________________
# Ход работы

Была использована подсистема Ubuntu 18.04, которую мы использовали для выполнения [Практической работы №1](https://github.com/mariakholodova/timp/tree/pr1) и последующих
После запуска подсистемы мы создали файлы и записали в них код для выполнения задания 
```sh
$ > QuickSort.c
$ nano QuickSort.c
$ > PyramidSort.c
$ nano PyramidSort.c
```
После этого выполняется команда компиляции "gcc <имя файла>", в результате чего создан исполняемый файл "a.out", который мы и запустили. 

Ниже представлена такая работа со вторым файлом
```sh
$  gcc PyramidSort.c
$  ./a.out
```
После этого создаем все остальные необходимые файлы (скриншоты работы программы, README), прописываем в .gitignore файл a.out, прописываем commit
```sh
$ nano .gitignore
$ > README.md
$ nano README.md
$ git add .
$ git commit -m "Исправлены мелкие ошибки "
$ git push 
```
___________________________
# Результат

#### Таблицы 

Результаты работы сортировок

Быстрая сортировка

|input|output|
|------|-----|
|10||
|4 7 5 4 6 3 1 4 6 3 5 3|1 3 3 4 4 4 5 6 6 7|

Скрин работы

[![Скрин1](https://github.com/mariakholodova/timp/blob/pr7/QuickSort.png)](https://github.com/mariakholodova/timp/blob/pr7/QuickSort.png, "Тык")

Пирамидальная сортировка

|input|output|
|------|-----|
|10||
|7 8 5 4 2 5 72 6 4 23|2 4 4 5 5 6 7 8 23 72|

Скрин работы

[![Скрин2](https://github.com/mariakholodova/timp/blob/pr7/PyramidSort.png)](https://github.com/mariakholodova/timp/blob/pr7/PyramidSort.png, "Тык")







