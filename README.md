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
| Имя     | Тип                   | Смысл                                     |
| ------- | --------------------- | ----------------------------------------- |
| FuncPtr | typedef void (*)(int) | Тип-указатель на функцию |
| Structure | struct              | Структура, хранящая функцию |
| print   | FuncPtr               | Поле структуры: указатель на функцию      |
| I       | struct M              | Экземпляр структуры для вызова функции    |
| value   | int                   | число для печати                          |


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

## 1.2
### Задача
Создать структуру для вектора в 3-х мерном пространстве. Реализовать и использовать в своей программе следующие операции над векторами: 
- скалярное умножение векторов; 
- векторное произведение; 
- модуль вектора; 
- распечатка вектора в консоли. 
В структуре вектора указать имя вектора в качестве отдельного поля этой структуры.
### Математическая модель
Скалярное произведение
$$(a,b)=a_xb_x+a_yb_y+a_zb_z$$

Векторное произведение
$$a×b=(a_yb_z−a_zb_y,a_zb_x−a_xb_z,a_xb_y−a_yb_x)$$

Модуль вектора
$$∥v∥=\sqrt{v_x^2+v_y^2+v_z^2}$$

### Список идентификаторов
| Имя    | Тип      | Смысл                                        |
| ------ | -------- | -------------------------------------------- |
| Vector | struct   | Тип структуры для представления 3D-вектора   |
| name   | char[20] | Поле структуры: имя вектора                  |
| x      | double   | Поле структуры: координата X                 |
| y      | double   | Поле структуры: координата Y                 |
| z      | double   | Поле структуры: координата Z                 |
| a      | Vector   | Экземпляр вектора A                          |
| b      | Vector   | Экземпляр вектора B                          |
| scalar | double   | Результат скалярного произведения            |
| cross  | Vector   | Результат векторного произведения            |
| len_a  | double   | Модуль вектора A                             |
| len_b  | double   | Модуль вектора B                             |
| v      | Vector   | Параметр функций vector_length, print_vector |

### Код программы
```C
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[20];
    double x;
    double y;
    double z;
} Vector;

double dot_product(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector cross_product(Vector a, Vector b) {
    Vector result;
    strncpy(result.name, "cross_result", sizeof(result.name));
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

double vector_length(Vector v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

void print_vector(Vector v) {
    printf("%s: (%.2f, %.2f, %.2f)\n", v.name, v.x, v.y, v.z);
}

int main() {
    Vector a = {"A", 1.0, 2.0, 3.0};
    Vector b = {"B", 4.0, 5.0, 6.0};

    double scalar = dot_product(a, b);
    Vector cross = cross_product(a, b);
    double len_a = vector_length(a);
    double len_b = vector_length(b);
    
    printf("\nVectors:\n");
    print_vector(a);
    print_vector(b);
    
    printf("\nScalar: %.2f\n", scalar);
    printf("\nCross:\n");
    print_vector(cross);
    
    printf("\nModules:\n");
    printf("|%s| = %.2f\n", a.name, len_a);
    printf("|%s| = %.2f\n", b.name, len_b);
    
    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/GmBcr8C7/image.png)](https://postimg.cc/gxW9H0r8)
