# Программирование. Язык СИ. Структуры. Объединения. Перечисления.
### Информация о студенте  
Шарманов Даниил Андреевич, 1 курс, ИВТ-1.1
## 1.1  
### Задача  
Создать некоторую структуру с указателем на некоторую функцию
в качестве поля. Вызвать эту функцию через имя переменной этой
структуры и поле указателя на функцию.  
### Математическая модель
--  
### Список идентификаторов
| Имя  | Тип | Смысл |
| --- | --- | --- |
| pointer  | double***  |  указатель |
| pp  | double**  |  указатель |

### Код программы
```C
#include <stdio.h>

typedef void (*FuncPtr)(int);

struct Structure {
    FuncPtr print;
};

void print_num(int value) {
    printf("Value: %d\n", value);
}

int main() {
    struct Structure I;
    I.print = print_num;
    I.print(101); 
    return 0;
}
```
### Результаты выполненной работы
![https://i.postimg.cc/KYrDYY7L/image.png](https://i.postimg.cc/KYrDYY7L/image.png)
