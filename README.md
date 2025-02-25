# Лабораторная работа: Реализация кольцевого списка и операций над ним

## Описание
Данная лабораторная работа представляет собой реализацию **кольцевого односвязного списка**. В программе реализованы основные операции для работы со списком, включая добавление элементов, очистку списка, а также операцию нахождения пересечения двух списков.

## Основные компоненты

### 1. Структура `Link`
- Представляет узел списка.
- Содержит:
  - `val` — значение узла.
  - `next` — указатель на следующий узел.

### 2. Класс `List`
Реализует кольцевой односвязный список. Основные методы:
- **`add(int a)`**: Добавляет элемент в список с сохранением порядка возрастания.
- **`clean()`**: Очищает список, освобождая память.
- **`peresechenie(List list_2, List list_3)`**: Находит пересечение двух списков и сохраняет результат в третий список.
- **Перегрузка операторов**:
  - `operator<<`: Вывод списка в поток.
  - `operator>>`: Ввод списка из потока.
