#include <stdio.h>
#include <locale.h>

int lab2(short int x, char y, char z) {
  printf("x = %x, z = %x, y = %x\n", x, z, y);

  short vC, vA;
  // Блок определения переменных
  // Блок вычислений функций на C
  vC = (4*z + y*(x - 3)) / (2*y + 5) + 2;
  printf("Result in C in decimal and hexadecimal number systems: v = %d, %x \n", vC, vC);
  
  // Блок вычисления функции на ассемблере
  __asm {
  //числитель
  mov ax, x; // ax = x
  sub ax, 3; // ax = x - 3
  mov bx, ax; // bx = x - 3
  mov al, y; // al = y
  cbw; // //Перевести y в WORD
  imul bx; // bx = (x - 3) * y
  mov bx, ax; //Поместить ax в bx
  mov cx, dx; // cx = dx
  mov al, z; // al = z
  cbw; // Перевести z в WORD
  imul ax, 4; // 4z
  cwd; // Перевести ax в WORD
  add bx, ax; // bx = 4z + (x - 3) * y
  adc cx, dx; //сложение со смещением 
  
  //знаменатель
  mov al, y; //Поместить y в AL
  cbw; //Перевести y в WORD
  imul ax, 2; //Перемножить y на 2
  add ax, 5; //Прибавить 5
  xchg ax, bx; //Поменять местами
  mov dx, cx; //Поместить cx в DX
  idiv bx; //Деление с остатком
  add ax, 2; //Прибавить 2
  mov vA, ax; //Поместить результат в vA
  }

  printf("Result in ASM in decimal and hexadecimal number systems: v = %d, %x\n", vA, vA);

}

int main() {
  printf("Lab A2\nVar 27\n\nTest 1\n");
  lab2(0x7, -0x2, -0x1);
  printf("Expected result: v = %d, %x\n", -0xA, -0xA);
  printf("\nTest 2\n");
  lab2(0x3AF, -0x71, 0x5E);
  printf("Expected result: v = %d, %x\n", 0x1E0, 0x1E0);
  getchar();
  return 0;
}
