// заголовочный файл для поддержки стеков и очередей

#ifndef SQUNITL
#define SQUNITL

// структура для хранения стека целочисленных значений на базе односвязных списков
typedef struct LStack *pLStack;
typedef struct LStack {
    int data;
    pLStack pnext;
} LStack;

// создает стек
pLStack LStack_create(int data);
// уничтожает стек
void LStack_destroy(pLStack stack);
// помещает элемент на вершину стека
void LStack_push(pLStack *stack, int number);
// возвращает элемент с вершины стека
int LStack_pop(pLStack *stack);
// возвращает 1, если стек пустой, иначе - 0
int LStack_empty(pLStack stack);
// возвращает 1, если стек полон, иначе - 0
int LStack_full(pLStack stack);
// возвращает количество элементов в стеке
int LStack_count(pLStack stack);


// структура для хранения очереди целочисленных значений на базе двусвязных кольцевых списков
typedef struct LQueue *pLQueue;
typedef struct LQueue {
    int data;
    pLQueue pprev, pnext;
} LQueue;

// создает очередь
pLQueue LQueue_create(int data);
// уничтожает очередь
void LQueue_destroy(pLQueue que);
// помещает элемент в конец очереди
void LQueue_put(pLQueue que, int number);
// возвращает элемент из начала очереди
int LQueue_get(pLQueue *que);
// возвращает 1, если очередь пустая, иначе - 0
int LQueue_empty(pLQueue que);
// возвращает 1, если очередь полностью заполнена, иначе - 0
int LQueue_full(pLQueue que);
// возвращает количество элементов в очереди
int LQueue_count(pLQueue que);


#endif // SQUNITL
