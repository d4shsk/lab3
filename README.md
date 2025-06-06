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

## 1.3
### Задача
Вычислить, используя структуру комплексного числа, комплексную экспоненту exp(z) некоторого z принадлежит C:
### Математическая модель
$$
e^z = \sum_{n=0}^{\infty} \frac{z^n}{n!} = 1 + z + \frac{z^2}{2!} + \frac{z^3}{3!} + \ldots
$$
### Список идентификаторов
| Имя     | Тип     | Смысл                                              |
| ------- | ------- | -------------------------------------------------- |
| Complex | struct  | Тип структуры для представления комплексного числа |
| real    | double  | Действительная часть комплексного числа            |
| imag    | double  | Мнимая часть комплексного числа                    |
| z       | Complex | Входное комплексное число                          |
| e       | double  | Точность вычислений                                |
| result  | Complex | Результат вычисления                               |
| term    | Complex | Текущий член ряда в complex_exp                    |
| sum     | Complex | Накопленная сумма ряда в complex_exp               |
| m       | double  | Модуль текущего члена ряда для проверки точности   |
| n       | int     | Счётчик итераций в циклах                          |
| a, b    | Complex | Параметры функций complex_add, complex_mul         |
| i       | int     | Итерационная переменная в циклах                   |
### Код программы
```C
#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex complex_add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex complex_multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex complex_pow(Complex z, int n) {
    Complex result = {1.0, 0.0};
    for (int i = 0; i < n; i++) {
        result = complex_multiply(result, z);
    }
    return result;
}

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

Complex complex_exp(Complex z, double e) {
    Complex sum = {1.0, 0.0};
    Complex term = {1.0, 0.0}; 

    for (int n = 1; ; n++) {
        term = complex_multiply(term, z);
        term.real /= n;
        term.imag /= n;

        double m = sqrt(term.real * term.real + term.imag * term.imag);
        if (m < e) break;

        sum = complex_add(sum, term);
    }

    return sum;
}

void print_complex(Complex z) {
    printf("%.4f %+.4fi\n", z.real, z.imag);
}
int main() {

    Complex z = {1.0, 2.0};
    double e = 1e-6;

    Complex result = complex_exp(z, e);

    printf("\nexp(1 + 2i) ≈ ");
    print_complex(result);
    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/bwR47qGC/image.png)](https://postimg.cc/CRzvDTsk)
## 1.4
### Задача
Используя так называемые "битовые" поля в структуре C, создать экономную структуру в оперативной памяти для заполнения даты некоторого события, например даты рождения человека.
### Математическая модель
--
### Список идентификаторов
| Имя       | Тип          | Смысл                                          |
| --------- | ------------ | ---------------------------------------------- |
| birth_day | struct       | Описывает формат хранения даты                 |
| bd        | BirthDate    | Экземпляр структуры — конкретная дата рождения |
| day       | unsigned int | день                                           |
| month     | unsigned int | месяц                                          |
| year      | unsigned int | год                                            |
### Код программы
```C
#include <stdio.h>

typedef struct {
    unsigned int day   : 5; 
    unsigned int month : 4; 
    unsigned int year  : 12;
} birth_day;

int main() {
    birth_day bd = { .day = 12, .month = 9, .year = 2006 };
    printf("Date: %u.%u.%u\n", bd.day, bd.month, bd.year);
    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/B6w0d4z9/image.png)](https://postimg.cc/mzMJ9fR8)
## 1.5
### Задача
Реализовать в виде структур двунаправленный связный список и совершить отдельно его обход в прямом и обратном направлениях с распечаткой значений каждого элемента списка.
### Математическая модель
--
### Список идентификаторов
| Имя      | Тип           | Смысл                                           |
| -------- | ------------- | ----------------------------------------------- |
| Node     | struct Node   | Описание структуры узла двунаправленного списка |
| data     | int           | Поле данных в узле                              |
| prev     | struct Node * | Указатель на предыдущий узел                    |
| next     | struct Node * | Указатель на следующий узел                     |
| new_node | Node *        | адрес нового узла                               |
| value    | int           | значение для data в новом узле                  |
| first    | Node *        | Указатель на первый узел списка                 |
| second   | Node *        | Указатель на второй узел списка                 |
| third    | Node *        | Указатель на третий узел                        |
| tail     | Node *        | Указатель на последний узел списка              |
| curr     | Node *        | Временный указатель для обхода списка           |
| next     | Node *        | Временный указатель при освобождении памяти     |
### Код программы
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;  
} Node;

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

int main() {
    Node* first   = create_node(1);
    Node* second = create_node(2);
    Node* third  = create_node(3);

    first->next    = second;
    second->prev  = first;
    second->next  = third;
    third->prev   = second;

    Node* tail = third;

    printf("Direct:\n");
    Node* curr = first;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }

    printf("Reverse:\n");
    curr = tail;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->prev;
    }

    curr = first;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/Px17MhkQ/image.png)](https://postimg.cc/34J9KsNk)

## 2.1
### Задача
Напишите программу, которая использует указатель на некоторое объединение union.
### Математическая модель
--
### Список идентификаторов
| Имя  | Тип    | Смысл                                                           |
| ---- | ------ | --------------------------------------------------------------- |
| Data | union  | Тип-объединение, может хранить либо int, либо float, либо char* |
| i    | int    | Поле объединения - целое число                                  |
| f    | float  | Поле объединения - число с плавающей точкой                     |
| s    | char*  | Поле объединения - указатель на строку                          |
| dat    | Data   | Переменная–объединение                                          |
| pdat   | Data * | Указатель на переменную d                                       |
### Код программы
```C
#include <stdio.h>

typedef union {
    int   i;   
    float f;
    char* s;
} Data;

int main() {
    Data dat;
    Data *pdat = &dat; 

    pdat->i = 13;
    printf("int: %d\n", pdat->i);

    pdat->f = 8.76f;
    printf("float: %.2f\n", pdat->f);

    pdat->s = "Hello";
    printf("string: %s\n", pdat->s);

    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/GhMyq5rW/image.png)](https://postimg.cc/YhW0S8vR)

## 2.2
### Задача
Напишите программу, которая использует union для побайтовой распечатки типа unsigned long.
### Математическая модель
--
### Список идентификаторов
| Имя        | Тип                                  | Смысл                                                    |
| ---------- | ------------------------------------ | -------------------------------------------------------- |
| ULongBytes | union                                | Тип-объединение для совместного хранения value и bytes[] |
| value      | unsigned long                        | Поле - само число                                        |
| bytes      | unsigned char[sizeof(unsigned long)] | Поле - массив байтов, перекрывающих value                |
| ub         | ULongBytes                           | Экземпляр объединения                                    |
| v          | unsigned long                        | Локальная переменная для ввода и присвоения числа        |
| u          | size_t                               | Счётчик цикла при выводе байтов                          |
### Код программы
```C
#include <stdio.h>
#include <stdlib.h>

typedef union {
    unsigned long    value;
    unsigned char    bytes[sizeof(unsigned long)];
} ULongBytes;

int main() {
    ULongBytes ub;
    unsigned long v;

    printf("Enter unsigned long: ");
    scanf("%lu", &v);
    ub.value = v;

    printf("Value: %lu\n", ub.value);
    printf("Byte-by-byte representation (%zu bytes):", sizeof(unsigned long));
    for (size_t i = 0; i < sizeof(unsigned long); i++) {
        printf(" %02X", ub.bytes[i]);
    }
    printf("\n");

    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/63NsrS29/image.png)](https://postimg.cc/f35gZ8fF)

## 2.3
### Задача
Создайте перечислимый тип данных (enum) для семи дней недели и распечатайте на экране его значения, как целые числа
### Математическая модель
--
### Список идентификаторов
| Имя       | Тип       | Смысл                                       |
| --------- | --------- | ------------------------------------------- |
| DayOfWeek | enum      | Пользовательский тип для дней недели        |
| MONDAY    | enum      | Понедельник (0)                             |
| TUESDAY   | enum      | Вторник (1)                                 |
| WEDNESDAY | enum      | Среда (2)                                   |
| THURSDAY  | enum      | Четверг (3)                                 |
| FRIDAY    | enum      | Пятница (4)                                 |
| SATURDAY  | enum      | Суббота (5)                                 |
| SUNDAY    | enum      | Воскресенье (6)                             |
| i         | DayOfWeek | Переменная для перебора в цикле             |
### Код программы
```C
#include <stdio.h>

typedef enum {
    MONDAY,    // 0
    TUESDAY,   // 1
    WEDNESDAY, // 2
    THURSDAY,  // 3
    FRIDAY,    // 4
    SATURDAY,  // 5
    SUNDAY     // 6
} DayOfWeek;

int main() {
    for (DayOfWeek i = MONDAY; i <= SUNDAY; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/TPMNFbR0/image.png)](https://postimg.cc/759NTfJJ)

## 2.4
### Задача
Создайте так называемое размеченное объединение union, которое заключено в виде поля структуры struct вместе с ещё одним полем, которое является перечислением епиm и служит индикатором того, что именно на текущий момент хранится в таком вложенном объединении. Создать и заполнить динамический массив таких структур с объединениями внутри, заполняя вспомогательное поле перечисления еnum для сохранения информации о хранимом в каждом размеченном объединении типе данных. Реализовать распечатку данных массива таких структур в консоль.
### Математическая модель
--
### Список идентификаторов
| Имя         | Тип          | Смысл                                                |
| ----------- | ------------ | ---------------------------------------------------- |
| DataType    | enum         | Тег, указывающий на текущий вариант в DataValue      |
| TYPE_INT    | enum         | Вариант int                                          |
| TYPE_FLOAT  | enum         | Вариант float                                        |
| TYPE_STRING | enum         | Вариант char*                                        |
| DataValue   | union        | Объединение для хранения одного из трёх типов        |
| i           | int          | Целочисленное значение                               |
| f           | float        | Значение с плавающей точкой                          |
| s           | char*        | Указатель на строку                                  |
| TaggedData  | struct       | "Размеченная" запись: тег + значение                 |
| type        | DataType     | Хранит значение тега                                 |
| data        | DataValue    | Хранит само значение                                 |
| n           | size_t       | Количество элементов в динамическом массиве          |
| arr         | TaggedData * | Указатель на первый элемент массива структур         |
| idx         | size_t       | Счётчик цикла                                        |
| buf         | char[32]     | Временный буфер для формирования строкового значения |
### Код программы
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} DataType;

typedef union {
    int    i; 
    float  f;
    char* s;
} DataValue;


typedef struct {
    DataType   type;
    DataValue  data;
} TaggedData;

int main() {
    size_t n;
    printf("Enter amount of elements ");
    if (scanf("%zu", &n) != 1) return 1;

    TaggedData* arr = malloc(n * sizeof * arr);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    for (size_t idx = 0; idx < n; idx++) {
        switch (idx % 3) {
        case 0:
            arr[idx].type = TYPE_INT;
            arr[idx].data.i = (int)(idx * 10);
            break;
        case 1:
            arr[idx].type = TYPE_FLOAT;
            arr[idx].data.f = (float)(idx) / 2.0f;
            break;
        case 2:
            arr[idx].type = TYPE_STRING;
            {
                char buf[32];
                snprintf(buf, sizeof buf, "str_%zu", idx);
                arr[idx].data.s = strdup(buf);
            }
            break;
        }
    }

    for (size_t idx = 0; idx < n; idx++) {
        printf("[%zu] ", idx);
        switch (arr[idx].type) {
        case TYPE_INT:
            printf("INT    = %d\n", arr[idx].data.i);
            break;
        case TYPE_FLOAT:
            printf("FLOAT  = %.2f\n", arr[idx].data.f);
            break;
        case TYPE_STRING:
            printf("STRING = \"%s\"\n", arr[idx].data.s);
            break;
        }
    }

    for (size_t idx = 0; idx < n; idx++) {
        if (arr[idx].type == TYPE_STRING) {
            free(arr[idx].data.s);
        }
    }
    free(arr);

    return 0;
}
```
### Результаты выполненной работы
[![image.png](https://i.postimg.cc/PrDctHS2/image.png)](https://postimg.cc/kBnwc03b)
