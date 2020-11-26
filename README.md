# 42cursus-get-next-line

**Прототип:**
int get_next_line(int fd, char **line);

**Файлы:**
get_next_line.c,
get_next_line_utils.c,
get_next_line.h

**Параметры:**
#1. Дескриптор файла для чтения
#2. ЖЗначение того, что было прочитано

**Возвращаемые значения:**
1: Строка прочитана,
0: EOF достигнута,
-1: Произошла ошибка

**Разрешенные функции:**
read, malloc, free

**Описание:**
Возвращает строку, считанную с дескриптор файла, без новой строки.

- Вызов вашей функции get_next_line в цикле позволит вам читать текст, доступный в файловом дескрипторе по одной строке за раз до EOF.
- Убедитесь, что ваша функция ведет себя хорошо, когда читает из файла и когда читает со стандартного входа.
- libft для этого проекта не разрешен. Вы должны добавить файл get_next_line_utils.c, который будет содержать функции, необходимые для работы вашей строки get_next_line.
- Ваша программа должна скомпилироваться с флагом -D BUFFER_SIZE=xx. который будет использоваться в качестве размера буфера для вызовов чтения в вашей строке get_next_line. Это значение будет изменено вашими вычислителями и мулинетом.
- Компиляция будет производиться следующим образом : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
- Для чтения из файла или из stdin необходимо использовать BUFFER_SIZE, определенный при компиляции.
- В заголовочном файле get_next_line.h должен быть как минимум прототип функции get_next_line.
- Мы считаем, что get_next_line имеет неопределенное поведение, если между двумя вызовами один и тот же файловый дескриптор переключается на другой файл до достижения EOF на первом fd.
- lseek не является разрешенной функцией. Чтение файла должно быть выполнено только один раз.
- Наконец, мы считаем, что get_next_line имеет неопределенное поведение при чтении из двоичного файла. Однако, при желании, вы можете сделать это поведение последовательным.
- Глобальные переменные запрещены.

**Ваша функция все еще работает, если значение BUFFER_SIZE равно 9999?  А если значение BUFFER_SIZE равно 1?  И 10000000?  Знаете почему?**

**При каждом вызове get_next_line следует стараться читать как можно меньше.  Если вы столкнулись с новой строкой, вы должны вернуть текущую строку.  Не читайте весь файл, а затем обработайте каждую строку.**

**Не сдавай свой проект без тестирования.  Есть много тестов, которые нужно провести, прикрыть свои базы.  Попробуйте прочитать из файла, из переадресации, со стандартного входа.  Как ведет себя ваша программа, когда вы посылаете новую строку на стандартный выход?  А CTRL-D?**
